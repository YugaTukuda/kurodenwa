@echo off
:start
timeout /t 20 /nobreak
call C:\Users\kurod\anaconda3\Scripts\activate
cd /d "C:\Users\kurod\kurodenwa"
python C:\Users\kurod\kurodenwa\kurodenwa.py sk-########
goto start
