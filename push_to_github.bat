@echo off
title Push to GitHub - arivena-omp
cd /d "%~dp0"

echo ========================================================
echo          PUSHING PRIVILEGED FILES TO GITHUB
echo ========================================================
echo Repository: https://github.com/yakacu/arivena-omp
echo.

echo [INFO] Mengkonfigurasi Git buffer untuk mencegah HTTP 408 timeout...
git config http.postBuffer 524288000
git config http.lowSpeedLimit 0
git config http.lowSpeedTime 999999

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

echo [INFO] Menilai ulang file yang sudah di-stage...
git rm -r --cached . >nul 2>&1
echo [INFO] Menambahkan file baru ke staging area...
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
