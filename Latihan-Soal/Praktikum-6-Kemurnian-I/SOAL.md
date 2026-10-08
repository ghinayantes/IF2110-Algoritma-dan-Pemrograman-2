# 20 Soal Latihan Praktikum Pemrograman Fungsional: Pohon

Bahan: Bab 10 Diktat Pemrograman Fungsional (Pohon) dan format soal `TreeFold.hs`.
Setiap soal terdiri dari: cerita, spesifikasi fungsi, batasan, contoh aplikasi fungsi, dan penjelasan contoh.
Template yang harus Anda lengkapi ada di folder `soal/`, dan solusi pembanding ada di folder `solusi/`.

**Cara berlatih.** Buka `soal/NamaFile.hs`, ganti isi fungsi yang masih `error "TODO"`, lalu uji dengan `ghci NamaFile.hs`. Pohon uji coba (`ta`, `tb`, dan seterusnya) sudah didefinisikan di dalam file sehingga bisa langsung dipakai. Contoh pada komentar template bisa disalin ke GHCi.

**Ringkasan soal dan prediksi kemunculan**

| No | Judul | File | Level | Topik | Peluang muncul |
|---|---|---|---|---|---|
| 1 | Banyak Ruangan Rahasia | `BanyakRuangan.hs` | Mudah | size (banyak simpul) | Hampir pasti |
| 2 | Tinggi Lift Mystery Shack | `TinggiLift.hs` | Mudah | height (tinggi pohon) | Hampir pasti |
| 3 | Kristal di Ruangan Buntu | `KristalBuntu.hs` | Mudah | daun & nilai pada daun | Hampir pasti |
| 4 | Penimbang Koin Susu | `PenimbangKoin.hs` | Mudah | fungsi sebagai parameter (filter + akumulasi) | Sangat mungkin |
| 5 | Rentang Suhu Ruangan | `SuhuRuangan.hs` | Mudah | max/min pada pohon sembarang | Sangat mungkin |
| 6 | Cermin Ajaib Paman Frod | `CerminAjaib.hs` | Mudah | mirror (membangun pohon baru) | Sangat mungkin |
| 7 | Sihir Pengganda Mebel | `SihirPengganda.hs` | Menengah | mapTree & aplikasi fungsi berulang | Sangat mungkin |
| 8 | Tiga Penjelajah Lorong | `TigaPenjelajah.hs` | Mudah | traversal pre/in/post-order | Hampir pasti |
| 9 | Lipatan Terbalik Paman Stenli | `LipatanTerbalik.hs` | Sulit | treeFold varian (kanan-akar-kiri) | Sangat mungkin |
| 10 | Katalog Perpustakaan Bawah Tanah | `KatalogPerpustakaan.hs` | Menengah | BST: pencarian & min | Hampir pasti |
| 11 | Menyisipkan Buku Baru | `SisipBuku.hs` | Menengah | BST: insert & hapus min | Hampir pasti |
| 12 | Menyusun Tumpukan Stiker | `TumpukanStiker.hs` | Menengah | membangun BST dari list & tree sort | Sangat mungkin |
| 13 | Audit Katalog Paman Frod | `AuditKatalog.hs` | Sulit | validasi invarian BST | Sangat mungkin |
| 14 | Kedalaman Peti Harta Karun | `KedalamanPeti.hs` | Menengah | BST: jalur pencarian & kedalaman | Sangat mungkin |
| 15 | Keseimbangan Ruang Rahasia | `KeseimbanganRuang.hs` | Sulit | pohon seimbang (height berulang) | Mungkin |
| 16 | Jalur Tol Menuju Pintu Keluar | `JalurTol.hs` | Sulit | jalur akar-ke-daun | Sangat mungkin |
| 17 | Lantai-Lantai Gedung Rahasia | `LantaiGedung.hs` | Sulit | level pohon | Mungkin |
| 18 | Peta Kembar dan Peta Simetris | `PetaKembar.hs` | Sulit | kesamaan, upapohon, simetri | Mungkin |
| 19 | Sandi Aritmetika Paman Frod | `SandiPamanFrod.hs` | Sulit | pohon ekspresi (evaluate, prefix, postfix) | Sangat mungkin |
| 20 | Arsip Bercabang Mystery Shack | `ArsipBercabang.hs` | Sulit | pohon n-aire (rekursi tidak langsung) | Mungkin |

Catatan prediksi: soal bertopik size, height, daun, traversal, fold, dan operasi pada pohon terurut (BST) adalah yang paling mungkin keluar karena itulah inti Bab 10. Soal berparameter fungsi (soal 4, 7, 9) meniru gaya soal `ulang` dan `sigma` pada contoh gambar Anda. Soal pohon ekspresi dan pohon n-aire muncul karena keduanya dibahas langsung pada bab tersebut.

---

## Soal 1: Banyak Ruangan Rahasia

| | |
|---|---|
| **Nama File** | `BanyakRuangan.hs` |
| **Header** | `module BanyakRuangan where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Musim panas di Nangor Falls tidak pernah membosankan. Deeper dan Mebel menemukan peta lorong rahasia di bawah Mystery Shack. Setiap ruangan pada peta bercabang ke paling banyak dua lorong (kiri dan kanan), dan setiap ruangan diberi nomor. Paman Frod ingin tahu ada berapa ruangan di seluruh jaringan lorong itu agar ia tahu berapa senter yang harus dibawa. Bantulah mereka membuat fungsi **banyakRuangan**.

**Spesifikasi Fungsi:**

```haskell
banyakRuangan :: BinTree Int -> Int
```

- `banyakRuangan t` menghasilkan banyaknya simpul (ruangan) pada pohon `t`.
- Pohon kosong tidak memiliki ruangan, sehingga hasilnya `0`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Fungsi harus rekursif; tidak boleh mengubah pohon menjadi list lalu memanggil `length`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> banyakRuangan Empty
0
> banyakRuangan (Node 7 Empty Empty)
1
> banyakRuangan (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
3
> banyakRuangan (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
5
```

**Penjelasan contoh:**

- Pohon kosong tidak punya ruangan, jadi hasilnya `0`; pohon satu simpul menghasilkan `1`.
- Pohon `tb` memiliki simpul bernilai 4, 2, 1, 5, dan 7, sehingga ada `5` ruangan.

---

## Soal 2: Tinggi Lift Mystery Shack

| | |
|---|---|
| **Nama File** | `TinggiLift.hs` |
| **Header** | `module TinggiLift where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Paman Stenli berencana memasang lift di sepanjang lorong terdalam Mystery Shack. Panjang lift ditentukan oleh jumlah ruangan yang dilewati pada jalur terpanjang dari ruangan paling atas (akar) sampai ruangan buntu (daun). Jalur terpanjang itu bisa berada di kiri maupun di kanan. Buatlah fungsi **tinggiLift** untuk menghitungnya agar Paman Stenli tidak salah membeli kabel.

**Spesifikasi Fungsi:**

```haskell
tinggiLift :: BinTree Int -> Int
```

- `tinggiLift t` menghasilkan banyaknya simpul pada jalur terpanjang dari akar sampai sebuah daun.
- Tinggi pohon kosong adalah `0`, dan tinggi pohon dengan satu simpul adalah `1`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Tinggi pohon paling banyak `1000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tc:
  1
  |---\
      2
      |---\
          3
          |---\
              4

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> tinggiLift Empty
0
> tinggiLift (Node 7 Empty Empty)
1
> tinggiLift (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
2
> tinggiLift (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
3
> tinggiLift (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
4
```

**Penjelasan contoh:**

- Pohon `tc` hanya punya cabang kanan: 1, 2, 3, 4. Jalur terpanjangnya melewati `4` simpul.
- Pada `tb`, jalur 4-2-1 dan 4-5-7 sama-sama melewati `3` simpul, sehingga tingginya `3`.

---

## Soal 3: Kristal di Ruangan Buntu

| | |
|---|---|
| **Nama File** | `KristalBuntu.hs` |
| **Header** | `module KristalBuntu where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Mebel gemar mengumpulkan kristal yang hanya tumbuh di ruangan buntu, yaitu ruangan yang tidak memiliki lorong lanjutan ke kiri maupun ke kanan. Ruangan yang masih punya satu lorong lanjutan **bukan** ruangan buntu. Mebel meminta Anda membuat dua fungsi: **jumlahBuntu** untuk menghitung banyaknya ruangan buntu, dan **jumlahKristal** untuk menjumlahkan nomor seluruh ruangan buntu, karena nomor ruangan itu menyatakan banyaknya kristal di dalamnya.

**Spesifikasi Fungsi:**

```haskell
jumlahBuntu :: BinTree Int -> Int
jumlahKristal :: BinTree Int -> Int
```

- `jumlahBuntu t` menghasilkan banyaknya daun pada `t`, yaitu simpul tanpa subpohon kiri dan tanpa subpohon kanan.
- Pohon kosong tidak memiliki daun.
- `jumlahKristal t` menghasilkan jumlah nilai seluruh daun pada `t`.
- Jika `t` kosong, hasilnya `0`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Simpul yang hanya memiliki satu anak bukan daun.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tc:
  1
  |---\
      2
      |---\
          3
          |---\
              4

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> jumlahBuntu Empty
0
> jumlahBuntu (Node 7 Empty Empty)
1
> jumlahBuntu (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
2
> jumlahBuntu (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
1
> jumlahKristal Empty
0
> jumlahKristal (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
4
> jumlahKristal (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
8
> jumlahKristal (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
4
```

**Penjelasan contoh:**

- Pada `tb`, simpul 2 hanya punya anak kiri dan simpul 5 hanya punya anak kanan, sehingga keduanya bukan daun. Daunnya adalah 1 dan 7: `jumlahBuntu` bernilai `2` dan `jumlahKristal` bernilai `1 + 7 = 8`.
- Pada `tc`, hanya simpul 4 yang tidak punya anak, sehingga hasilnya `1` dan `4`.

---

## Soal 4: Penimbang Koin Susu

| | |
|---|---|
| **Nama File** | `PenimbangKoin.hs` |
| **Header** | `module PenimbangKoin where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Susu menemukan peti-peti koin yang disusun bercabang seperti pohon; setiap peti berisi sejumlah koin sesuai nomornya. Sayangnya, Susu hanya boleh membawa pulang peti yang memenuhi sebuah syarat tertentu, misalnya hanya peti bernomor genap atau hanya peti bernomor lebih dari tiga. Syarat tersebut diberikan sebagai sebuah fungsi. Buatlah fungsi **sumIf** yang menjumlahkan nilai semua simpul yang memenuhi syarat, serta **banyakIf** yang menghitung banyaknya simpul tersebut.

**Spesifikasi Fungsi:**

```haskell
sumIf :: (Int -> Bool) -> BinTree Int -> Int
banyakIf :: (Int -> Bool) -> BinTree Int -> Int
```

- `sumIf p t` menghasilkan jumlah nilai seluruh simpul `x` pada `t` yang memenuhi `p x`.
- Jika tidak ada simpul yang memenuhi, atau `t` kosong, hasilnya `0`.
- `banyakIf p t` menghasilkan banyaknya simpul `x` pada `t` yang memenuhi `p x`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Fungsi `p` selalu terdefinisi untuk semua `Int`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7
```

**Contoh aplikasi fungsi:**

```text
> sumIf even Empty
0
> sumIf even (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
6
> sumIf (> 3) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
16
> sumIf (\x -> x `mod` 3 == 0) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
3
> sumIf (> 100) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
0
> banyakIf odd (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
3
> banyakIf (< 0) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
0
> banyakIf (\x -> x > 1 && x < 5) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
2
```

**Penjelasan contoh:**

- Pada `sumIf even` atas `tb`, simpul genapnya adalah 4 dan 2, sehingga jumlahnya `6`.
- Pada `sumIf (> 3)`, simpul yang lolos adalah 4, 5, dan 7: `4 + 5 + 7 = 16`.
- Pada `banyakIf odd`, simpul ganjilnya adalah 1, 5, dan 7, sehingga ada `3`.

---

## Soal 5: Rentang Suhu Ruangan

| | |
|---|---|
| **Nama File** | `SuhuRuangan.hs` |
| **Header** | `module SuhuRuangan where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Wendi memasang termometer di setiap ruangan rahasia dan mencatat suhunya. Ruangan-ruangan itu membentuk pohon, tetapi suhunya tidak berurutan sama sekali, sehingga ruangan terdingin dan terpanas bisa berada di mana saja. Wendi ingin mengetahui suhu terpanas, suhu terdingin, dan **rentang** suhu, yaitu selisih keduanya. Pohon yang diamati selalu memiliki paling sedikit satu ruangan.

**Spesifikasi Fungsi:**

```haskell
suhuMaks :: BinTree Int -> Int
suhuMin :: BinTree Int -> Int
rentangSuhu :: BinTree Int -> Int
```

- `suhuMaks t` menghasilkan nilai terbesar pada `t`.
- Prasyarat: `t` tidak kosong.
- `suhuMin t` menghasilkan nilai terkecil pada `t`.
- Prasyarat: `t` tidak kosong.
- `rentangSuhu t` menghasilkan `suhuMaks t - suhuMin t`.
- Prasyarat: `t` tidak kosong.

**Batasan:**

- Pohon selalu tidak kosong.
- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`; pohon **bukan** pohon terurut.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tx:
  7

td:
          3
  /-------|---\
  -4          0
  |---\
      9
```

**Contoh aplikasi fungsi:**

```text
> suhuMaks (Node 7 Empty Empty)
7
> suhuMaks (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
7
> suhuMaks (Node 3 (Node (-4) Empty (Node 9 Empty Empty)) (Node 0 Empty Empty))
9
> suhuMin (Node 7 Empty Empty)
7
> suhuMin (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
1
> suhuMin (Node 3 (Node (-4) Empty (Node 9 Empty Empty)) (Node 0 Empty Empty))
-4
> rentangSuhu (Node 7 Empty Empty)
0
> rentangSuhu (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
6
> rentangSuhu (Node 3 (Node (-4) Empty (Node 9 Empty Empty)) (Node 0 Empty Empty))
13
```

**Penjelasan contoh:**

- Pohon `td` tidak terurut: nilainya 3, -4, 9, dan 0. Nilai terbesar `9` berada di cucu, dan nilai terkecil `-4` berada di anak kiri, sehingga rentangnya `9 - (-4) = 13`.
- Pohon satu simpul memiliki maksimum dan minimum yang sama, sehingga rentangnya `0`.

---

## Soal 6: Cermin Ajaib Paman Frod

| | |
|---|---|
| **Nama File** | `CerminAjaib.hs` |
| **Header** | `module CerminAjaib where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Di ruang kerja Paman Frod terdapat sebuah cermin ajaib. Jika peta lorong rahasia diletakkan di depannya, bayangan yang muncul adalah peta yang lorong kiri dan kanannya tertukar pada **setiap** ruangan, tanpa mengubah nomor ruangan mana pun. Deeper ingin meniru kerja cermin itu lewat program. Buatlah fungsi **cermin** yang menghasilkan pohon bayangannya.

**Spesifikasi Fungsi:**

```haskell
cermin :: BinTree Int -> BinTree Int
```

- `cermin t` menghasilkan pohon yang subpohon kiri dan kanannya tertukar pada setiap simpul.
- `cermin Empty` adalah `Empty`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Hasil harus berupa pohon baru; pohon asal tidak berubah.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tc:
  1
  |---\
      2
      |---\
          3
          |---\
              4
```

**Contoh aplikasi fungsi:**

```text
> cermin Empty
Empty
> cermin (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
Node 2 (Node 3 Empty Empty) (Node 1 Empty Empty)
> cermin (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 4 (Node 5 (Node 7 Empty Empty) Empty) (Node 2 Empty (Node 1 Empty Empty))
> cermin (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
Node 1 (Node 2 (Node 3 (Node 4 Empty Empty) Empty) Empty) Empty
> cermin (cermin (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))))
Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
```

**Penjelasan contoh:**

- Pada `ta`, simpul 1 dan 3 bertukar tempat.
- Pada `tb`, penukaran terjadi di akar dan juga di dalam kedua upapohonnya; simpul 2 dan 5 berpindah sisi, lalu 1 dan 7 ikut berpindah sisi di dalam upapohonnya masing-masing.
- `cermin (cermin t)` selalu menghasilkan `t` kembali.

---

## Soal 7: Sihir Pengganda Mebel

| | |
|---|---|
| **Nama File** | `SihirPengganda.hs` |
| **Header** | `module SihirPengganda where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Menengah |

Mebel menemukan sweter sihir yang dapat mengubah nilai setiap kristal pada pohon kristal. Mantra sweter itu berupa sebuah fungsi, dan mantra tersebut diterapkan pada **setiap** kristal tanpa mengubah bentuk pohonnya. Sweter itu juga dapat dipakai berkali-kali: mantra yang sama diterapkan sebanyak `n` kali pada tiap kristal. Buatlah fungsi **mapTree** dan **ulangTree** untuk meniru sweter tersebut.

**Spesifikasi Fungsi:**

```haskell
mapTree :: (Int -> Int) -> BinTree Int -> BinTree Int
ulangTree :: Int -> (Int -> Int) -> BinTree Int -> BinTree Int
```

- `mapTree f t` menghasilkan pohon dengan bentuk yang sama seperti `t`, dengan nilai tiap simpul `x` diganti menjadi `f x`.
- `ulangTree n f t` menghasilkan pohon dengan bentuk yang sama seperti `t`, dengan nilai tiap simpul `x` diganti menjadi `f` yang diterapkan `n` kali pada `x`.
- Jika `n = 0`, hasilnya adalah `t` tanpa perubahan.

**Batasan:**

- `0 <= n <= 4` pada `ulangTree`.
- Banyak simpul pada pohon paling banyak `1000`.
- Nilai awal setiap simpul berada pada rentang `-10` sampai `10`; seluruh hasil perhitungan muat dalam `Int`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7
```

**Contoh aplikasi fungsi:**

```text
> mapTree (* 2) Empty
Empty
> mapTree (* 2) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
Node 4 (Node 2 Empty Empty) (Node 6 Empty Empty)
> mapTree (\x -> x * x - 1) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 15 (Node 3 (Node 0 Empty Empty) Empty) (Node 24 Empty (Node 48 Empty Empty))
> ulangTree 0 (* 2) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
> ulangTree 3 (+ 2) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
Node 8 (Node 7 Empty Empty) (Node 9 Empty Empty)
> ulangTree 2 (\x -> x * x) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
Node 16 (Node 1 Empty Empty) (Node 81 Empty Empty)
> ulangTree 2 (* 2) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 16 (Node 8 (Node 4 Empty Empty) Empty) (Node 20 Empty (Node 28 Empty Empty))
```

**Penjelasan contoh:**

- `ulangTree 3 (+ 2) ta` menambahkan `2` sebanyak tiga kali, yaitu `+6`, pada setiap simpul: 2 menjadi 8, 1 menjadi 7, dan 3 menjadi 9.
- `ulangTree 2 (\x -> x * x) ta`: 2 menjadi 4 lalu 16, 1 tetap 1, dan 3 menjadi 9 lalu 81.

---

## Soal 8: Tiga Penjelajah Lorong

| | |
|---|---|
| **Nama File** | `TigaPenjelajah.hs` |
| **Header** | `module TigaPenjelajah where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Mudah |

Deeper, Mebel, dan Susu menjelajahi labirin berbentuk pohon, dan masing-masing mencatat nomor ruangan sesuai kebiasaannya. Deeper selalu mencatat ruangan **sebelum** masuk ke lorong kiri dan kanan. Mebel mencatat ruangan **setelah** keluar dari lorong kiri dan **sebelum** masuk ke lorong kanan. Susu baru mencatat ruangan **setelah** kedua lorongnya selesai dijelajahi. Lorong kiri selalu dijelajahi lebih dulu daripada lorong kanan. Buatlah fungsi **catatanDeeper**, **catatanMebel**, dan **catatanSusu** untuk menghasilkan catatan masing-masing.

**Spesifikasi Fungsi:**

```haskell
catatanDeeper :: BinTree Int -> [Int]
catatanMebel :: BinTree Int -> [Int]
catatanSusu :: BinTree Int -> [Int]
```

- `catatanDeeper t` menghasilkan list nilai `t` dengan urutan: akar, kiri, kanan (pre-order).
- `catatanMebel t` menghasilkan list nilai `t` dengan urutan: kiri, akar, kanan (in-order).
- `catatanSusu t` menghasilkan list nilai `t` dengan urutan: kiri, kanan, akar (post-order).

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Tidak boleh memakai fungsi `sort` atau fungsi pengurutan lain.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tc:
  1
  |---\
      2
      |---\
          3
          |---\
              4
```

**Contoh aplikasi fungsi:**

```text
> catatanDeeper Empty
[]
> catatanDeeper (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
[2,1,3]
> catatanDeeper (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4,2,1,5,7]
> catatanMebel (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
[1,2,3]
> catatanMebel (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[1,2,4,5,7]
> catatanMebel (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
[1,2,3,4]
> catatanSusu (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
[1,3,2]
> catatanSusu (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[1,2,7,5,4]
> catatanSusu (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
[4,3,2,1]
```

**Penjelasan contoh:**

- Pada `tb`, Deeper mencatat `[4,2,1,5,7]`, Mebel mencatat `[1,2,4,5,7]`, dan Susu mencatat `[1,2,7,5,4]`.
- Ketiga catatan memuat nilai yang sama dengan urutan berbeda. Catatan Susu selalu berakhir dengan nilai akar.

---

## Soal 9: Lipatan Terbalik Paman Stenli

| | |
|---|---|
| **Nama File** | `LipatanTerbalik.hs` |
| **Header** | `module LipatanTerbalik where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Paman Stenli menyimpan barang antik di lemari yang tersusun sebagai pohon terurut: barang bernilai lebih kecil ada di lorong kiri, dan yang lebih besar ada di lorong kanan. Ia ingin memeriksa lemari dari barang termahal ke termurah, sehingga ia butuh sebuah mesin lipat yang memeriksa lorong **kanan** lebih dulu, kemudian ruangan, baru lorong **kiri**. Buatlah mesin tersebut sebagai fungsi **treeFoldRevIn**, lalu gunakan untuk membuat **kTermahal** yang menghasilkan `k` barang termahal.

**Spesifikasi Fungsi:**

```haskell
treeFoldRevIn :: (a -> Int -> a -> a) -> a -> BinTree Int -> a
kTermahal :: Int -> BinTree Int -> [Int]
```

- `treeFoldRevIn f b t` menghasilkan akumulasi nilai pohon `t` dengan fold reverse in-order menggunakan `f` dan basis `b`.
- Urutan proses: subpohon kanan, kemudian akar, dan terakhir subpohon kiri. Fungsi `f` menerima tiga argumen secara berurutan: hasil subpohon kanan, nilai akar, dan hasil subpohon kiri.
- Untuk pohon kosong, hasilnya adalah `b`.
- `kTermahal k t` menghasilkan list berisi `k` nilai terbesar pada pohon terurut `t`, dari yang terbesar ke yang terkecil.
- Jika `t` memiliki kurang dari `k` simpul, semua nilai `t` dikembalikan.
- Prasyarat: `t` adalah pohon terurut (seluruh nilai di kiri < akar < seluruh nilai di kanan).

**Batasan:**

- `0 <= k <= 10000`.
- Banyak simpul pada pohon paling banyak `10000`.
- `kTermahal` wajib memakai `treeFoldRevIn`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7
```

**Contoh aplikasi fungsi:**

```text
> treeFoldRevIn (\r x l -> r ++ [x] ++ l) [] (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
[3,2,1]
> treeFoldRevIn (\r x l -> r ++ [x] ++ l) [] (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[7,5,4,2,1]
> treeFoldRevIn (\r x l -> r + x + l) 0 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
19
> treeFoldRevIn (\r x l -> x : (l ++ r)) [] (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4,2,1,5,7]
> kTermahal 3 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[7,5,4]
> kTermahal 10 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[7,5,4,2,1]
> kTermahal 0 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[]
> kTermahal 2 Empty
[]
```

**Penjelasan contoh:**

- Pada `tb`, fold dengan `r ++ [x] ++ l` memeriksa 7, 5, 4, 2, lalu 1, sehingga hasilnya `[7,5,4,2,1]`.
- Pada contoh terakhir, lambda `\r x l -> x : (l ++ r)` menaruh akar di depan, lalu hasil kiri `l`, lalu hasil kanan `r`, sehingga hasilnya `[4,2,1,5,7]`. Ini menunjukkan bahwa argumen pertama `f` memang hasil subpohon kanan dan argumen ketiga adalah hasil subpohon kiri.
- `kTermahal 3 tb` mengambil tiga nilai pertama dari urutan menurun, yaitu `[7,5,4]`.

---

## Soal 10: Katalog Perpustakaan Bawah Tanah

| | |
|---|---|
| **Nama File** | `KatalogPerpustakaan.hs` |
| **Header** | `module KatalogPerpustakaan where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Menengah |

Di bawah Mystery Shack ada perpustakaan tua yang katalognya berbentuk pohon terurut: kode buku yang lebih kecil dari kode ruangan ada di lorong kiri, dan yang lebih besar ada di lorong kanan. Deeper ingin tahu apakah sebuah kode buku tercatat di katalog, tanpa harus memeriksa semua ruangan. Ia juga ingin tahu kode buku terkecil di katalog. Buatlah fungsi **adaKode** dan **kodeTerkecil**.

**Spesifikasi Fungsi:**

```haskell
adaKode :: Int -> BinTree Int -> Bool
kodeTerkecil :: BinTree Int -> Int
```

- `adaKode x t` bernilai `True` bila `x` merupakan salah satu nilai pada pohon terurut `t`.
- Prasyarat: `t` adalah pohon terurut tanpa nilai kembar.
- Pencarian hanya boleh menelusuri satu sisi pada setiap simpul.
- `kodeTerkecil t` menghasilkan nilai terkecil pada pohon terurut `t`.
- Prasyarat: `t` adalah pohon terurut dan tidak kosong.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`, dan tinggi pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-100000` sampai `100000`.
- Pohon masukan dijamin merupakan pohon terurut tanpa nilai kembar.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> adaKode 7 Empty
False
> adaKode 4 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> adaKode 7 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> adaKode 3 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
False
> adaKode 8 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
False
> kodeTerkecil (Node 7 Empty Empty)
7
> kodeTerkecil (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
1
```

**Penjelasan contoh:**

- Mencari `7` pada `tb`: 7 > 4 sehingga ke kanan, 7 > 5 sehingga ke kanan lagi, lalu ditemukan. Subpohon kiri tidak pernah diperiksa.
- Mencari `3`: 3 < 4 ke kiri, 3 > 2 ke kanan, lalu bertemu pohon kosong sehingga hasilnya `False`.
- `kodeTerkecil tb` terus ke kiri dari 4, ke 2, lalu ke 1, dan berhenti di `1`.

---

## Soal 11: Menyisipkan Buku Baru

| | |
|---|---|
| **Nama File** | `SisipBuku.hs` |
| **Header** | `module SisipBuku where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Menengah |

Setiap kali ada buku baru, Deeper harus menyisipkannya ke katalog pohon terurut tanpa merusak keterurutannya. Buku dengan kode yang sudah tercatat tidak ditambahkan lagi. Kadang Paman Frod juga meminta buku dengan kode terkecil dikeluarkan dari katalog karena buku itu terlalu berbahaya. Buatlah fungsi **sisipBuku** dan **keluarkanTerkecil**.

**Spesifikasi Fungsi:**

```haskell
sisipBuku :: Int -> BinTree Int -> BinTree Int
keluarkanTerkecil :: BinTree Int -> BinTree Int
```

- `sisipBuku x t` menghasilkan pohon terurut yang berisi seluruh nilai `t` beserta `x`.
- Bila `x` sudah ada pada `t`, hasilnya adalah `t`.
- Prasyarat: `t` adalah pohon terurut tanpa nilai kembar.
- `keluarkanTerkecil t` menghasilkan pohon terurut `t` tanpa nilai terkecilnya.
- Prasyarat: `t` adalah pohon terurut dan tidak kosong.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-100000` sampai `100000`.
- Seluruh subpohon yang tidak dilewati harus dipakai kembali utuh pada hasil.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

te:
  5
  |---\
      8

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> sisipBuku 5 Empty
Node 5 Empty Empty
> sisipBuku 6 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 (Node 6 Empty Empty) Empty))
> sisipBuku 4 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
> sisipBuku 0 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 4 (Node 2 (Node 1 (Node 0 Empty Empty) Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
> keluarkanTerkecil (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
Node 4 (Node 2 Empty Empty) (Node 5 Empty (Node 7 Empty Empty))
> keluarkanTerkecil (Node 5 Empty (Node 8 Empty Empty))
Node 8 Empty Empty
> keluarkanTerkecil (Node 7 Empty Empty)
Empty
```

**Penjelasan contoh:**

- `sisipBuku 6 tb`: 6 > 4 ke kanan, 6 > 5 ke kanan, lalu 6 < 7 ke kiri; simpul 6 menjadi anak kiri dari 7.
- `sisipBuku 4 tb` menghasilkan `tb` sendiri karena 4 sudah ada.
- Pada `keluarkanTerkecil te`, akar 5 tidak punya anak kiri, sehingga hasilnya adalah subpohon kanannya saja.

---

## Soal 12: Menyusun Tumpukan Stiker

| | |
|---|---|
| **Nama File** | `TumpukanStiker.hs` |
| **Header** | `module TumpukanStiker where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Menengah |

Mebel punya setumpuk stiker bernomor yang datang satu per satu secara acak, dan nomor yang sama bisa muncul lebih dari sekali. Ia ingin menata stiker-stiker itu ke dalam pohon terurut dengan menyisipkannya sesuai urutan kedatangan (dari kiri ke kanan pada list). Nomor kembar hanya disimpan sekali. Setelah itu, ia ingin membaca kembali seluruh nomor secara menaik. Fungsi penyisipan **sisipStiker** dan **bacaMenaik** sudah disediakan. Buatlah fungsi **susunStiker** dan **urutkanStiker**.

**Spesifikasi Fungsi:**

```haskell
susunStiker :: [Int] -> BinTree Int
urutkanStiker :: [Int] -> [Int]
```

- `susunStiker xs` menghasilkan pohon terurut hasil menyisipkan elemen `xs` satu per satu dari kiri ke kanan ke dalam pohon kosong, memakai `sisipStiker`.
- `urutkanStiker xs` menghasilkan list nomor stiker pada `xs` yang terurut menaik, dengan nomor kembar hanya muncul sekali.

**Batasan:**

- Panjang list paling banyak `10000`.
- Nilai setiap elemen berada pada rentang `-100000` sampai `100000`.
- `urutkanStiker` tidak boleh memakai fungsi `sort` bawaan.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```

**Contoh aplikasi fungsi:**

```text
> susunStiker []
Empty
> susunStiker [3,1,2]
Node 3 (Node 1 Empty (Node 2 Empty Empty)) Empty
> susunStiker [4,2,5,1,7]
Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
> susunStiker [1,2,3]
Node 1 Empty (Node 2 Empty (Node 3 Empty Empty))
> urutkanStiker [5,3,8,3,1,5]
[1,3,5,8]
> urutkanStiker [9]
[9]
> urutkanStiker []
[]
```

**Penjelasan contoh:**

- `susunStiker [3,1,2]`: 3 menjadi akar, 1 ke kiri dari 3, lalu 2 ke kanan dari 1.
- `susunStiker [1,2,3]` menghasilkan pohon yang hanya punya cabang kanan, karena setiap nilai baru lebih besar dari semua nilai sebelumnya.
- `urutkanStiker [5,3,8,3,1,5]` menghasilkan `[1,3,5,8]`; angka 3 dan 5 yang kembar hanya disimpan sekali.

---

## Soal 13: Audit Katalog Paman Frod

| | |
|---|---|
| **Nama File** | `AuditKatalog.hs` |
| **Header** | `module AuditKatalog where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Paman Frod curiga seseorang mengacak-acak katalog perpustakaan pohon terurut. Sebuah pohon dinyatakan valid bila untuk **setiap** simpul, semua nilai di subpohon kirinya lebih kecil daripada nilai simpul itu, dan semua nilai di subpohon kanannya lebih besar. Pemeriksaan yang hanya membandingkan sebuah simpul dengan anak langsungnya tidak cukup. Bantulah Paman Frod dengan membuat fungsi **katalogValid**.

**Spesifikasi Fungsi:**

```haskell
katalogValid :: BinTree Int -> Bool
```

- `katalogValid t` bernilai `True` bila `t` memenuhi invarian pohon terurut: untuk setiap simpul, seluruh nilai di kiri < nilai simpul < seluruh nilai di kanan.
- Pohon kosong dan pohon satu simpul selalu valid.
- Nilai kembar membuat pohon tidak valid.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-100000` sampai `100000`.
- Anda boleh membuat fungsi bantu, tetapi tidak boleh mengimpor modul apa pun.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tf:
      5
  /---|-------\
  3           8
          /---|---\
          4       9

tg:
      2
  /---|
  2

th:
              5
      /-------|---\
      3           8
  /---|---\
  1       6
```

**Contoh aplikasi fungsi:**

```text
> katalogValid Empty
True
> katalogValid (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> katalogValid (Node 5 (Node 3 Empty Empty) (Node 8 (Node 4 Empty Empty) (Node 9 Empty Empty)))
False
> katalogValid (Node 2 (Node 2 Empty Empty) Empty)
False
> katalogValid (Node 5 (Node 3 (Node 1 Empty Empty) (Node 6 Empty Empty)) (Node 8 Empty Empty))
False
```

**Penjelasan contoh:**

- Pada `tf`, simpul 8 sudah benar terhadap anaknya (4 < 8 < 9). Namun 4 berada di subpohon kanan dari 5, padahal 4 < 5, sehingga pohon **tidak** valid.
- Pada `tg`, nilai 2 muncul dua kali (akar dan anak kiri), sehingga tidak valid.
- Pada `th`, simpul 6 berada di subpohon kanan milik 3, tetapi sah terhadap 3. Namun 6 berada di subpohon kiri dari 5 dan 6 > 5, sehingga pohon tidak valid.

---

## Soal 14: Kedalaman Peti Harta Karun

| | |
|---|---|
| **Nama File** | `KedalamanPeti.hs` |
| **Header** | `module KedalamanPeti where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Menengah |

Deeper menemukan sebuah peti harta karun di salah satu ruangan pada labirin berbentuk pohon terurut. Ia ingin tahu rute dari ruangan paling atas menuju ruangan yang menyimpan peti, serta seberapa dalam peti tersebut terkubur. Kedalaman dihitung sebagai banyaknya ruangan yang dilewati, termasuk ruangan paling atas dan ruangan tujuan. Buatlah fungsi **rutePeti** dan **kedalamanPeti**.

**Spesifikasi Fungsi:**

```haskell
rutePeti :: Int -> BinTree Int -> [Int]
kedalamanPeti :: Int -> BinTree Int -> Int
```

- `rutePeti x t` menghasilkan list nilai simpul yang dilewati dari akar sampai simpul bernilai `x` (keduanya ikut ditulis) pada pohon terurut `t`.
- Bila `x` tidak ada pada `t`, hasilnya list kosong.
- Prasyarat: `t` adalah pohon terurut tanpa nilai kembar.
- `kedalamanPeti x t` menghasilkan banyaknya simpul yang dilewati dari akar sampai simpul bernilai `x`, termasuk keduanya.
- Bila `x` tidak ada pada `t`, hasilnya `0`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`, dan tinggi pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-100000` sampai `100000`.
- Pohon masukan dijamin merupakan pohon terurut tanpa nilai kembar.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7
```

**Contoh aplikasi fungsi:**

```text
> rutePeti 4 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4]
> rutePeti 7 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4,5,7]
> rutePeti 1 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4,2,1]
> rutePeti 6 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[]
> rutePeti 3 Empty
[]
> kedalamanPeti 4 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
1
> kedalamanPeti 7 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
3
> kedalamanPeti 6 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
0
```

**Penjelasan contoh:**

- `rutePeti 7 tb` melewati 4, lalu 5, lalu 7, sehingga rutenya `[4,5,7]` dan kedalamannya `3`.
- `rutePeti 4 tb` hanya `[4]` karena peti berada di akar.
- Nilai `6` tidak ada pada `tb`; pencarian berakhir di pohon kosong sehingga rute berupa `[]` dan kedalamannya `0`, bukan rute sebagian.

---

## Soal 15: Keseimbangan Ruang Rahasia

| | |
|---|---|
| **Nama File** | `KeseimbanganRuang.hs` |
| **Header** | `module KeseimbanganRuang where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Paman Stenli khawatir Mystery Shack akan miring karena lorong rahasianya tidak seimbang. Sebuah ruangan dinyatakan **seimbang** bila selisih tinggi lorong kiri dan lorong kanannya paling banyak satu. Seluruh jaringan lorong dinyatakan seimbang bila **setiap** ruangannya seimbang. Selain itu, Paman Stenli ingin mengetahui ada berapa ruangan yang tidak seimbang. Buatlah fungsi **isSeimbang** dan **banyakMiring**.

**Spesifikasi Fungsi:**

```haskell
isSeimbang :: BinTree Int -> Bool
banyakMiring :: BinTree Int -> Int
```

- `isSeimbang t` bernilai `True` bila pada setiap simpul `t`, selisih tinggi subpohon kiri dan subpohon kanan paling banyak `1`.
- Tinggi pohon kosong adalah `0`, dan pohon kosong dianggap seimbang.
- `banyakMiring t` menghasilkan banyaknya simpul pada `t` yang selisih tinggi subpohon kiri dan kanannya lebih dari `1`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `10000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Anda perlu menulis sendiri fungsi bantu untuk tinggi pohon.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tc:
  1
  |---\
      2
      |---\
          3
          |---\
              4
```

**Contoh aplikasi fungsi:**

```text
> isSeimbang Empty
True
> isSeimbang (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> isSeimbang (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
False
> banyakMiring Empty
0
> banyakMiring (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
0
> banyakMiring (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
0
> banyakMiring (Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty))))
2
```

**Penjelasan contoh:**

- Pada `tc`: simpul 1 punya tinggi kiri `0` dan kanan `3` (selisih 3), simpul 2 punya `0` dan `2` (selisih 2), simpul 3 punya `0` dan `1` (selisih 1). Dua simpul tidak seimbang, sehingga `banyakMiring` bernilai `2` dan `isSeimbang` bernilai `False`.
- Pada `tb`, selisih tertinggi hanya `1` (pada simpul 2 dan 5), sehingga pohonnya seimbang.

---

## Soal 16: Jalur Tol Menuju Pintu Keluar

| | |
|---|---|
| **Nama File** | `JalurTol.hs` |
| **Header** | `module JalurTol where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Untuk keluar dari labirin, Deeper harus berjalan dari ruangan paling atas sampai ke sebuah ruangan buntu (daun). Setiap ruangan memungut biaya tol sebesar nomornya. Mebel menuliskan semua jalur yang mungkin dari kiri ke kanan, lalu Deeper ingin tahu apakah ada jalur yang total tolnya **tepat** sama dengan uang yang ia bawa. Buatlah fungsi **semuaJalur** dan **adaJalurTepat**.

**Spesifikasi Fungsi:**

```haskell
semuaJalur :: BinTree Int -> [[Int]]
adaJalurTepat :: Int -> BinTree Int -> Bool
```

- `semuaJalur t` menghasilkan list seluruh jalur dari akar sampai tiap daun pada `t`, diurutkan dari jalur paling kiri.
- Setiap jalur berupa list nilai simpul yang dilewati, dari akar sampai daun. Untuk pohon kosong, hasilnya list kosong.
- `adaJalurTepat s t` bernilai `True` bila terdapat jalur dari akar sampai sebuah **daun** pada `t` yang jumlah nilainya tepat `s`.
- Pohon kosong tidak memiliki jalur sehingga hasilnya `False`.

**Batasan:**

- Banyak simpul pada pohon paling banyak `1000`.
- Nilai setiap simpul berada pada rentang `-100` sampai `100`.
- Jalur harus berakhir di daun; berhenti di simpul yang masih punya anak tidak dihitung.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> semuaJalur Empty
[]
> semuaJalur (Node 7 Empty Empty)
[[7]]
> semuaJalur (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
[[2,1],[2,3]]
> semuaJalur (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[[4,2,1],[4,5,7]]
> adaJalurTepat 7 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> adaJalurTepat 16 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> adaJalurTepat 6 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
False
> adaJalurTepat 0 Empty
False
```

**Penjelasan contoh:**

- Pada `tb` ada dua daun sehingga ada dua jalur: `[4,2,1]` dan `[4,5,7]`, dengan total `7` dan `16`.
- `adaJalurTepat 6 tb` bernilai `False`: memang `4 + 2 = 6`, tetapi simpul 2 bukan daun sehingga jalurnya tidak sah.

---

## Soal 17: Lantai-Lantai Gedung Rahasia

| | |
|---|---|
| **Nama File** | `LantaiGedung.hs` |
| **Header** | `module LantaiGedung where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Gedung rahasia di bawah Nangor Falls memiliki beberapa lantai. Ruangan paling atas berada di lantai 1, anak-anaknya berada di lantai 2, dan seterusnya. Deeper ingin mendata seluruh nomor ruangan pada suatu lantai dari kiri ke kanan. Mebel, di sisi lain, ingin tahu jumlah nomor ruangan pada setiap lantai sejak lantai 1. Buatlah fungsi **isiLantai** dan **jumlahPerLantai**.

**Spesifikasi Fungsi:**

```haskell
isiLantai :: Int -> BinTree Int -> [Int]
jumlahPerLantai :: BinTree Int -> [Int]
```

- `isiLantai k t` menghasilkan list nilai seluruh simpul pada lantai ke-`k` pohon `t`, dari kiri ke kanan. Akar berada di lantai `1`.
- Bila `t` tidak memiliki lantai ke-`k`, hasilnya list kosong.
- `jumlahPerLantai t` menghasilkan list yang elemen ke-`i`-nya adalah jumlah nilai seluruh simpul pada lantai ke-`i`, mulai dari lantai `1` sampai lantai terdalam.
- Untuk pohon kosong, hasilnya list kosong.

**Batasan:**

- Banyak simpul pada pohon paling banyak `1000`.
- `1 <= k <= 1000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tx:
  7
```

**Contoh aplikasi fungsi:**

```text
> isiLantai 1 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4]
> isiLantai 2 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[2,5]
> isiLantai 3 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[1,7]
> isiLantai 4 (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[]
> jumlahPerLantai Empty
[]
> jumlahPerLantai (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
[4,7,8]
> jumlahPerLantai (Node 7 Empty Empty)
[7]
```

**Penjelasan contoh:**

- Pada `tb`: lantai 1 berisi `[4]`, lantai 2 berisi `[2,5]`, dan lantai 3 berisi `[1,7]`. Lantai 4 tidak ada sehingga hasilnya `[]`.
- `jumlahPerLantai tb` adalah `[4, 2+5, 1+7] = [4,7,8]`.

---

## Soal 18: Peta Kembar dan Peta Simetris

| | |
|---|---|
| **Nama File** | `PetaKembar.hs` |
| **Header** | `module PetaKembar where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Deeper dan Mebel memiliki dua peta lorong, dan mereka berdebat apakah kedua peta itu sama persis, baik bentuk maupun nomor ruangannya. Mereka juga penasaran apakah sebuah peta kecil merupakan potongan (upapohon) dari peta yang lebih besar. Terakhir, Paman Frod menantang mereka: apakah sebuah peta bersifat **simetris**, yaitu lorong kirinya merupakan bayangan cermin dari lorong kanannya, lengkap dengan nomor ruangannya? Buatlah fungsi **petaSama**, **petaPotongan**, dan **petaSimetris**.

**Spesifikasi Fungsi:**

```haskell
petaSama :: BinTree Int -> BinTree Int -> Bool
petaPotongan :: BinTree Int -> BinTree Int -> Bool
petaSimetris :: BinTree Int -> Bool
```

- `petaSama t1 t2` bernilai `True` bila `t1` dan `t2` memiliki bentuk dan nilai simpul yang persis sama.
- Fungsi ini harus ditulis secara rekursif, tanpa memakai operator `==` pada pohon.
- `petaPotongan s t` bernilai `True` bila `s` adalah sebuah upapohon dari `t`, yaitu terdapat simpul pada `t` (atau `t` sendiri) yang beserta seluruh keturunannya persis sama dengan `s`.
- Pohon kosong dianggap upapohon dari pohon apa pun.
- `petaSimetris t` bernilai `True` bila subpohon kiri dan kanan `t` saling bercermin, yaitu bentuknya merupakan pencerminan dan nilai simpul yang bersesuaian sama.
- Pohon kosong dianggap simetris.

**Batasan:**

- Banyak simpul pada setiap pohon paling banyak `1000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Tidak boleh memakai operator `==` pada pohon (`BinTree`) pada `petaSama`.

**Pohon yang dipakai pada contoh** (nama pohon dipakai pada penjelasan; pada contoh aplikasi ditulis lengkap):

```text
ta:
      2
  /---|---\
  1       3

tb:
          4
      /---|---\
      2       5
  /---|       |---\
  1               7

tp:
      2
  /---|
  1

ts:
          1
      /---|---\
      2       2
  /---|       |---\
  3               3

tt:
          1
      /---|-------\
      2           2
  /---|       /---|
  3           3

tu:
      1
  /---|---\
  2       2
```

**Contoh aplikasi fungsi:**

```text
> petaSama Empty Empty
True
> petaSama (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
True
> petaSama (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
False
> petaSama (Node 2 (Node 1 Empty Empty) Empty) (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
False
> petaPotongan (Node 2 (Node 1 Empty Empty) Empty) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> petaPotongan (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
False
> petaPotongan Empty (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> petaPotongan (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))) (Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty)))
True
> petaSimetris Empty
True
> petaSimetris (Node 1 (Node 2 Empty Empty) (Node 2 Empty Empty))
True
> petaSimetris (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty))
False
> petaSimetris (Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 2 Empty (Node 3 Empty Empty)))
True
> petaSimetris (Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 2 (Node 3 Empty Empty) Empty))
False
```

**Penjelasan contoh:**

- `tp` adalah simpul 2 yang hanya punya anak kiri 1; `tp` merupakan potongan dari `tb` pada simpul 2.
- Pada `ts`, anak kiri adalah `2` dengan anak kiri `3`, dan anak kanan adalah `2` dengan anak kanan `3`; keduanya saling bercermin sehingga `ts` simetris.
- Pada `tt`, kedua anak sama-sama memiliki anak **kiri** `3`. Bentuknya sama persis, bukan bercermin, sehingga tidak simetris. Pada `ta`, nilai 1 dan 3 berbeda sehingga tidak simetris.

---

## Soal 19: Sandi Aritmetika Paman Frod

| | |
|---|---|
| **Nama File** | `SandiPamanFrod.hs` |
| **Header** | `module SandiPamanFrod where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Paman Frod menyimpan pesan rahasia yang disandikan sebagai pohon ekspresi aritmetika: setiap simpul adalah sebuah bilangan (`Angka`), atau sebuah operator biner (`Op`) beserta operan kiri dan kanannya. Operator yang dipakai adalah `+`, `-`, dan `*`. Deeper harus menghitung nilai pesan tersebut. Selain itu, Mebel ingin menuliskannya dalam notasi prefix dan postfix, dengan setiap lambang dipisahkan oleh tepat satu spasi, agar pesan dapat dikirim lewat telegram.

**Spesifikasi Fungsi:**

```haskell
evaluasi :: Expr -> Int
notasiPrefix :: Expr -> String
notasiPostfix :: Expr -> String
```

- `evaluasi e` menghasilkan nilai ekspresi `e`.
- Sebuah `Angka n` bernilai `n`. Sebuah `Op c l r` bernilai hasil operator `c` terhadap nilai `l` dan nilai `r` (gunakan `applyOp`).
- `notasiPrefix e` menghasilkan penulisan `e` dengan urutan: operator, operan kiri, operan kanan (pre-order), dengan setiap lambang dipisahkan satu spasi, tanpa spasi di awal maupun akhir.
- `notasiPostfix e` menghasilkan penulisan `e` dengan urutan: operan kiri, operan kanan, operator (post-order), dengan setiap lambang dipisahkan satu spasi, tanpa spasi di awal maupun akhir.

**Batasan:**

- Banyak simpul pada pohon ekspresi paling banyak `1000`.
- Bilangan pada `Angka` berada pada rentang `-100` sampai `100`; operator hanya `'+'`, `'-'`, atau `'*'`.
- Seluruh perhitungan aman dari overflow pada batasan di atas.

**Pohon yang dipakai pada contoh:**

```text
e1:
              *
      /-------|---\
      +           5
  /---|---\
  3       4

e2:
      -
  /---|-------\
  2           *
          /---|---\
          3       -4

e3:
  7
```

**Contoh aplikasi fungsi:**

```text
> evaluasi (Angka 7)
7
> evaluasi (Op '*' (Op '+' (Angka 3) (Angka 4)) (Angka 5))
35
> evaluasi (Op '-' (Angka 2) (Op '*' (Angka 3) (Angka (-4))))
14
> notasiPrefix (Angka 7)
"7"
> notasiPrefix (Op '*' (Op '+' (Angka 3) (Angka 4)) (Angka 5))
"* + 3 4 5"
> notasiPrefix (Op '-' (Angka 2) (Op '*' (Angka 3) (Angka (-4))))
"- 2 * 3 -4"
> notasiPostfix (Angka 7)
"7"
> notasiPostfix (Op '*' (Op '+' (Angka 3) (Angka 4)) (Angka 5))
"3 4 + 5 *"
> notasiPostfix (Op '-' (Angka 2) (Op '*' (Angka 3) (Angka (-4))))
"2 3 -4 * -"
```

**Penjelasan contoh:**

- `e1` merepresentasikan `(3 + 4) * 5`: hasilnya `35`, prefix-nya `"* + 3 4 5"`, dan postfix-nya `"3 4 + 5 *"`.
- `e2` merepresentasikan `2 - (3 * (-4))`, yaitu `2 - (-12) = 14`. Bilangan negatif ditulis apa adanya dengan `show`.
- Notasi prefix dan postfix tidak memerlukan kurung karena bentuk pohonnya sudah menentukan pengelompokan.

---

## Soal 20: Arsip Bercabang Mystery Shack

| | |
|---|---|
| **Nama File** | `ArsipBercabang.hs` |
| **Header** | `module ArsipBercabang where` |
| **Time limit** | 1 s |
| **Memory limit** | 64 MB |
| **Level** | Sulit |

Arsip rahasia Mystery Shack disusun seperti struktur folder: setiap berkas memiliki sebuah nomor, dan di dalamnya dapat tersimpan **sejumlah berapa pun** berkas lain (dapat nol). Berkas yang tidak menyimpan berkas lain disebut berkas ujung. Susu diminta menghitung banyaknya seluruh berkas, kedalaman penyimpanan terdalam, dan mendaftar seluruh nomor berkas ujung dari kiri ke kanan. Karena sebuah berkas menyimpan *list* berkas, Anda perlu memakai rekursi tidak langsung atau fungsi `map`.

**Spesifikasi Fungsi:**

```haskell
banyakBerkas :: Tree -> Int
kedalamanArsip :: Tree -> Int
berkasUjung :: Tree -> [Int]
```

- `banyakBerkas t` menghasilkan banyaknya simpul pada `t`, termasuk akarnya.
- `kedalamanArsip t` menghasilkan banyaknya simpul pada jalur terpanjang dari akar sampai sebuah daun.
- Sebuah simpul tanpa anak memiliki kedalaman `1`.
- `berkasUjung t` menghasilkan list nilai seluruh daun pada `t`, dari kiri ke kanan.

**Batasan:**

- Banyak simpul pada pohon paling banyak `1000`.
- Nilai setiap simpul berada pada rentang `-1000` sampai `1000`.
- Tidak ada pohon kosong; list anak boleh kosong.

**Pohon yang dipakai pada contoh:**

```text
f1:
  1
  |-- 2
  |-- 3
  |   |-- 5
  |   `-- 6
  `-- 4

f2:
  9

f3:
  1
  `-- 2
      `-- 3
          `-- 4
```

**Contoh aplikasi fungsi:**

```text
> banyakBerkas (Node 9 [])
1
> banyakBerkas (Node 1 [Node 2 [], Node 3 [Node 5 [], Node 6 []], Node 4 []])
6
> banyakBerkas (Node 1 [Node 2 [Node 3 [Node 4 []]]])
4
> kedalamanArsip (Node 9 [])
1
> kedalamanArsip (Node 1 [Node 2 [], Node 3 [Node 5 [], Node 6 []], Node 4 []])
3
> kedalamanArsip (Node 1 [Node 2 [Node 3 [Node 4 []]]])
4
> berkasUjung (Node 9 [])
[9]
> berkasUjung (Node 1 [Node 2 [], Node 3 [Node 5 [], Node 6 []], Node 4 []])
[2,5,6,4]
> berkasUjung (Node 1 [Node 2 [Node 3 [Node 4 []]]])
[4]
```

**Penjelasan contoh:**

- Pada `f1` terdapat simpul 1, 2, 3, 4, 5, dan 6, sehingga `banyakBerkas` bernilai `6`.
- Jalur terpanjang pada `f1` adalah 1-3-5 (atau 1-3-6), yaitu `3` simpul. Daunnya, dari kiri ke kanan, adalah 2, 5, 6, dan 4.
- `f3` hanya berupa satu rantai 1-2-3-4: banyak berkasnya `4`, kedalamannya `4`, dan satu-satunya berkas ujung adalah `[4]`.

