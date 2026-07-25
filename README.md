# Arivena Roleplay (open.mp)

Panduan singkat untuk memasang dan menjalankan gamemode Arivena Roleplay berbasis open.mp.

## Persiapan Alat

Sebelum memulai, siapkan beberapa kebutuhan berikut di komputer mu:

- **MySQL / MariaDB**: Bisa menggunakan XAMPP, Laragon, atau HeidiSQL.
- **sampctl**: Digunakan untuk mengkompilasi gamemode.

## Cara Install dan Setup

### 1. Install sampctl

`sampctl` adalah **command-line development tool** untuk mengembangkan skrip Pawn. Pastikan kamu telah menginstalnya sebelum melanjutkan.

**Cara install sampctl:**

- **Untuk semua platform**: Download file `sampctl` (atau `sampctl.exe` di Windows) dari [halaman rilis GitHub](https://github.com/Southclaws/sampctl/releases), lalu letakkan di folder yang sudah termasuk dalam `PATH` komputer mu.

- **Windows (manual)**: Letakkan `sampctl.exe` di folder seperti `C:\sampctl\`, lalu tambahkan folder tersebut ke variabel environment `PATH`.
    - **Cara menambahkan ke PATH**: Buka Start Menu → cari "Environment Variables" → pilih "Edit the system environment variables" → klik "Environment Variables…" → pilih `Path` di bagian "User variables" → klik "Edit…" → klik "New" → masukkan path folder mu (misal: `C:\sampctl`).
    - **Verifikasi**: Tutup dan buka kembali Command Prompt/PowerShell, lalu jalankan perintah `sampctl version` untuk memastikan instalasi berhasil.

- **Linux (Debian/Ubuntu)**: Jalankan perintah berikut di terminal:
  ```bash
  curl -fsSL https://raw.githubusercontent.com/Southclaws/sampctl/master/scripts/install-deb.sh | sh
  ```
  Script ini akan mengunduh dan menginstal paket `.deb` secara otomatis.

- **Linux (RPM-based / Fedora/CentOS)**: Jalankan perintah:
  ```bash
  curl -fsSL https://raw.githubusercontent.com/Southclaws/sampctl/master/scripts/install-rpm.sh | sh
  ```
  Script ini akan mengunduh dan menginstal paket `.rpm`.

- **Linux (distro lain)**: Unduh binary statically compiled untuk arsitektur mu dari [halaman rilis GitHub](https://github.com/Southclaws/sampctl/releases), lalu letakkan di folder yang sudah ada di `PATH` Anda.

- **Windows (dengan Scoop)**: Jika kamu menggunakan manajer paket Scoop:
  1. Install Scoop (jika belum): https://scoop.sh/ 
  2. Tambahkan bucket sampctl: `scoop bucket add sampctl https://github.com/Southclaws/sampctl`
  3. Install sampctl: `scoop install sampctl/sampctl`

- **Linux (dengan Homebrew)**: Jika kamu menggunakan Homebrew, tersedia formula di `Casks/sampctl.rb`.

**Dokumentasi lengkap**: [docs/install.md](https://github.com/Southclaws/sampctl/blob/master/docs/install.md)

### 2. Database

- Buka phpMyAdmin, Laragon, atau HeidiSQL.
- Buat database baru dengan nama `arivena` (atau sesuaikan sendiri).
- Import file database `.sql` yang ada di folder `database` proyek ini.
- Sesuaikan kredensial MySQL (host, user, password, nama database) di file `mysql.ini`.

### 3. Kompilasi Gamemode

- Buka terminal atau Command Prompt di folder utama proyek ini.
- Jalankan perintah kompilasi:
  ```bash
  sampctl build
  ```
- Atau kompilasi file `gamemodes/main.pwn` ke `gamemodes/main.amx` menggunakan Pawn compiler secara manual.

### 4. Menjalankan Server

- Setelah file `main.amx` berhasil dibuat, jalankan server:
    - **Windows**: Buka `omp-server.exe`
    - **Linux**: Jalankan `./omp-server` (jika ada plugin yang tidak ter-upload, kamu bisa mencarinya atau menambahkannya sendiri)
- Server sudah berjalan dan bisa diakses melalui client SA-MP / open.mp menggunakan IP `localhost:7777` atau `127.0.0.1:7777`.