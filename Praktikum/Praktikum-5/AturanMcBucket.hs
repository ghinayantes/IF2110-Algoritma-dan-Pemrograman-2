module AturanMcBucket where

-- ATURAN MCBUCKET
-- DEFINISI DAN SPESIFIKASI
buatEnkripsi :: [(Int -> Bool, Int -> Int)] -> (Int -> Int)
-- buatEnkripsi aturan menghasilkan sebuah FUNGSI enkripsi. 
-- Fungsi enkripsi tersebut akan memproses sebuah integer melalui 
-- serangkaian modifikasi berdasarkan aturan yang diberikan secara berurutan.
-- Jika aturan kosong atau tidak ada predikat yang terpenuhi, nilai tetap sama.

-- Definisikan beberapa aturan
-- aturan1 = (\x -> x > 10, \x -> x - 5)
-- aturan2 = (\x -> mod x 2 == 0, \x -> x * 10)
-- REALISASI

buatEnkripsi [] x = x
buatEnkripsi ((p, f) : xs) x
  | p x       = buatEnkripsi xs (f x)  -- Efek f diterapkan ke x, lalu hasilnya diteruskan ke sisa aturan (xs)
  | otherwise = buatEnkripsi xs x    -- Nilai x tidak berubah, diteruskan ke sisa aturan (xs)

-- APLIKASI
-- Definisikan beberapa aturan
aturan1 :: (Int -> Bool, Int -> Int)
aturan1 = (\x -> x > 10, \x -> x - 5)
aturan2 :: (Int -> Bool, Int -> Int)
aturan2 = (\x -> mod x 2 == 0, \x -> x * 10)
listAturan :: [(Int -> Bool, Int -> Int)]
listAturan = [aturan1, aturan2]

-- Buat fungsi enkripsinya
enkripsiA :: Int -> Int
enkripsiA = buatEnkripsi listAturan

-- Gunakan fungsi yang baru saja dibuat
-- enkripsiA 12
-- 7
-- Penjelasan proses 12: 
-- aturan1: 12 > 10 (True) -> 12 - 5 = 7. Nilai memori sekarang 7.
-- aturan2: 7 genap? (False) -> Nilai tetap 7. Hasil akhir 7.