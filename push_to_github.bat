@echo off
title Push to GitHub - arivena-omp
cd /d "%~dp0"

echo ========================================================
echo          PUSHING PRIVILEGED FILES TO GITHUB
echo ========================================================
echo Repository: https://github.com/yakacu/arivena-omp
echo.

if not exist ".git" (
    echo [INFO] Inisialisasi Git repository...
    git init
    git remote add origin https://github.com/yakacu/arivena-omp.git
) else (
    echo [INFO] Memeriksa remote origin...
    git remote set-url origin https://github.com/yakacu/arivena-omp.git
)

echo [INFO] Mengatur branch utama ke 'main'...
git branch -M main

echo [INFO] Menambahkan file ke staging area...
git add .

echo.
set /p commit_msg="Masukkan pesan commit (tekan Enter untuk default 'Update project files'): "
if "%commit_msg%"=="" set commit_msg=Update project files

echo [INFO] Melakukan commit dengan pesan: "%commit_msg%"...
git commit -m "%commit_msg%"

echo [INFO] Mengunggah file ke GitHub (main)...
git push -u origin main

echo.
echo ========================================================
echo                PROSES PUSH SELESAI!
echo ========================================================
pause
