module Segitiga where

-- Diberikan panjang tiga sisi segitiga a, b, c (bilangan bulat positif).
-- Tugasmu adalah menentukan jenis segitiganya:
--   "Bukan segitiga" - bila ketiganya tidak dapat membentuk segitiga
--                       (jumlah dua sisi terpendek harus lebih besar
--                        daripada sisi terpanjang)
--   "Sama sisi"       - bila ketiga sisi sama panjang
--   "Sama kaki"       - bila tepat dua sisi sama panjang
--   "Sembarang"       - bila ketiga sisi berbeda panjang, dan valid
--                        sebagai segitiga
--
-- Contoh: jenisSegitiga 1 2 3   = "Bukan segitiga"  (1+2 tidak > 3)
-- Contoh: jenisSegitiga 5 5 5   = "Sama sisi"
-- Contoh: jenisSegitiga 5 5 8   = "Sama kaki"
-- Contoh: jenisSegitiga 4 5 6   = "Sembarang"

-- DEFINISI DAN SPESIFIKASI UTAMA
-- jenisSegitiga: Int -> Int -> Int -> String
-- {jenisSegitiga(a,b,c) menentukan jenis segitiga dari sisi a, b, c.
--  Prasyarat: a > 0, b > 0, c > 0}
jenisSegitiga :: Int -> Int -> Int -> String
jenisSegitiga a b c 
    | (a + b <= c) || (a + c <= b) || (c + b <= a) = "Bukan segitiga"
    | (a == b ) && (b == c) = "Sama sisi"
    | (a == b) || (b == c) || (a == c) = "Sama kaki"
    | otherwise = "Sembarang"