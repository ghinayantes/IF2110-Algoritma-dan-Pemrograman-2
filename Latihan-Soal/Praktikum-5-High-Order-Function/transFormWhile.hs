-- Deskripsi:
-- Fungsi `transformWhile` menerima pasangan kondisi dan fungsi transformasi, 
-- serta sebuah list.
-- Fungsi ini akan terus menerapkan transformasi pada elemen list dari depan, 
-- SELAMA elemen tersebut memenuhi kondisi. 
-- Begitu menemukan elemen yang TIDAK memenuhi kondisi, proses transformasi 
-- dihentikan, dan elemen tersebut beserta sisa list di belakangnya dibiarkan tetap (tidak diubah).
--
-- Contoh:
-- transformWhile (\x -> x < 5, \x -> x * 10) [1, 3, 7, 2, 4] => [10, 30, 7, 2, 4]

isEmpty :: [a] -> Bool
isEmpty li = null li

transformWhile :: (a -> Bool, a -> a) -> [a] -> [a]
transformWhile (cond, transform) li
    | isEmpty li = []
    | otherwise =
        if cond (head li) then transform (head li) : transformWhile (cond, transform) (tail li)
        else li

-- APLIKASI
-- Data antrean nilai/skor mentah yang masuk ke sistem
antreanSkor :: [Int]
antreanSkor = [2, 4, 7, 3, 1]

-- Menjalankan transformWhile
-- Selama x < 5, kalikan skor dengan 10. Jika ketemu >= 5, berhenti ubah dan biarkan sisa list asli.
hasilProses = transformWhile (\x -> x < 5, \x -> x * 10) antreanSkor

-- Penjelasan Alur:
-- 1. Angka 2 (< 5) -> diubah jadi 20
-- 2. Angka 4 (< 5) -> diubah jadi 40
-- 3. Angka 7 (TIDAK < 5) -> Kondisi gagal! Proses berhenti total di sini.
-- 4. Sisa list [3, 1] dibiarkan utuh tanpa diubah.
-- Output: [20, 40, 7, 3, 1]