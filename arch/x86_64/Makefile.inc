# -*- makefile -*-
#
# arch/x86_64/Makefile.inc
#
# Special rules for this architecture.  Note that this is actually
# included from the main Makefile, and that pathnames should be
# accordingly.
#

ARCHOBJS = \
	arch/$(ARCH)/exits.o

ARCHSOOBJS = $(patsubst %.o,%.lo,$(ARCHOBJS))

archclean: