//
// file:			directory_iterator.h
// path:			include/directory_iterator/directory_iterator.h
// created on:		2023 Jan 10
// created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//

#ifndef DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H
#define DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H

#include <directory_iterator/export_symbols.h>
#include <cinternal/disable_compiler_warnings.h>
#include <stdint.h>
#include <cinternal/undisable_compiler_warnings.h>

CPPUTILS_BEGIN_C

#define DIRITER_EXIT_ALL	(387)

// see: https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa
typedef struct SDirIterFileData {
	uint32_t	deepness;  // in case of non recursive call this field is not used
	uint32_t	isDir : 1;
	uint32_t	reserved01 : 31;
	const char* pFileName;
	const void* pSystemData;
}DirIterFileData;

typedef int		(*TypeDirIterFunc)(const char*,void*, const DirIterFileData*);

DIRITER_EXPORT void IterateOverDirectoryFilesNoRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud);
DIRITER_EXPORT void IterateOverDirectoryFilesRecurse(const char* a_sourceDirectory, TypeDirIterFunc a_callback, void* a_ud);


#ifdef _WIN32
#define snprintf_di(_buf,_cnt,...)		_snprintf_s(_buf,_cnt,_cnt,__VA_ARGS__)
#else
#define snprintf_di(_buf,_cnt,...)		snprintf(_buf,_cnt,__VA_ARGS__)
#endif

CPPUTILS_END_C


#endif  // #ifndef DIRECTORY_ITERATOR_INCLUDE_DIRECTORY_ITERATOR_DIRECTORY_ITERATOR_H
