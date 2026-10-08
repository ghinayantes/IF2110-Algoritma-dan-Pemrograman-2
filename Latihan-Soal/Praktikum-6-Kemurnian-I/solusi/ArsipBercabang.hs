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


-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
f1 :: Tree
f1 = Node 1 [Node 2 [], Node 3 [Node 5 [], Node 6 []], Node 4 []]
f2 :: Tree
f2 = Node 9 []
f3 :: Tree
f3 = Node 1 [Node 2 [Node 3 [Node 4 []]]]

-- banyakBerkas
banyakBerkas :: Tree -> Int
banyakBerkas (Node _ fs) = 1 + sum (map banyakBerkas fs)

-- kedalamanArsip
kedalamanArsip :: Tree -> Int
kedalamanArsip (Node _ []) = 1
kedalamanArsip (Node _ fs) = 1 + maximum (map kedalamanArsip fs)

-- berkasUjung
berkasUjung :: Tree -> [Int]
berkasUjung (Node v []) = [v]
berkasUjung (Node _ fs) = concatMap berkasUjung fs
