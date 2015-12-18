REM In case some of the long file names are MIA
if exist ..\..\dat\data.bas copy ..\..\dat\data.bas ..\..\dat\data.base
if exist ..\..\include\patchlev.h copy ..\..\include\patchlev.h ..\..\include\patchlevel.h 
if exist ..\..\doc\guideboo.txt copy ..\..\doc\guideboo.txt ..\..\doc\guidebook.txt
REM workaround for MinGW/MSYS conflict unless I found a new way to let them work together
copy lev_flex.c ..\..\src
copy lev_yacc.c ..\..\src
copy dgn_flex.c ..\..\src
copy dgn_yacc.c ..\..\src
copy lev_comp.h ..\..\src
copy dgn_comp.h ..\..\src
copy makefile.gcc ..\..\src\Makefile
copy win32api.h ..\..\include\win32api.h
pause
