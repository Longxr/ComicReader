SET PATH=%PATH%;C:\Qt\Qt5.7.0\5.7\mingw53_32\bin;
SET PATH=%PATH%;C:\Qt\Qt5.7.0\Tools\mingw530_32\bin;
SET PRODUCT_DIR=%~dp0..\product
SET RELEASE_DIR=%~dp0..\bin

CD %~dp0..
if EXIST "Product" (
	RD /S /Q "product"
)

windeployqt.exe %RELEASE_DIR%\KanManHua.exe --dir %PRODUCT_DIR%

pause