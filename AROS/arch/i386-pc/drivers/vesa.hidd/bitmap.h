/*
    Copyright � 1995-2010, The AROS Development Team. All rights reserved.
    $Id$
*/

#ifndef _BITMAP_H
#define _BITMAP_H

#include <hidd/graphics.h>

#define IID_Hidd_VesaGfxBitMap "hidd.bitmap.vesabitmap"

#define HiddVesaGfxBitMapAttrBase __abHidd_VesaGfxBitMap

/* extern OOP_AttrBase HiddVesaGfxBitMapAttrBase; */

enum
{
    aoHidd_VesaGfxBitMap_Drawable,
    num_Hidd_VesaGfxBitMap_Attrs
};

#define aHidd_VesaGfxBitMap_Drawable	(HiddVesaGfxBitMapAttrBase + aoHidd_VesaGfxBitMap_Drawable)

#define IS_BM_ATTR(attr, idx) ( ( (idx) = (attr) - HiddBitMapAttrBase) < num_Hidd_BitMap_Attrs)
#define IS_VesaGfxBM_ATTR(attr, idx) ( ( (idx) = (attr) - HiddVesaGfxBitMapAttrBase) < num_Hidd_VesaGfxBitMap_Attrs)

/*
   This structure is used as instance data for the bitmap class.
*/
struct BitmapData
{
    UBYTE   	    	*VideoData;	/* Pointing to video data */
    ULONG   	    	width;      	/* Width of bitmap */
    ULONG   	    	height;		/* Height of bitmap */
    UBYTE   	    	bytesperpix;
    ULONG   	    	bytesperline;
    UBYTE *   	    	DAC;   		/* Hardware palette registers */
    BYTE    	    	bpp;         	/* Cached bits per pixel */
    BYTE    	    	disp;        	/* !=0 - displayable */
    OOP_Object	    	*pixfmtobj;	/* Cached pixelformat object */
    OOP_Object	    	*gfxhidd;	/* Cached driver object */
    ULONG		disp_width;	/* Display size */
    ULONG		disp_height;
};

#endif /* _BITMAP_H */
