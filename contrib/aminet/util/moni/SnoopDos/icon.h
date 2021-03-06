/*
 *		ICON.H											vi:ts=4
 *
 *      Copyright (c) Eddy Carroll, September 1994.
 *
 *		Header file containing icon data ... kept in a separate file to make
 *		it easier to update (this is taken straight from IconEdit's SAVE AS C
 *		output -- to access this, set SRC=YES in the IconEdit tooltypes).
 */

/*
 *		We define some standard names here to make life easier and to
 *		save lots of editing of the IconEdit-produced code.
 */
#define DefSnoopDosIcon		SnoopDos_Project
#define DefToolTypes		SnoopDos_ProjectTools

/*
 *		Next, some stuff that IconEdit gets wrong (1.3 vs 2.0 includes)
 */
#ifndef GADGIMAGE
#define GADGIMAGE			GFLG_GADGIMAGE
#define GADGHCOMP			GFLG_GADGHCOMP
#define GADGIMMEDIATE		GACT_IMMEDIATE
#define RELVERIFY			GACT_RELVERIFY
#define BOOLGADGET			GTYP_BOOLGADGET

#endif

/*
 *		Now over to IconEdit...
 */
static UWORD SECTION_CHIP SnoopDos_ProjectI1Data[] =
{
/* Plane 0 */
    0x0000,0x0000,0x0000,0x0400,0x0000,0x0003,0xF000,0x0C00,
    0x0000,0x000F,0xFC00,0x0C00,0x0000,0x003E,0x1F00,0x0C00,
    0x0000,0x0078,0x1F80,0x0C00,0x001F,0x8070,0x7FC0,0x0C00,
    0x0018,0xE1F8,0xF1F0,0x0C00,0x0018,0x61F8,0xE0F0,0x0C00,
    0x0018,0x33FC,0xF0E0,0x0C00,0x0018,0x339C,0x7E60,0x0C00,
    0x0018,0x339C,0x1FE0,0x0C00,0x0018,0x339C,0x03F0,0x0C00,
    0x0018,0x339C,0x00F0,0x0C00,0x0018,0x61FC,0x00F0,0x0C00,
    0x0018,0xE1F8,0xE0F0,0x0C00,0x001F,0x83F8,0xF1C0,0x0C00,
    0x0000,0x7FF0,0x7F80,0x0C00,0x0007,0xFFF8,0x3F80,0x0C00,
    0x007F,0xFC3E,0x1F00,0x0C00,0x07FF,0x800F,0xFC00,0x0C00,
    0x07F8,0x0003,0xF000,0x0C00,0x7FFF,0xFFFF,0xFFFF,0xFC00,
/* Plane 1 */
    0xFFFF,0xFFFF,0xFFFF,0xF800,0xD555,0x5557,0xF555,0x5000,
    0xD555,0x555F,0xFD55,0x5000,0xD555,0x557F,0x5F55,0x5000,
    0xD555,0x557D,0x47D5,0x5000,0xD540,0x5565,0x0195,0x5000,
    0xD545,0x14E5,0x05C5,0x5000,0xD545,0x14C5,0x15C5,0x5000,
    0xD545,0x45C1,0x05F5,0x5000,0xD545,0x45C1,0x0175,0x5000,
    0xD545,0x45C1,0x4075,0x5000,0xD545,0x45C1,0x5465,0x5000,
    0xD545,0x45C1,0x5565,0x5000,0xD545,0x15C1,0x55E5,0x5000,
    0xD545,0x14C5,0x15C5,0x5000,0xD540,0x57E5,0x05D5,0x5000,
    0xD555,0x7FE5,0x01D5,0x5000,0xD557,0xFFFD,0x47D5,0x5000,
    0xD57F,0xFD7F,0x5F55,0x5000,0xD7FF,0xD55F,0xFD55,0x5000,
    0xD7FD,0x5557,0xF555,0x5000,0x8000,0x0000,0x0000,0x0000,
};

static struct Image SnoopDos_ProjectI1 =
{
    0, 0,			/* Upper left corner */
    54, 22, 2,			/* Width, Height, Depth */
    SnoopDos_ProjectI1Data,		/* Image data */
    0x0003, 0x0000,		/* PlanePick, PlaneOnOff */
    NULL			/* Next image */
};

static STRPTR SnoopDos_ProjectTools[] =
{
    (STRPTR)"AUTHOR=Eddy Carroll",
    (STRPTR)NULL
};

struct DiskObject SnoopDos_Project =
{
    WB_DISKMAGIC,		/* Magic Number */
    WB_DISKVERSION,		/* Version */
    {				/* Embedded Gadget Structure */
	NULL,			/* Next Gadget Pointer */
	0, 0, 54, 23,		/* Left,Top,Width,Height */
	GADGIMAGE | GADGHCOMP,	/* Flags */
	RELVERIFY | GADGIMMEDIATE,		/* Activation Flags */
	BOOLGADGET,		/* Gadget Type */
	(APTR)&SnoopDos_ProjectI1,	/* Render Image */
	NULL,			/* Select Image */
	NULL,			/* Gadget Text */
	0,				/* Mutual Exclude */
	NULL,			/* Special Info */
	0,			/* Gadget ID */
	(APTR) 0x0001,		/* User Data (Revision) */
    },
    WBPROJECT,			/* Icon Type */
    NULL,			/* Default Tool */
    SnoopDos_ProjectTools,			/* Tool Type Array */
    NO_ICON_POSITION,		/* Current X */
    NO_ICON_POSITION,		/* Current Y */
    NULL,			/* Drawer Structure */
    NULL,			/* Tool Window */
    12288				/* Stack Size */
};
