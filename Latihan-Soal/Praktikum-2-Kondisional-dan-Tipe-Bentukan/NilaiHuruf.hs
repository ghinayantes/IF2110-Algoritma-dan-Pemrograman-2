module NilaiHuruf where

-- Sebuah mata kuliah mengubah nilai angka (0..100) menjadi nilai huruf
-- dengan ketentuan berikut:
--   nilai >= 85            : 'A'
--   70 <= nilai < 85        : 'B'
--   55 <= nilai < 70        : 'C'
--   40 <= nilai < 55        : 'D'
--   nilai < 40              : 'E'
--
-- Contoh: nilaiHuruf 90 = 'A'
-- Contoh: nilaiHuruf 85 = 'A'
-- Contoh: nilaiHuruf 84 = 'B'
-- Contoh: nilaiHuruf 40 = 'D'
-- Contoh: nilaiHuruf 39 = 'E'

-- DEFINISI DAN SPESIFIKASI UTAMA
-- nilaiHuruf: Int -> Char
-- {nilaiHuruf(n) memberikan nilai huruf untuk nilai angka n.
--  Prasyarat: 0 <= n <= 100}
nilaiHuruf :: Int -> Char
nilaiHuruf n 
    | (n >= 85) = 'A'
    | (n >= 70) = 'B'
    | (n >= 55) = 'C'
    | (n >= 40) = 'D'
    | otherwise = 'E'