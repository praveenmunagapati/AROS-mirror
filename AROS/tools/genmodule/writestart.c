/*
    Copyright � 1995-2002, The AROS Development Team. All rights reserved.

    Desc: function to write modulename_start.c. Part of genmodule.
*/
#include "genmodule.h"

void writestart(void)
{
    FILE *out;
    struct functionlist *funclistit;
    struct arglist *arglistit;
    unsigned int lvo;
    
    snprintf(line, slen-1, "%s/%s_start.c", gendir, modulename);
    out = fopen(line, "w");
    if (out==NULL)
    {
	fprintf(stderr, "Could not write %s\n", line);
	exit(20);
    }
    fprintf(out,
	    "/*\n"
	    "    *** Automatically generated file. Do not edit ***\n"
	    "    Copyright � 1995-2002, The AROS Development Team. All rights reserved.\n"
	    "*/\n"
	    "#include <libcore/libheader.c>\n"
	    "\n");
    if (libcall==REGISTER)
    {
	fprintf(out,
		"#define NOLIBDEFINES\n"
		"#include <proto/%s.h>\n"
		"\n",
		modulename);
    }
    
    for (funclistit = funclist, lvo=firstlvo;
	 funclistit != NULL;
	 funclistit = funclistit->next, lvo++)
    {
	switch (libcall)
	{
	case STACK:
	    fprintf(out, "int %s();\n", funclistit->name);
	    break;
	    
	case REGISTER:
	    fprintf(out, "%s %s(", funclistit->type, funclistit->name);
	    for (arglistit = funclistit->arguments;
		 arglistit!=NULL;
		 arglistit = arglistit->next)
	    {
		if (arglistit!=funclistit->arguments)
		    fprintf(out, ", ");
		fprintf(out, "%s %s", arglistit->type, arglistit->name);
	    }
	    fprintf(out, ");\nAROS_LH%d(%s, %s,\n",
		    funclistit->argcount, funclistit->type, funclistit->name);
	    for (arglistit = funclistit->arguments;
		 arglistit!=NULL;
		 arglistit = arglistit->next)
	    {
		fprintf(out, "         AROS_LHA(%s, %s, %s),\n",
			arglistit->type, arglistit->name, arglistit->reg);
	    }
	    fprintf(out,
		    "         %s *, %s, %u, %s)\n"
		    "{\n"
		    "    return %s(",
		    libbasetypeextern, libbase, lvo, basename, funclistit->name);
	    for (arglistit = funclistit->arguments;
		 arglistit!=NULL;
		 arglistit = arglistit->next)
	    {
		if (arglistit!=funclistit->arguments)
		    fprintf(out, ", ");
		fprintf(out, "%s", arglistit->name);
	    }
	    fprintf(out, ");\n}\n\n");
	    break;
	    
	default:
	    fprintf(stderr, "Internal error: unhandled libcall in writestart\n");
	    exit(20);
	    break;
	}
    }
    
    fprintf(out,
	    "\n"
	    "const APTR %s_functable[]=\n"
	    "{\n"
	    "    &AROS_SLIB_ENTRY(LC_BUILDNAME(OpenLib),LibHeader),\n"
	    "    &AROS_SLIB_ENTRY(LC_BUILDNAME(CloseLib),LibHeader),\n"
	    "    &AROS_SLIB_ENTRY(LC_BUILDNAME(ExpungeLib),LibHeader),\n"
	    "    &AROS_SLIB_ENTRY(LC_BUILDNAME(ExtFuncLib),LibHeader),\n",
	    modulename);

    for (funclistit = funclist;
	 funclistit != NULL;
	 funclistit = funclistit->next)
    {
	switch (libcall)
	{
	case STACK:
	    fprintf(out, "    &%s,\n", funclistit->name);
	    break;
	    
	case REGISTER:
	    fprintf(out, "    &AROS_SLIB_ENTRY(%s,%s),\n", funclistit->name, basename);
	    break;
	    
	default:
	    fprintf(stderr, "Internal error: unhandled libcall type in writestart\n");
	    exit(20);
	    break;
	}
    }

    fprintf(out, "    (void *)-1\n};\n");
    fclose(out);
}
