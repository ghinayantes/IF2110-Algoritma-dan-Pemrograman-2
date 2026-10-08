module ArsipBercabang where

-- DEFINISI DATA STRUKTUR
-- Pohon n-aire: sebuah simpul berisi nilai beserta list anak-anaknya.
-- Tidak ada pohon kosong; sebuah daun adalah simpul dengan list anak kosong.
data Tree = Node Int [Tree]
  deriving (Show, Eq)

-- KONSTRUKTOR
makeTree :: Int -> [Tree] -> Tree
makeTree a fs = Node a fs

-- SELEKTOR
info :: Tree -> Int
info (Node a _) = a

children :: Tree -> [Tree]
children (Node _ fs) = fs

-- PREDIKAT
isLeaf :: Tree -> Bool
isLeaf (Node _ []) = True
isLeaf _           = False

-- BENTUK POHON UJI COBA
--   f1:
--     1
--     |-- 2
--     |-- 3
--     |   |-- 5
--     |   `-- 6
--     `-- 4
--   f2:
--     9
--   f3:
--     1
--     `-- 2
--         `-- 3
--             `-- 4

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
f1 :: Tree
f1 = Node 1 [Node 2 [], Node 3 [Node 5 [], Node 6 []], Node 4 []]
f2 :: Tree
f2 = Node 9 []
f3 :: Tree
f3 = Node 1 [Node 2 [Node 3 [Node 4 []]]]

-- SPESIFIKASI
-- banyakBerkas t menghasilkan banyaknya simpul pada t, termasuk akarnya.
-- Contoh:
--   banyakBerkas f2 == 1
--   banyakBerkas f1 == 6
--   banyakBerkas f3 == 4
-- TODO: Lengkapi fungsi sesuai spesifikasi.
banyakBerkas :: Tree -> Int
banyakBerkas t = error "TODO"

-- SPESIFIKASI
-- kedalamanArsip t menghasilkan banyaknya simpul pada jalur terpanjang dari akar sampai sebuah daun.
-- Sebuah simpul tanpa anak memiliki kedalaman 1.
-- Contoh:
--   kedalamanArsip f2 == 1
--   kedalamanArsip f1 == 3
--   kedalamanArsip f3 == 4
-- TODO: Lengkapi fungsi sesuai spesifikasi.
kedalamanArsip :: Tree -> Int
kedalamanArsip t = error "TODO"

-- SPESIFIKASI
-- berkasUjung t menghasilkan list nilai seluruh daun pada t, dari kiri ke kanan.
-- Contoh:
--   berkasUjung f2 == [9]
--   berkasUjung f1 == [2,5,6,4]
--   berkasUjung f3 == [4]
-- TODO: Lengkapi fungsi sesuai spesifikasi.
berkasUjung :: Tree -> [Int]
berkasUjung t = error "TODO"
