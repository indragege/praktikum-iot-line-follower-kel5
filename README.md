# Praktikum IoT — Mobil Line Follower 4WD (Kelompok 5)

Repository source code firmware **Mobil Line Follower 4WD** berbasis mikrokontroler Arduino Uno R3 untuk pemenuhan Tugas Besar Ujian Tengah Semester (UTS) mata kuliah **Praktikum Internet of Things**.

## Informasi Akademik
* **Mata Kuliah:** Praktikum Internet of Things
* **Dosen Pengampu:** Mohammad Bayu Anggara, S.Kom., M.Kom.
* **Program Studi:** Teknik Informatika — Fakultas Teknologi Informasi
* **Institusi:** Universitas Bale Bandung (2026)

## Anggota Kelompok 5
| No | Nama Lengkap | NIM | Peran / Tugas |
| :---: | :--- | :---: | :--- |
| 1 | Nela Nurazizah | 301230029 | Ketua Kelompok, Koordinasi Tim & Penyusunan Laporan Utama |
| 2 | Indra Mulyadi | 301230005 | Perancangan Mekanik Chassis & Perakitan Hardware |
| 3 | Muhammad Taufik Rahmatullah | 301230042 | Pemrograman Firmware, Wiring Elektronik & Kalibrasi Sensor |
| 4 | Rahayu Febrianti | 301230057 | Penyusunan Slide Presentasi (.pptx) & Finalisasi Laporan |
| 5 | Erga Refaldy Dwi Gustian | 301230006 | Dokumentasi Pengujian & Produksi Video Tutorial |

## Spesifikasi Perangkat Keras
* **Mikrokontroler:** Arduino Uno R3 (ATmega328P SMD)
* **Driver Motor:** L298N Dual H-Bridge
* **Sensor:** 2x Modul Sensor Garis Inframerah (TCRT5000 + Komparator LM393)
* **Chassis & Aktuator:** Smart Car 4WD Double-Layer Acrylic + 4x TT DC Gear Motor (1:48)
* **Catu Daya:** 4x Baterai AA 1.5V (6V DC)

## Pemetaan Pin (Wiring)
| Pin Arduino | Komponen / Terminal | Warna Kabel | Fungsi Sinyal |
| :--- | :--- | :--- | :--- |
| **D2** | Sensor Garis Kiri (`OUT`) | Hitam | Input digital sensor kiri (`0` = putih, `1` = hitam) |
| **D3** | Sensor Garis Kanan (`OUT`) | Hitam | Input digital sensor kanan (`0` = putih, `1` = hitam) |
| **D11 (PWM)** | Driver L298N (`ENA`) | Cokelat | Output sinyal PWM kecepatan motor kiri |
| **D10** | Driver L298N (`IN1`) | Merah | Output logika arah putar motor kiri |
| **D9** | Driver L298N (`IN2`) | Kuning | Output logika arah putar motor kiri |
| **D8** | Driver L298N (`IN3`) | Oranye | Output logika arah putar motor kanan |
| **D7** | Driver L298N (`IN4`) | Hijau | Output logika arah putar motor kanan |
| **D6 (PWM)** | Driver L298N (`ENB`) | Biru | Output sinyal PWM kecepatan motor kanan |

## Logika Navigasi & Parameter PWM
* **Kecepatan Jalan Lurus (`kecepatanMaju`):** `140`
* **Kecepatan Belok Skid-Steering (`kecepatanBelok`):** `230`
* **Telemetri Serial:** UART `9600 bps`

| Sensor Kiri (`D2`) | Sensor Kanan (`D3`) | Kondisi Lintasan | Aksi Robot |
| :---: | :---: | :--- | :--- |
| `0` (LOW) | `0` (LOW) | Kedua sensor di lantai putih (garis di tengah) | **Maju Lurus** (`PWM 140`) |
| `1` (HIGH) | `0` (LOW) | Sensor kiri menyentuh garis hitam | **Belok Kiri** (`PWM 230`) |
| `0` (LOW) | `1` (HIGH) | Sensor kanan menyentuh garis hitam | **Belok Kanan** (`PWM 230`) |
| `1` (HIGH) | `1` (HIGH) | Kedua sensor menyentuh garis hitam melintang | **Berhenti** (`PWM 0`) |

## Struktur File
* `line_follower_4wd.ino` — Source code utama program kendali navigasi dan telemetri serial robot.
* `README.md` — Dokumentasi rangkaian, logika kendali, dan informasi tim pengembang.
