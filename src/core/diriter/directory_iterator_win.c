//
// file:			directory_iterator_win.c  
// path:			src/core/diriter/directory_iterator_win.c  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//



#include <directory_iterator/export_symbols.h>

#ifdef _WIN32

#include <directory_iterator/directory_iterator.h>
#include <cinternal/disable_compiler_warnings.h>
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <cinternal/undisable_compiler_warnings.h>

#define DIRITER_MAX_PATH		(2*MAX_PATH)

CPPUTILS_BEGIN_C

static void WinDataToClbkData(DirIterFileData* a_pClbk, const WIN32_FIND_DATAA* a_pWinData)
{
	a_pClbk->isDir = (a_pWinData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? CPPUTILS_STATIC_CAST(uint64_t, 1) : CPPUTILS_STATIC_CAST(uint64_t, 0);
	a_pClbk->pFileName = a_pWinData->cFileName;
	a_pClbk->pSystemData = CPPUTILS_STATIC_CAST(const void*, a_pWinData);
}


DIRITER_EXPORT void IterateOverDirectoryFilesNoRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud)
{
	HANDLE				hFile;                       // Handle to directory
	WIN32_FIND_DATAA	FileInformation;             // File information
	char				vcStrPattern[DIRITER_MAX_PATH];

	if (!(GetFileAttributesA(a_sourceDirectory) & FILE_ATTRIBUTE_DIRECTORY)) { return; }

	_snprintf_s(vcStrPattern, DIRITER_MAX_PATH, DIRITER_MAX_PATH, "%s\\*.*", a_sourceDirectory);

	hFile = FindFirstFileA(vcStrPattern, &FileInformation);
	if (hFile != INVALID_HANDLE_VALUE) {
		int					nReturnFromCallback;
		DirIterFileData		aClbkData;
		
		do {
			WinDataToClbkData(&aClbkData, &FileInformation);

			nReturnFromCallback = (*a_callback)(a_sourceDirectory,a_ud, &aClbkData);
			if (nReturnFromCallback) { break; }

		} while (FindNextFileA(hFile, &FileInformation) == TRUE);

		// Close handle
		FindClose(hFile);
	}
}


CPPUTILS_END_C


#endif  //  #ifdef _WIN32
