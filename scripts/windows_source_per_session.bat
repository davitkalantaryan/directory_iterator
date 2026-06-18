::
:: repo:	    directory_iterator
:: file:	    windows_source_per_session.bat
:: path:	    scripts\windows_source_per_session.bat
:: created on:	2026 Jun 18
:: created by:	Davit Kalantaryan (davit.kalantaryan@desy.de)
:: notice:	    call this to initialize session for development
::

@echo off
setlocal EnableDelayedExpansion enableextensions

set  scriptDirectory=%~dp0
cd /D "%scriptDirectory%.."
set "directoryIteratorRepoRoot=%cd%"
set "repositoryRoot=%directoryIteratorRepoRoot%\"


endlocal & (
    call "%directoryIteratorRepoRoot%\contrib\cinternal\scripts\windows_source_per_session.bat"
    set "directoryIteratorRepoRoot=%directoryIteratorRepoRoot%"
)
