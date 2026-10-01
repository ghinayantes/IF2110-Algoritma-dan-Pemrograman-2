module BarisanGnome where

-- BARISAN GNOME
-- Soal ini dirancang agar dapat diselesaikan dengan fungsi fold (foldr) bawaan Haskell.
-- DEFINISI DAN SPESIFIKASI
gnomeTerlihat :: [Integer] -> [Integer]
-- gnomeTerlihat l menerima list tinggi gnome l yang berbaris dari kiri ke kanan.
-- Deeper berdiri di ujung paling kanan barisan dan menghadap ke kiri.
-- Sebuah gnome terlihat oleh Deeper JIKA DAN HANYA JIKA gnome tersebut lebih tinggi (>) dari semua gnome yang berada di sebelah kanannya.
-- gnomeTerlihat l menghasilkan list tinggi gnome yang terlihat, dengan mempertahankan urutan pada l.
-- Gnome paling kanan selalu terlihat. Jika l kosong, hasilnya adalah list kosong.

-- REALISASI
gnomeTerlihat [] = []
gnomeTerlihat l = foldr f [] l -- foldr membuat list dari kanan
  where
    f x [] = [x]
    f x (m:ms)
      | x > m     = x : m : ms
      | otherwise = m : ms

-- APLIKASI
-- > gnomeTerlihat [16,17,4,3,5,2]
-- [17,5,2]
-- Penjelasan:
-- - 2 terlihat karena tidak ada gnome di sebelah kanannya.
-- - 5 terlihat karena 5 > 2.
-- - 3 dan 4 tidak terlihat karena keduanya tidak lebih tinggi dari 5.
-- - 17 terlihat karena 17 lebih tinggi dari 4, 3, 5, dan 2.
-- - 16 tidak terlihat karena tidak lebih tinggi dari 17.
--
-- > gnomeTerlihat [5,5]
-- [5]
-- Penjelasan:
-- - Gnome kedua terlihat.
-- - Gnome pertama tidak terlihat karena tingginya sama dengan gnome kedua (tidak lebih tinggi).
--
-- > gnomeTerlihat [1,2,3,4,5]
-- [5]
-- Penjelasan:
-- - Hanya gnome paling kanan yang terlihat karena masing-masing gnome lainnya dihalangi gnome yang lebih tinggi di kanannya.
--
-- > gnomeTerlihat [5,4,3,2,1]
-- [5,4,3,2,1]
-- Penjelasan:
-- - Setiap gnome lebih tinggi dari semua gnome di kanannya sehingga semuanya terlihat.
--
-- > gnomeTerlihat []
-- []
-- Penjelasan:
-- - Barisan kosong sehingga tidak ada gnome yang terlihat.

-- Rekursi langsung tetap boleh, tetapi disarankan memakai foldr
-- agar kamu dapat mempraktikkan penggunaan fungsi tersebut :)