module PosisiAnomali where

-- POSISI ANOMALI
-- DEFINISI TYPE
data Point = Pt Int Int
    deriving (Show, Read)
-- Tuliskan definisi tipe Point dengan konstruktor Pt dan dua komponen Int.
-- Tambahkan deriving (Show, Read).
-- Lengkapi definisi tipe terlebih dahulu agar file dapat dimuat di GHCi.

-- DEFINISI DAN SPESIFIKASI
posisiTitik :: Point -> Int
-- posisiTitik p menghasilkan kode posisi titik p sesuai aturan pada soal.

-- REALISASI
posisiTitik (Pt x y)
    | (x == 0) && (y == 0) = 0
    | (x > 0) && (y > 0) = 1
    | (x < 0) && (y > 0) = 2
    | (x <  0) && (y < 0) = 3
    | (x > 0) && (y < 0) = 4
    | (x > 0) || (x < 0) && (y == 0) = 5
    | otherwise = 6

-- APLIKASI
-- posisiTitik (Pt 5 5)
