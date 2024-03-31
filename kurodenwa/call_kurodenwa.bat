@echo off
:start
timeout /t 20 /nobreak
call C:\Users\kurod\anaconda3\Scripts\activate
cd /d "C:\Users\kurod\kurodenwa"
python C:\Users\kurod\kurodenwa\kurodenwa.py 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
goto start