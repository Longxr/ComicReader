SET PATH=%PATH%;C:\Qt\Qt5.7.0\5.7\mingw53_32\bin;
SET PATH=%PATH%;C:\Qt\Qt5.7.0\Tools\mingw530_32\bin;
REM SET PATH=%PATH%;C:\Qt\Qt5.12.0\5.12.0\mingw73_32\bin;
REM SET PATH=%PATH%;C:\Qt\Qt5.12.0\Tools\mingw730_32\bin;
SET PRODUCT_DIR=%~dp0..\Product\ComicReader
SET RELEASE_DIR=%~dp0..\RunImage\release
SET VERSION=%1

CD %~dp0..
if EXIST "Intermediate" (
	RD /S /Q "Intermediate"
)

if EXIST "RunImage" (
	RD /S /Q "RunImage"
)

if EXIST "Product" (
	RD /S /Q "Product"
)

if EXIST "Setup" (
	RD /S /Q "Setup"
)

mingw32-make.exe clean
qmake.exe AllProjects.pro -spec win32-g++ "CONFIG+=release" && mingw32-make.exe qmake_all
mingw32-make.exe -j4
lrelease AllProjects.pro

REM copy /y Third\mDNS\*.dll RunImage\release\

CD %RELEASE_DIR%
windeployqt.exe ComicReader.exe --dir %PRODUCT_DIR%
REM windeployqt.exe --qmldir %~dp0..\Assets Common.dll --dir %PRODUCT_DIR% 

copy /y *.dll %PRODUCT_DIR%
copy /y *.exe %PRODUCT_DIR%

CD %~dp0..
REM xcopy /e /y /exclude:Script\uncopy.txt Localizations %PRODUCT_DIR%\Localizations\

pause