# Sistem Pembayaran Parkir
STRUKTUR DATA KELAS C
<br>
KELOMPOK 1
1. 20081010240 Desya Ristya Putri
2. 21081010064 Faris Munir Mahdi
3. 21081010066 Nauval Maulana Rizky Irawan
4. 21081010065 Achmad Robby Sabilul Firdaus
5. 20081010174 Satria Aqilla Gunawan

<br>
Studi kasus: Sistem Pembayaran Keluar Parkir Kendaraan
<br>
Struktur data yang digunakan: Linkedlist dan Queue
<br><br>
Kasus:
<br>
Di sebuah pertokoan, sistem untuk parkir kendaraan sangat diperlukan. Selain untuk keamanan, parkir juga dapat menjadi satu diantara sumber pendapatan pertokoan.
Pada pertokoan X menerapkan sistem parkir dimana data yang dikelola adalah sebagai berikut.
1) No plat kendaraan
2) Warna kendaraan
3) Durasi parkir (dalam menit)
4) Golongan kendaraan (R2/R4)

Biaya parkir memiliki ketentuan sebagai berikut.
1. Setiap tanggal ganjil dan no plat kendaraan ganjil, maka pembayaran parkir diskon 50%, berlaku juga untuk tanggal dan no plat genap.
2. Pelanggan mendapat prioritas berupa dapat menyela antrean ke antrean paling depan apabila warna kendaraan sesuai dengan warna yang ditentukan pada periode setiap harinya. Kendaraan yang mendapat prioritas merupakan kendaraan dengan warna dan hari yang sesuai dengan ketentuan berikut.
	- Senin: hitam
	- Selasa: putih
	- Rabu: Selain hitam dan putih
	- Kamis: hitam
	- Jumat: putih
	- Sabtu: Selain hitam dan putih
	- Minggu: hitam
3. Parkir dengan durasi <= 5 menit tidak dikenakan biaya (gratis).
4. Parkir pada 60 menit pertama dikenakan biaya:
	- R2: 5000
	- R4: 10000
<br>Untuk durasi selanjutnya, dikenakan biaya 1000 setiap 60 menit berikutnya.

Penerapan struktur data pada kasus:
1. Queue, digunakan untuk menyimpan data antrean kendaraan dengan metode First In First Out.
2. Linkedlist, digunakan untuk menyisipkan/menambahkan data kendaraan yang memiliki prioritas untuk menyela antrean.
