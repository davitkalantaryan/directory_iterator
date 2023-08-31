#
# repo:		    simple_cpp_bcrypt
# file:		    flagsandsys_common_raw.unix.Makefile
# created on:	    2023 Aug 14
# created by:	    Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	    This file can be only as include
#

ifndef simpleCppBcryptRepositoryRoot
        mkfile_path		=  $(abspath $(lastword $(MAKEFILE_LIST)))
        mkfile_dir		=  $(shell dirname $(mkfile_path))
        simpleCppBcryptRepositoryRoot	:= $(shell curDir=`pwd` && cd $(mkfile_dir)/../../../.. && pwd && cd ${curDir})
endif

ifndef artifactRoot
        artifactRoot	= $(simpleCppBcryptRepositoryRoot)
endif

include $(simpleCppBcryptRepositoryRoot)/contrib/cinternal/prj/common/common_mkfl/flagsandsys_common.unix.Makefile

COMMON_FLAGS	+= -I$(simpleCppBcryptRepositoryRoot)/include
