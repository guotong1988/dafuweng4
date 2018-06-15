@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by R4.HPJ. >"hlp\R4.hm"
echo. >>"hlp\R4.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\R4.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\R4.hm"
echo. >>"hlp\R4.hm"
echo // Prompts (IDP_*) >>"hlp\R4.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\R4.hm"
echo. >>"hlp\R4.hm"
echo // Resources (IDR_*) >>"hlp\R4.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\R4.hm"
echo. >>"hlp\R4.hm"
echo // Dialogs (IDD_*) >>"hlp\R4.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\R4.hm"
echo. >>"hlp\R4.hm"
echo // Frame Controls (IDW_*) >>"hlp\R4.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\R4.hm"
REM -- Make help for Project R4


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\R4.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\R4.hlp" goto :Error
if not exist "hlp\R4.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\R4.hlp" Debug
if exist Debug\nul copy "hlp\R4.cnt" Debug
if exist Release\nul copy "hlp\R4.hlp" Release
if exist Release\nul copy "hlp\R4.cnt" Release
echo.
goto :done

:Error
echo hlp\R4.hpj(1) : error: Problem encountered creating help file

:done
echo.
