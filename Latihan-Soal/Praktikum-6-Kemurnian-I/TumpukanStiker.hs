module TumpukanStiker where

-- DEFINISI DATA STRUKTUR
-- Binary Tree dengan konstruktor Node dan Empty
data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
-- Definisi dan Spesifikasi utama
akar  :: BinTree Int -> Int
left  :: BinTree Int -> BinTree Int
right :: BinTree Int -> BinTree Int

-- Realisasi
akar Empty          = error "akar: pohon kosong tidak punya akar"
akar (Node v _ _)   = v

left Empty          = error "left: pohon kosong tidak punya subpohon kiri"
left (Node _ l _)   = l

right Empty         = error "right: pohon kosong tidak punya subpohon kanan"
right (Node _ _ r)  = r

-- PREDIKAT
-- Definisi dan Spesifikasi utama
isTreeEmpty  :: BinTree a -> Bool
isOneElmt    :: BinTree a -> Bool
isExistLeft  :: BinTree a -> Bool
isExistRight :: BinTree a -> Bool
isUnerLeft   :: BinTree a -> Bool
isUnerRight  :: BinTree a -> Bool
isBiner      :: BinTree a -> Bool

-- Realisasi
isTreeEmpty Empty                = True
isTreeEmpty _                    = False

isOneElmt (Node _ Empty Empty)   = True
isOneElmt _                      = False

isExistLeft (Node _ l _)         = not (isTreeEmpty l)
isExistLeft _                    = False

isExistRight (Node _ _ r)        = not (isTreeEmpty r)
isExistRight _                   = False

isUnerLeft (Node _ l r)          = not (isTreeEmpty l) && isTreeEmpty r
isUnerLeft _                     = False

isUnerRight (Node _ l r)         = isTreeEmpty l && not (isTreeEmpty r)
isUnerRight _                    = False

isBiner (Node _ l r)             = not (isTreeEmpty l) && not (isTreeEmpty r)
isBiner _                        = False

-- FUNGSI YANG SUDAH DISEDIAKAN (tidak perlu diubah)
-- sisipStiker x t menyisipkan x ke pohon terurut t (nilai kembar diabaikan)
sisipStiker :: Int -> BinTree Int -> BinTree Int
sisipStiker x Empty = Node x Empty Empty
sisipStiker x t@(Node v l r)
    | x < v = Node v (sisipStiker x l) r
    | x > v = Node v l (sisipStiker x r)
    | otherwise = t

-- bacaMenaik t menghasilkan nilai t dengan urutan in-order
bacaMenaik :: BinTree Int -> [Int]
bacaMenaik Empty = []
bacaMenaik (Node v l r) = bacaMenaik l ++ [v] ++ bacaMenaik r

-- BENTUK POHON UJI COBA

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)

-- SPESIFIKASI
-- susunStiker xs menghasilkan pohon terurut hasil menyisipkan elemen xs satu per satu dari kiri ke kanan ke dalam pohon kosong, memakai sisipStiker.
-- Contoh:
--   susunStiker [] == Empty
--   susunStiker [3,1,2] == Node 3 (Node 1 Empty (Node 2 Empty Empty)) Empty
--   susunStiker [4,2,5,1,7] == Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
--   susunStiker [1,2,3] == Node 1 Empty (Node 2 Empty (Node 3 Empty Empty))
-- TODO: Lengkapi fungsi sesuai spesifikasi.
susunStiker :: [Int] -> BinTree Int
susunStiker xs = error "TODO"

-- SPESIFIKASI
-- urutkanStiker xs menghasilkan list nomor stiker pada xs yang terurut menaik, dengan nomor kembar hanya muncul sekali.
-- Contoh:
--   urutkanStiker [5,3,8,3,1,5] == [1,3,5,8]
--   urutkanStiker [9] == [9]
--   urutkanStiker [] == []
-- TODO: Lengkapi fungsi sesuai spesifikasi.
urutkanStiker :: [Int] -> [Int]
urutkanStiker xs = error "TODO"
