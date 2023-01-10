//
// file:			directory_iterator_win.c  
// path:			src/core/diriter/directory_iterator_win.c  
// created on:		2023 Jan 10
// Created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//



#include <directory_iterator/export_symbols.h>

#ifdef _WIN32

#include <directory_iterator/directory_iterator.h>
#include <stdio.h>
#include <cinternal/disable_compiler_warnings.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#define DIRITER_MAX_PATH		(2*MAX_PATH)

CINTERNAL_BEGIN_C

static void WinDataToClbkData(DirIterFileData* a_pClbk, const WIN32_FIND_DATAA* a_pWinData)
{
	a_pClbk->isDir = (a_pWinData->dwFileAttributes& FILE_ATTRIBUTE_DIRECTORY)? CINTERNAL_STATIC_CAST(uint64_t,1): CINTERNAL_STATIC_CAST(uint64_t, 0);
	a_pClbk->fileAttributes = CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->dwFileAttributes);
	a_pClbk->creationTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftCreationTime.dwHighDateTime)<<32)& 
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftCreationTime.dwLowDateTime);
	a_pClbk->lastAccessTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastAccessTime.dwHighDateTime) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastAccessTime.dwLowDateTime);
	a_pClbk->lastWriteTimeIn100Ms = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastWriteTime.dwHighDateTime) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->ftLastWriteTime.dwLowDateTime);
	a_pClbk->fileSize = (CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->nFileSizeHigh) << 32) &
		CINTERNAL_STATIC_CAST(uint64_t, a_pWinData->nFileSizeLow);
	a_pClbk->pFileName = a_pWinData->cFileName;
	a_pClbk->pAlternateFileName = a_pWinData->cAlternateFileName;
}


DIRITER_EXPORT void IterateOverDirectoryFiles(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud)
{
	HANDLE				hFile;                       // Handle to directory
	WIN32_FIND_DATAA	FileInformation;             // File information
	int					nReturnFromCallback;
	char				vcStrPattern[DIRITER_MAX_PATH];
	DirIterFileData		aClbkData;

	if (!(GetFileAttributesA(a_sourceDirectory) & FILE_ATTRIBUTE_DIRECTORY)) { return; }

	_snprintf_s(vcStrPattern, DIRITER_MAX_PATH, DIRITER_MAX_PATH, "%s\\*.*", a_sourceDirectory);

	hFile = FindFirstFileA(vcStrPattern, &FileInformation);
	if (hFile != INVALID_HANDLE_VALUE) {
		do {
			if (FileInformation.cFileName[0] == '.') {
				if ((FileInformation.cFileName[1] == 0) || ((FileInformation.cFileName[1] == '.') && (FileInformation.cFileName[2] == 0))) { continue; }
			}

			WinDataToClbkData(&aClbkData, &FileInformation);

			nReturnFromCallback = (*a_callback)(a_sourceDirectory,a_ud, &aClbkData);
			if (nReturnFromCallback) { break; }

		} while (FindNextFileA(hFile, &FileInformation) == TRUE);

		// Close handle
		FindClose(hFile);
	}
}


CINTERNAL_END_C


#endif  //  #ifdef _WIN32
