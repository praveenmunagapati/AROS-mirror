/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id$

    Desc: Camd initialization code.
    Lang: English
*/

#include <exec/types.h>
#include <exec/libraries.h>

#include <aros/symbolsets.h>

#include <proto/exec.h>
#include <proto/utility.h>
#include <proto/dos.h>

#include "security_intern.h"
#include LC_LIBDEFS_FILE

#define DEBUG 1
#include <aros/debug.h>

/****************************************************************************************/

AROS_SET_LIBFUNC(Init, LIBBASETYPE, LIBBASE)
{
    AROS_SET_LIBFUNC_INIT;
    
    D(bug("Inside Init func of security.library\n"));

    return TRUE;
    
    AROS_SET_LIBFUNC_EXIT;
}

/****************************************************************************************/

AROS_SET_LIBFUNC(Expunge, LIBBASETYPE, LIBBASE)
{
    AROS_SET_LIBFUNC_INIT;
    
    return TRUE;
    
    AROS_SET_LIBFUNC_EXIT;
}

ADD2INITLIB(Init, 0);
ADD2EXPUNGELIB(Expunge, 0);
