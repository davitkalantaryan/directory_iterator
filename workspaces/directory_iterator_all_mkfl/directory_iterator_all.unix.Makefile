

targetName=directory_iterator_all

mkfile_path		=  $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir		=  $(shell dirname $(mkfile_path))

ifndef directoryIteratorRepoRoot
        directoryIteratorRepoRoot	:= $(shell curDir=`pwd` && cd $(mkfile_dir)/../.. && pwd && cd ${curDir})
endif


all:
	$(MAKE) -f $(directoryIteratorRepoRoot)/prj/tests/diriter_unit_test_mult/diriter_unit_test.unix.Makefile			&& \
	$(MAKE) -f $(directoryIteratorRepoRoot)/prj/tests/any_quick_test_mkfl/any_quick_test.unix.Makefile

.PHONY: clean
clean:
	$(MAKE) -f $(directoryIteratorRepoRoot)/prj/tests/diriter_unit_test_mult/diriter_unit_test.unix.Makefile clean
	$(MAKE) -f $(directoryIteratorRepoRoot)/prj/tests/any_quick_test_mkfl/any_quick_test.unix.Makefile clean
	
