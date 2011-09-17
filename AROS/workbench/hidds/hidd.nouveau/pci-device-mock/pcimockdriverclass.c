/*
    Copyright 2011, The AROS Development Team. All rights reserved.
    $Id$
*/

#include <aros/debug.h>
#include <proto/oop.h>

#include <aros/symbolsets.h>

#include "pcimock_intern.h"

#include "pci_registers.h" /* From hidd.pci */

#undef HiddPCIDriverAttrBase
#define HiddPCIDriverAttrBase   (SD(cl)->hiddPCIDriverAB)

#undef HiddAttrBase
#define HiddAttrBase            (SD(cl)->hiddAB)

#undef HiddPCIMockHardwareAttrBase
#define HiddPCIMockHardwareAttrBase (SD(cl)->hiddPCIMockHardwareAB)

OOP_Object * METHOD(PCIMock, Root, New)
{
    struct pRoot_New mymsg;

    struct TagItem mytags[] = 
    {
        { aHidd_Name, (IPTR)"PCIMock" },
        { aHidd_HardwareName, (IPTR)"Mock PCI Driver" },
        { TAG_DONE, 0 }
    };

    mymsg.mID = msg->mID;
    mymsg.attrList = (struct TagItem *)&mytags;

    if (msg->attrList)
    {
        mytags[3].ti_Tag = TAG_MORE;
        mytags[3].ti_Data = (IPTR)msg->attrList;
    }

    msg = &mymsg;

    o = (OOP_Object *)OOP_DoSuperMethod(cl, o, (OOP_Msg)msg);

    return o;
}

ULONG METHOD(PCIMock, Hidd_PCIDriver, ReadConfigLong)
{
    IPTR pciconfigspace;
    ULONG * ptr;
    
    if (!((msg->bus == 0) && (msg->dev == 2) && (msg->sub == 0)))
        return 0;

    OOP_GetAttr(SD(cl)->mockHardware, aHidd_PCIMockHardware_ConfigSpaceAddr, &pciconfigspace);
    
    ptr = (ULONG *)pciconfigspace;

    switch (msg->reg)
    {
        /* PCICS_PRODUCT */
        case(PCICS_VENDOR)      :
        /* PCICS_STATUS */
        case(PCICS_COMMAND)     :
        /* PCICS_PROGIF */
        /* PCICS_SUBCLASS */
        /* PCICS_CLASS */
        case(PCICS_REVISION)    :
        case(PCICS_CACHELS)     :
        /* PCICS_SUBSYSTEM */
        case(PCICS_SUBVENDOR)   :
        /* CICS_INT_PIN */
        case(PCICS_INT_LINE)    :
        case(PCICS_BAR0)        :
        case(PCICS_BAR1)        :
        case(PCICS_BAR2)        :
        case(PCICS_BAR3)        :
        case(PCICS_BAR4)        :
        case(PCICS_BAR5)        :
        case(PCICS_EXPROM_BASE) :
            return ptr[msg->reg];


        default: bug("READ: 0x%x\n", msg->reg);
    }

    return 0;
}

VOID METHOD(PCIMock, Hidd_PCIDriver, WriteConfigLong)
{
    IPTR pciconfigspace;
    ULONG * ptr;

    if (!((msg->bus == 0) && (msg->dev == 2) && (msg->sub == 0)))
        return;

    OOP_GetAttr(SD(cl)->mockHardware, aHidd_PCIMockHardware_ConfigSpaceAddr, &pciconfigspace);
    
    ptr = (ULONG *)pciconfigspace;
    ptr[msg->reg] = msg->val;
    
    /* Inform mock device that value in its address space region has changed */
    {
        struct pHidd_PCIMockHardware_MemoryChangedAtAddress mcaa =
        {
            mID : OOP_GetMethodID(IID_Hidd_PCIMockHardware, moHidd_PCIMockHardware_MemoryChangedAtAddress),
            memoryaddress : pciconfigspace + msg->reg
        };
        
        OOP_DoMethod(SD(cl)->mockHardware, (OOP_Msg)&mcaa);
    }
}

static int PCIMock_ExpungeClass(LIBBASETYPEPTR LIBBASE)
{
    D(bug("[PCIMock] deleting classes\n"));

    OOP_ReleaseAttrBase(IID_Hidd_PCIDriver);
    OOP_ReleaseAttrBase(IID_Hidd);
    OOP_ReleaseAttrBase(IID_Hidd_PCIMockHardware);
    
    /* TODO: delete all allocated mock hardware devices */

    return TRUE;
}

static int PCIMock_InitClass(LIBBASETYPEPTR LIBBASE)
{
    OOP_Object *pci = NULL;

    D(bug("[PCIMock] Driver initialization\n"));

    LIBBASE->sd.hiddPCIDriverAB = OOP_ObtainAttrBase(IID_Hidd_PCIDriver);
    LIBBASE->sd.hiddAB = OOP_ObtainAttrBase(IID_Hidd);
    LIBBASE->sd.hiddPCIMockHardwareAB = OOP_ObtainAttrBase(IID_Hidd_PCIMockHardware);
    
    LIBBASE->sd.mockHardware = OOP_NewObject(NULL, CLID_Hidd_PCIMockHardware_NV44A, NULL);

    if (LIBBASE->sd.hiddPCIDriverAB)
    {
        /*
        * The class may be added to the system. Add the driver
        * to PCI subsystem as well
        */
        struct pHidd_PCI_AddHardwareDriver msg;

        /*
        * PCI is suppose to destroy the class on its Dispose
        */
        msg.driverClass = LIBBASE->sd.driverClass;
        msg.mID = OOP_GetMethodID(IID_Hidd_PCI, moHidd_PCI_AddHardwareDriver);

        pci = OOP_NewObject(NULL, CLID_Hidd_PCI, NULL);
        OOP_DoMethod(pci, (OOP_Msg)&msg);
        OOP_DisposeObject(pci);
    }
    else
        return FALSE;

    D(bug("[PCIMock] Driver ClassPtr = %x\n", psd->driverClass));

    return TRUE;
}

ADD2INITLIB(PCIMock_InitClass, 0)
ADD2EXPUNGELIB(PCIMock_ExpungeClass, 0)
