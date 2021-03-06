# $Date: 2011-06-26 09:31:03 +0200 (So, 26. Jun 2011) $
# $Revision: 744 $
##############################################################################

ifndef $(TOPLEVEL)
	TOPLEVEL=$(shell pwd)/../../../..
endif

###############################################################################

include $(TOPLEVEL)/config.mk
include $(TOPLEVEL)/rules.mk

###############################################################################
# Check compiler

ifeq ($(MACHINE), ppc-morphos)

###############################################################################
# MorphOS

LANG	=       polski


else
ifeq ($(MACHINE), ppc-amigaos)

###############################################################################
# AmigOS4

LANG	=       polish

else

###############################################################################
# AmigaOS (and AROS)

LANG	=       polski

endif
endif
