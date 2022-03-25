@echo off
:loop
yunshujihua.exe
zj.exe
fc 2.out 1.out
if not errorlevel 1 goto loop
pause
:end
