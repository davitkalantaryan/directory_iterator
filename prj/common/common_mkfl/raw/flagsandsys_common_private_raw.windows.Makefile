#
# repo:		    simple_cpp_bcrypt
# file:		    flagsandsys_common_private_pure.windows.Makefile
# created on:	    2023 Aug 14
# created by:	    Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	    This file can be only as include
#

!IFNDEF simpleCppBcryptRepositoryRoot
simpleCppBcryptRepositoryRoot	= $(MAKEDIR)\..\..\..\..
!ENDIF
!include <$(simpleCppBcryptRepositoryRoot)\prj\common\common_mkfl\flagsandsys_common.windows.Makefile>

CFLAGS				= $(CFLAGS) /I"$(simpleCppBcryptRepositoryRoot)\src\include"
