/*
    Copyright � 1995-2011, The AROS Development Team. All rights reserved.
    $Id$

    Desc: autoinit library - arosc.library specific code
    Lang: english
*/
#include <proto/arosc.h>

#include <aros/symbolsets.h>
#include <aros/startup.h>

#define DEBUG 0
#include <aros/debug.h>

void __arosc_program_startup(void);
void __arosc_program_end(void);

/* aroscbase is defined by the C prototypes.
 * We need to set it as the default LIBBASE
 * here so that our routines case use it.
 */
static void __arosc_startup(void)
{
    APTR oldLibBase;
    D(bug("[__arosc_startup] Start\n"));

    oldLibBase = AROS_SET_LIBBASE(aroscbase);

    __arosc_program_startup();

    struct arosc_userdata *udata = __get_arosc_userdata();

    udata->acud_startup_error = __startup_error;

    if (setjmp(udata->acud_startup_jmp_buf) == 0)
    {
        D(bug("[__arosc_startup] setjmp() called\n"));
        __startup_entries_next();
    }
    else
    {
        D(bug("[__arosc_startup] setjmp() return from longjmp\n"));
        __startup_error = udata->acud_startup_error;
    }

    __arosc_program_end();
    AROS_SET_LIBBASE(oldLibBase);

    D(bug("[__arosc_startup] Leave\n"));
}

ADD2SET(__arosc_startup, program_entries, 0);
