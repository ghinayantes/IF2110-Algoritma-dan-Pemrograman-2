module KedalamanPeti where

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

-- BENTUK POHON UJI COBA
--   tb:
--             4
--         /---|---\
--         2       5
--     /---|       |---\
--     1               7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))

-- SPESIFIKASI
-- rutePeti x t menghasilkan list nilai simpul yang dilewati dari akar sampai simpul bernilai x (keduanya ikut ditulis) pada pohon terurut t.
-- Bila x tidak ada pada t, hasilnya list kosong.
-- Prasyarat: t adalah pohon terurut tanpa nilai kembar.
-- Contoh:
--   rutePeti 4 tb == [4]
--   rutePeti 7 tb == [4,5,7]
--   rutePeti 1 tb == [4,2,1]
--   rutePeti 6 tb == []
--   rutePeti 3 Empty == []
-- TODO: Lengkapi fungsi sesuai spesifikasi.
rutePeti :: Int -> BinTree Int -> [Int]
rutePeti x t = error "TODO"

-- SPESIFIKASI
-- kedalamanPeti x t menghasilkan banyaknya simpul yang dilewati dari akar sampai simpul bernilai x, termasuk keduanya.
-- Bila x tidak ada pada t, hasilnya 0.
-- Contoh:
--   kedalamanPeti 4 tb == 1
--   kedalamanPeti 7 tb == 3
--   kedalamanPeti 6 tb == 0
-- TODO: Lengkapi fungsi sesuai spesifikasi.
kedalamanPeti :: Int -> BinTree Int -> Int
kedalamanPeti x t = error "TODO"
