@echo off
:loop
makedata.exe
2018ecjj.exe
zj.exe
fc 2.out 1.out
if not errorlevel 1 goto loop
pause
:end
