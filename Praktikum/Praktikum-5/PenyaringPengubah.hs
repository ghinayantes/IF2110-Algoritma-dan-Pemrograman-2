module PenyaringPengubah where

-- TERMINAL PENGOLAH DATA
-- Soal ini dirancang agar dapat diselesaikan dengan fungsi map dan filter bawaan Haskell.


-- HASIL OLAH
-- DEFINISI DAN SPESIFIKASI
hasilOlah :: [Integer] -> (Integer -> Bool) -> (Integer -> Integer) -> [Integer]
-- hasilOlah l p f menghasilkan list yang berisi hasil transformasi f dari setiap elemen l yang memenuhi kriteria p.
-- Urutan elemen pada hasil sama dengan urutan elemen pada l.

-- REALISASI
hasilOlah l p f = 
    let olah = filter (\o -> p o) l
    in map f olah

-- APLIKASI
-- > hasilOlah [1,2,3,4,5] (\x -> x > 2) (\x -> x * 10)
-- [30,40,50]
-- Penjelasan:
-- - 1 dan 2 tidak memenuhi kriteria x > 2, sehingga diabaikan.
-- - 3, 4, dan 5 memenuhi kriteria, lalu masing-masing diubah menjadi 30, 40, dan 50.
--
-- > hasilOlah [-3,-2,-1,0,1,2] (\x -> x `mod` 2 == 0) (\x -> x + 5)
-- [3,5,7]
-- Penjelasan:
-- - -2, 0, dan 2 memenuhi kriteria bilangan genap.
-- - -2 diubah menjadi 3, 0 diubah menjadi 5, dan 2 diubah menjadi 7.
--
-- > hasilOlah [10,20,30] (\x -> x > 100) (\x -> x * x)
-- []
-- Penjelasan:
-- - Tidak ada elemen yang memenuhi kriteria x > 100.
--
-- > hasilOlah [] (\x -> x > 0) (\x -> x + 1)
-- []
-- Penjelasan:
-- - List masukan kosong sehingga tidak ada elemen yang diproses.


-- CATATAN BERSIH
-- DEFINISI DAN SPESIFIKASI
catatanBersih :: [[Integer]] -> [[Integer]]
-- catatanBersih m menerima list of list m, dengan setiap baris menyatakan sinyal dalam satu hari.
-- catatanBersih m menghasilkan list of list yang setiap barisnya hanya berisi angka yang lebih besar dari 0,
-- sedangkan baris yang menjadi kosong tidak disertakan.
-- Urutan baris dan urutan angka pada hasil sama dengan urutan pada m.

-- REALISASI
catatanBersih m = filter (/= []) [filter (\x -> x > 0) y | y <- (filter (\l -> l /= []) m)]

-- APLIKASI
-- > catatanBersih [[1,-2,3],[-4,-5],[6]]
-- [[1,3],[6]]
-- Penjelasan:
-- - Baris pertama menjadi [1,3] dan baris ketiga tetap [6].
-- - Baris kedua menjadi kosong sehingga dibuang.
--