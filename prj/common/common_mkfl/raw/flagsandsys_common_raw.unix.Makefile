#
# repo:		    directory_iterator
# file:		    flagsandsys_common_raw.unix.Makefile
# created on:	    2023 Aug 14
# created by:	    Davit Kalantaryan (davit.kalantaryan@desy.de)
# purpose:	    This file can be only as include
#

ifndef directoryIteratorRepoRoot
        mkfile_path		=  $(abspath $(lastword $(MAKEFILE_LIST)))
        mkfile_dir		=  $(shell dirname $(mkfile_path))
        directoryIteratorRepoRoot	:= $(shell curDir=`pwd` && cd $(mkfile_dir)/../../../.. && pwd && cd ${curDir})
endif

ifndef artifactRoot
        artifactRoot	= $(directoryIteratorRepoRoot)
endif

include $(directoryIteratorRepoRoot)/contrib/cinternal/prj/common/common_mkfl/flagsandsys_common.unix.Makefile

COMMON_FLAGS	+= -I$(directoryIteratorRepoRoot)/include

LIBS	+= -L$(directoryIteratorRepoRoot)/sys/$(lsbCode)/$(Configuration)/lib
LIBS	+= -L$(directoryIteratorRepoRoot)/sys/$(lsbCode)/$(Configuration)/tlib
