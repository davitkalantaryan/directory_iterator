#
# file:				dir_iter_test01.pro
# path:				prj/tests/dir_iter_test01_qt/dir_iter_test01.pro    
# created on:		2023 Jan 10
# Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
#

message (!!! $$_PRO_FILE_)

include ("$${PWD}/../../../prj/common/common_qt/sys_common.pri")
# include ("$${PWD}/../../../prj/common/common_qt/flags_common.pri")

DESTDIR     = $${artifactRoot}/$${SYSTEM_PATH}/$$CONFIGURATION/test

DIR_ITER_INCLUDE = $${directoryIteratorRepositoryRoot}/include

INCLUDEPATH += $${DIR_ITER_INCLUDE}
INCLUDEPATH += $${cinternalRepoRoot}/include

QT -= core
QT -= gui
CONFIG -= qt


SOURCES +=	\
	$${directoryIteratorRepositoryRoot}/src/tests/main_dir_iter_test01.cpp				\
	$${directoryIteratorRepositoryRoot}/src/core/diriter/directory_iterator_unix.c


HEADERS += $$files($${DIR_ITER_INCLUDE}/*.h,true)

OTHER_FILES +=	\
	$${directoryIteratorRepositoryRoot}/src/core/diriter/directory_iterator_win.c
