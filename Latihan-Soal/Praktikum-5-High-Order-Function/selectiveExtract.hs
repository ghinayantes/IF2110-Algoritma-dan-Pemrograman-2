-- Deskripsi:
-- Fungsi `selectiveExtract` menerima pasangan kondisi dan fungsi transformasi.
-- Fungsi ini hanya akan "mengambil" elemen yang memenuhi kondisi, kemudian
-- mengubah elemen tersebut menggunakan fungsi transformasi. 
-- Elemen yang tidak memenuhi kondisi akan dibuang dari list hasil.
--
-- Contoh (Ambil yang genap, lalu kuadratkan):
-- selectiveExtract (\x -> mod x 2 == 0, \x -> x ^ 2) [1, 2, 3, 4, 5] => [4, 16]

isEmpty :: [a] -> Bool
isEmpty li = null li

selectiveExtract :: (a -> Bool, a -> b) -> [a] -> [b]
selectiveExtract (cond, transform) li
    | isEmpty li = []
    | otherwise =
        if cond (head li) then transform (head li) : selectiveExtract (cond, transform) (tail li)
        else selectiveExtract (cond, transform) (tail li)

-- APLIKASI
-- Daftar harga produk mentah di keranjang (dalam Rupiah)
hargaProduk :: [Float]
hargaProduk = [35000, 120000, 50000, 75000, 20000]

-- Menjalankan selectiveExtract
-- Syarat: Harga > 50000. Transformasi: Harga dikali 0.9 (diskon 10%).
hasilDiskon = selectiveExtract (\x -> x > 50000, \x -> x * 0.9) hargaProduk

-- Penjelasan Alur:
-- 1. 35000 (Tidak > 50000) -> Dibuang (di-skip)
-- 2. 120000 (> 50000) -> Diambil dan diubah menjadi 108000.0
-- 3. 50000 (Tidak > 50000, karena syaratnya harus lebih besar) -> Dibuang
-- 4. 75000 (> 50000) -> Diambil dan diubah menjadi 67500.0
-- 5. 20000 (Tidak > 50000) -> Dibuang
-- Output: [108000.0, 67500.0]