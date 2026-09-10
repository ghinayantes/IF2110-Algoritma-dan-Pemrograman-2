module KonversiWaktu where

-- KONVERSI WAKTU
-- DEFINISI TYPE
data Jam = Jm Int Int Int
    deriving (Show, Read)

-- Tuliskan definisi tipe Jam dengan konstruktor Jm untuk jam, menit, dan detik.
-- Tambahkan deriving (Show, Read).
-- Lengkapi definisi tipe terlebih dahulu agar file dapat dimuat di GHCi.

-- konstruktor
makeJam :: Int -> Int -> Int -> Jam
makeJam j m d = (Jm j m d)

-- selektor
jam :: Jam -> Int
min :: Jam -> Int
det :: Jam -> Int

jam (Jm j _ _) = j
min (Jm _ m _) = m
det (Jm _ _ d ) = d

-- DEFINISI DAN SPESIFIKASI
detikKeJam :: Int -> Jam
-- detikKeJam total mengonversi detik menjadi Jam dalam siklus 24 jam.

-- helper
keJam :: Int -> Int
keMen :: Int -> Int
keDet :: Int -> Int

keJam x = x `div` 3600
keMen x = (x - (keJam x) * 3600) `div` 60
keDet x = x `mod` 60

-- REALISASI
detikKeJam total = Jm ((keJam total) `mod` 24) (keMen total) (keDet total)

-- APLIKASI
-- detikKeJam 3665