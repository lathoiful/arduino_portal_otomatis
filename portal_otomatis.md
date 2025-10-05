# Portal Otomatis dengan Servo dan Sensor Ultrasonik

## Deskripsi
Project ini menggunakan Arduino / Uno / Nano (atau board kompatibel) untuk membuka dan menutup portal secara otomatis berdasarkan jarak objek yang terdeteksi sensor ultrasonik.
- Jika ada benda mendekat (<30 cm), servo akan membuka portal.
- Jika tidak ada benda atau objek menjauh, portal akan menutup.

## Fitur
- Portal buka/tutup otomatis berdasarkan sensor ultrasonik
- Servo bergerak halus dengan kecepatan yang bisa diatur
- Serial monitor menampilkan jarak dan status portal

## Hardware yang dibutuhkan
- Arduino (Uno/Nano/board compatible)
- Servo motor (misal SG90)
- Sensor Ultrasonik HC-SR04
- Kabel jumper
- Breadboard (opsional)

## Wiring / Skema Rangkaian

| Komponen | Pin Arduino | Keterangan |
|----------|------------|------------|
| Servo    | 6          | Signal (VCC ke 5V, GND ke GND) |
| Trig HC-SR04 | 9       | Output trigger sensor |
| Echo HC-SR04 | 10      | Input echo sensor |
| VCC HC-SR04  | 5V      | Power sensor |
| GND HC-SR04  | GND     | Ground |

Diagram sederhana:
```
       +5V
        |
      [HC-SR04 VCC]
       Trig --> Arduino Pin 9
       Echo --> Arduino Pin 10
        |
       GND --> Arduino GND

Servo:
   Signal --> Arduino Pin 6
   VCC --> 5V
   GND --> GND
```

## Library yang dibutuhkan
- Servo.h (standar Arduino, biasanya sudah ada di IDE)

## Cara Upload
1. Hubungkan Arduino ke komputer via USB
2. Pilih board & port di Arduino IDE
3. Upload sketch
4. Buka Serial Monitor untuk melihat jarak & status portal

## Konfigurasi
Ubah variabel sesuai kebutuhan:
```cpp
const int openAngle = 90;   // sudut buka
const int closeAngle = 0;   // sudut tutup
const int threshold = 30;   // jarak dalam cm untuk membuka portal
const int moveDelay = 15;   // kecepatan servo
const int checkDelay = 200; // waktu jeda pembacaan sensor
```

## Catatan
- Pastikan servo mendapatkan daya yang cukup (kalau servo besar, gunakan power terpisah)
- Sensor ultrasonik memiliki jangkauan tertentu, jangan terlalu dekat dengan benda yang sangat kecil

