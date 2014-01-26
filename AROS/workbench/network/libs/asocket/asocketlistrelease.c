/*
    Copyright � 2014, The AROS Development Team. All rights reserved.
    $Id$
*/

/*****************************************************************************

    NAME */

        #include <protos/asocket.h>

        AROS_LH1(VOID, ASocketListRelease,

/*  SYNOPSIS */
        AROS_LHA(struct List *, aslist, A0),

/*  LOCATION */
        struct Library *, ASocketBase, 9, ASocket)

/*  FUNCTION

    INPUTS

        aslist - An ASocketList from ASocketListObtain()

    RESULT

        None

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

        ASocketListObtain()

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    AROS_FUNCTION_NOT_IMPLEMENTED(asocket);

    AROS_LIBFUNC_EXIT
}
