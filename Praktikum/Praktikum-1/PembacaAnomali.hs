module PembacaAnomali where

-- PEMBACA ANOMALI
-- DEFINISI DAN SPESIFIKASI
skorAnomali :: Int -> Int -> Int -> Int -> Float
-- skorAnomali a b c d menghasilkan rata-rata dua nilai tengah
-- setelah satu nilai terbesar dan satu nilai terkecil diabaikan

maks2 :: Int -> Int -> Int
-- maks2 a b menghasilkan nilai terbesar di antara a dan b

min2 :: Int -> Int -> Int
-- min2 a b menghasilkan nilai terkecil di antara a dan b

maks4 :: Int -> Int -> Int -> Int -> Int
-- maks4 a b c d menghasilkan nilai terbesar di antara a, b, c, dan d

min4 :: Int -> Int -> Int -> Int -> Int
-- min4 a b c d menghasilkan nilai terkecil di antara a, b, c, dan d

-- REALISASI
maks2 a b = if a > b then a else b

min2 a b = if a < b then a else b

maks4 a b c d = maks2 (maks2 a b) (maks2 c d)

min4 a b c d = min2 (min2 a b) (min2 c d)

skorAnomali a b c d = fromIntegral(a + b + c + d - (maks4 a b c d) - (min4 a b c d)) / 2

-- APLIKASI
-- skorAnomali 7 9 6 9