#
# repo:			directory_iterator
# file:			sys_common.pri
# path:			prj/common/common_qt/sys_common.pri    
# created on:		2023 Jan 10
# Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
#

message ("$${PWD}/resolve_common.pri")
directoryIteratorResolveCommonIncluded = 1

isEmpty( directoryIteratorRepoRoot ) {
        directoryIteratorRepoRoot = $$(directoryIteratorRepoRoot)
	isEmpty(directoryIteratorRepoRoot) {
	    directoryIteratorRepoRoot = $${PWD}/../../..
        }
}

isEmpty( repositoryRoot ) {
        repositoryRoot = $$(repositoryRoot)
        isEmpty(repositoryRoot) {
	    repositoryRoot = $${directoryIteratorRepoRoot}
        }
}

isEmpty(artifactRoot) {
    artifactRoot = $$(artifactRoot)
    isEmpty(artifactRoot) {
        artifactRoot = $${repositoryRoot}
    }
}

isEmpty( cinternalRepoRoot ) {
        cinternalRepoRoot = $$(cinternalRepoRoot)
        isEmpty(cinternalRepoRoot) {
	    cinternalRepoRoot=$${directoryIteratorRepoRoot}/contrib/cinternal
        }
}

