-- Deskripsi:
-- Fungsi `dualTransform` menerima sebuah tuple yang berisi satu kondisi dan 
-- dua fungsi transformasi, serta sebuah list. 
-- Jika elemen memenuhi kondisi, ubah menggunakan transformasi pertama.
-- Jika tidak memenuhi kondisi, ubah menggunakan transformasi kedua.
--
-- Contoh:
-- dualTransform (\x -> x > 0, \x -> x * 2, \x -> x * (-1)) [2, -3, 4] => [4, 3, 8]

isEmpty :: [a] -> Bool
isEmpty li = null li

dualTransform :: (a -> Bool, a -> b, a -> b) -> [a] -> [b]
dualTransform (cond, trans1, trans2) li
    | isEmpty li = []
    | otherwise = 
        if cond (head li) then trans1 (head li) : dualTransform (cond, trans1, trans2) (tail li)
        else trans2 (head li) : dualTransform (cond, trans1, trans2) (tail li)

-- APLIKASI
-- Data sensor atau transaksi keuangan mentah
dataMentah :: [Int]
dataMentah = [5, -2, 10, 0, -8]

-- Menjalankan dualTransform
-- Jika x > 0 kalikan 2, jika tidak kalikan -1
hasilNormalisasi :: [Int]
hasilNormalisasi = dualTransform (\x -> x > 0, \x -> x * 2, \x -> x * (-1)) dataMentah
-- Output: [10, 2, 20, 0, 8]