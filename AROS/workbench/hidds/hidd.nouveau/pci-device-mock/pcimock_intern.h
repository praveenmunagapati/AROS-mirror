#ifndef PCIMOCK_INTERN_H
#define PCIMOCK_INTERN_H

#include <exec/types.h>
#include <exec/libraries.h>
#include <oop/oop.h>

#include LC_LIBDEFS_FILE

struct BarSpace
{
    APTR    BarAddr[6];
    ULONG   BarSize[6];
};


struct staticdata
{
    OOP_Class       *driverClass;
    OOP_AttrBase    hiddPCIDriverAB;
    OOP_AttrBase    hiddAB;
    struct BarSpace tmp;
};

LIBBASETYPE
{
    struct Library      Base;
    struct staticdata   sd;
};

#define METHOD(base, id, name) \
  base ## __ ## id ## __ ## name (OOP_Class *cl, OOP_Object *o, struct p ## id ## _ ## name *msg)

#define BASE(lib)                   ((LIBBASETYPEPTR)(lib))

#define SD(cl)                      (&BASE(cl->UserData)->sd)

#endif /* PCIMOCK_INTERN_H */

