#
# repo:		directory_iterator
# file:		flagsandsys_common_raw.windows.Makefile
# created on:	2023 Aug 14
# created by:	Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	This file can be only as include
#

!IFNDEF MakeFileDir
MakeFileDir			= $(MAKEDIR)\..
!ENDIF

!IFNDEF directoryIteratorRepoRoot
directoryIteratorRepoRoot	= $(MakeFileDir)\..\..\..
!ENDIF

!IFNDEF artifactRoot
artifactRoot	= $(directoryIteratorRepoRoot)
!ENDIF

!IFNDEF cinternalRepoRoot
cinternalRepoRoot	= $(directoryIteratorRepoRoot)\contrib\cinternal
!ENDIF

!include <$(cinternalRepoRoot)\prj\common\common_mkfl\flagsandsys_common.windows.Makefile>

CFLAGS				= $(CFLAGS) /I"$(directoryIteratorRepoRoot)\include"

LFLAGS				= $(LFLAGS) /LIBPATH:"$(directoryIteratorRepoRoot)\sys\win_$(Platform)\$(Configuration)\lib"
LFLAGS				= $(LFLAGS) /LIBPATH:"$(directoryIteratorRepoRoot)\sys\win_$(Platform)\$(Configuration)\tlib"
