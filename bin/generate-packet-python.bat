@echo off
@REM SET SCRIPT_PATH=%~dp0
@REM SET SCRIPT_PATH=/Users/shohtatakami/github/Leica_KEK
@REM python %SCRIPT_PATH%/pygen-packet.py %SCRIPT_PATH%/../Include/ES_C_API_Def_clean.h > %SCRIPT_PATH%/../CESAPI/packet.py
python /Users/shohtatakami/github/Leica_KEK/bin/pygen-packet.py /Users/shohtatakami/github/Leica_KEK/bin/../Include/ES_C_API_Def_clean.h > /Users/shohtatakami/github/Leica_KEK/bin/../CESAPI/packet.py