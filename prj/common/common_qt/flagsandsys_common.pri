#
# repo:			simple_cpp_bcrypt
# name:			flagsandsys_common.pri
# path:			prj/common/common_qt/flagsandsys_common.pri
# created on:   2023 Jun 21
# created by:   Davit Kalantaryan (davit.kalantaryan@desy.de)
# usage:		Use this qt include file to calculate some platform specific stuff
#


message("!!! $${PWD}/flagsandsys_common.pri")

isEmpty(dirIterFlagsAndSysCommonIncluded){
    dirIterFlagsAndSysCommonIncluded = 1

    directoryIteratorRepoRoot = $${PWD}/../../..
        include("$${directoryIteratorRepoRoot}/contrib/cinternal/prj/common/common_qt/flagsandsys_common.pri")

    isEmpty(artifactRoot) {
        artifactRoot = $$(artifactRoot)
		isEmpty(artifactRoot) {
		        artifactRoot = $${directoryIteratorRepoRoot}
		}
    }

    INCLUDEPATH += $${directoryIteratorRepoRoot}/include

        LIBS	+= -L$${directoryIteratorRepoRoot}/sys/$${CODENAME}/$$CONFIGURATION/lib
	LIBS	+= -L$${directoryIteratorRepoRoot}/sys/$${CODENAME}/$$CONFIGURATION/tlib

        OTHER_FILES += $$files($${PWD}/../common_mkfl/*.Makefile,true)
}
