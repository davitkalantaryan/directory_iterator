//
// file:			directory_iterator_cmn.c  
// path:			src/core/diriter/directory_iterator_cmn.c  
// created on:		2023 Jan 13
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


#include <directory_iterator/directory_iterator.h>
#include <stdio.h>
#include <stdint.h>

#define DIRITER_MAX_PATH_MIN_1	(4095)
#define DIRITER_MAX_PATH		(4096)

CINTERNAL_BEGIN_C


typedef struct CINTERNAL_DLL_PRIVATE _SDirIterRecurseData {
	uint64_t		shouldStop : 1;
	uint64_t		reserved01 : 63;
	void*			pUd;
	TypeDirIterFunc	userClbk;
}SDirIterRecurseData;

static int DirIterFunctionToRecurseStatic(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CINTERNAL_NOEXCEPT;


DIRITER_EXPORT void IterateOverDirectoryFilesRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud)
{
	SDirIterRecurseData aDt;
	aDt.shouldStop = 0;
	aDt.pUd = a_ud;
	aDt.userClbk = a_callback;
	IterateOverDirectoryFilesNoRecurse(a_sourceDirectory, &DirIterFunctionToRecurseStatic, &aDt);
}


static int DirIterFunctionToRecurseStatic(const char* a_sourceDirectory, void* a_pUd, const DirIterFileData* a_pData) CINTERNAL_NOEXCEPT
{
	int nRetByUser;
	SDirIterRecurseData* pDt = (SDirIterRecurseData*)a_pUd;
	if (pDt->shouldStop) {
		return DIRITER_EXIT_ALL;
	}

	nRetByUser = (*(pDt->userClbk))(a_sourceDirectory, pDt->pUd, a_pData);
	if (nRetByUser == DIRITER_EXIT_ALL) {
		pDt->shouldStop = 1;
		return DIRITER_EXIT_ALL;
	}

	if (a_pData->isDir) {
		char  vcStrFilePath[DIRITER_MAX_PATH];
		snprintf_di(vcStrFilePath, DIRITER_MAX_PATH_MIN_1, "%s/%s", a_sourceDirectory, a_pData->pFileName);
		IterateOverDirectoryFilesNoRecurse(vcStrFilePath, &DirIterFunctionToRecurseStatic, pDt);
	}

	return nRetByUser;
}


CINTERNAL_END_C
