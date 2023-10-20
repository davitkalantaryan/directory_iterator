#
# file:			directory_iterator_all.pro
# path:			workspaces/directory_iterator_all_qt/directory_iterator_all.pro
# created on:		2023 Jan 10
# Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
#

message("!!! $${_PRO_FILE_}")

TEMPLATE = subdirs
#CONFIG += ordered

include ( "$${PWD}/../../prj/common/common_qt/flagsandsys_common.pri" )

SUBDIRS		+=	"$${directoryIteratorRepoRoot}/prj/tests/any_quick_test_qt/any_quick_test.pro"
SUBDIRS		+=	"$${directoryIteratorRepoRoot}/prj/tests/diriter_unit_test_mult/diriter_unit_test.pro"

cinternalFromHere{
        SUBDIRS	+= "$${cinternalRepoRoot}/workspaces/cinternal_all_qt/cinternal_all.pro"
}


greaterThan(QT_MAJOR_VERSION, 4):QT += widgets

OTHER_FILES += $$files($${directoryIteratorRepoRoot}/docs/*.md,true)
OTHER_FILES += $$files($${directoryIteratorRepoRoot}/docs/*.txt,true)
OTHER_FILES += $$files($${directoryIteratorRepoRoot}/scripts/*.sh,true)
OTHER_FILES += $$files($${directoryIteratorRepoRoot}/scripts/*.bat,true)
OTHER_FILES += $$files($${directoryIteratorRepoRoot}/.github/*.yml,true)

OTHER_FILES	+=	\
        $${directoryIteratorRepoRoot}/.gitattributes			\
	$${directoryIteratorRepoRoot}/.gitignore			\
	$${directoryIteratorRepoRoot}/LICENSE				\
	$${directoryIteratorRepoRoot}/README.md
