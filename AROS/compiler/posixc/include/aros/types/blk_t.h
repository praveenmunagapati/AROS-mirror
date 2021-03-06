#ifndef _AROS_TYPES_BLK_T_H
#define _AROS_TYPES_BLK_T_H

/*
    Copyright � 2010-2011, The AROS Development Team. All rights reserved.
    $Id$

    blkcnt_t and blksize_t
*/

#include <aros/cpu.h>

/* FIXME: Is 32bit blkcnt_t and blksize_t future proof enough? */
typedef	signed AROS_32BIT_TYPE      blkcnt_t;	/* File block count         */
typedef signed AROS_32BIT_TYPE      blksize_t;	/* File block size          */

#endif /* _AROS_TYPES_BLK_T_H */
