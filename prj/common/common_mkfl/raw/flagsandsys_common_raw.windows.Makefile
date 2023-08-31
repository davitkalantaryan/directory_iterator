#
# repo:		simple_cpp_bcrypt
# file:		flagsandsys_common_raw.windows.Makefile
# created on:	2023 Aug 14
# created by:	Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	This file can be only as include
#

!IFNDEF MakeFileDir
MakeFileDir			= $(MAKEDIR)\..
!ENDIF

!IFNDEF simpleCppBcryptRepositoryRoot
simpleCppBcryptRepositoryRoot	= $(MakeFileDir)\..\..\..
!ENDIF

!IFNDEF artifactRoot
artifactRoot	= $(simpleCppBcryptRepositoryRoot)
!ENDIF

!IFNDEF cinternalRepoRoot
cinternalRepoRoot	= $(simpleCppBcryptRepositoryRoot)\contrib\cinternal
!ENDIF

!include <$(cinternalRepoRoot)\prj\common\common_mkfl\flagsandsys_common.windows.Makefile>
CFLAGS				= $(CFLAGS) /I"$(simpleCppBcryptRepositoryRoot)\include"
