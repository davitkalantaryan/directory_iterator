#
# repo:		    directory_iterator
# file:		    flagsandsys_common_private_raw.windows.Makefile
# created on:	    2023 Aug 14
# created by:	    Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	    This file can be only as include
#

!IFNDEF directoryIteratorRepoRoot
directoryIteratorRepoRoot	= $(MAKEDIR)\..\..\..\..
!ENDIF
!include <$(directoryIteratorRepoRoot)\prj\common\common_mkfl\flagsandsys_common.windows.Makefile>

CFLAGS				= $(CFLAGS) /I"$(directoryIteratorRepoRoot)\src\include"
