/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$

    Desc: Internal information for aros.library.
    Lang:
*/
#ifndef _AROS_INTERN_H_
#define _AROS_INTERN_H_

#include <exec/types.h>
#include <exec/libraries.h>
#include <dos/dos.h>

#include "libdefs.h"

/*
    This is the ArosBase structure. It is documented here because it is
    completely private. Applications should treat it as a struct Library, and
    use the aros.library functions to get information.
*/

struct LIBBASETYPE
{
    struct Library       aros_LibNode;

    /* The following information is private! */

    struct ExecBase *    aros_sysBase;
    struct Library *     aros_utilityBase;
    BPTR                 aros_segList;

};

/* digulla again... Needed for close() */
#define expunge() \
 AROS_LC0(BPTR, expunge, struct ArosBase *, ArosBase, 3, Aros)

#define SysBase         LIBBASE->aros_sysBase
#define UtilityBase	LIBBASE->aros_utilityBase

#endif /* _AROS_INTERN_H */
