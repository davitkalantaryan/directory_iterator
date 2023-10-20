#
# repo:		directory_iterator
# file:		flagsandsys_common.windows.Makefile
# created on:	2020 Dec 14
# created by:	Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	This file can be only as include
#

!IFNDEF dirIterFlagsAndSysCommonIncluded
dirIterFlagsAndSysCommonIncluded		= 1
!IFNDEF directoryIteratorRepoRoot
directoryIteratorRepoRoot	= $(MAKEDIR)\..\..\..
!ENDIF
!include <$(directoryIteratorRepoRoot)\prj\common\common_mkfl\raw\flagsandsys_common_raw.windows.Makefile>
!ENDIF
