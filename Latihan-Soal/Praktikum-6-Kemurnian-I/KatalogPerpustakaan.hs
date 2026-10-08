module KatalogPerpustakaan where

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
--   tx:
--     7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tx :: BinTree Int
tx = Node 7 Empty Empty

-- SPESIFIKASI
-- adaKode x t bernilai True bila x merupakan salah satu nilai pada pohon terurut t.
-- Prasyarat: t adalah pohon terurut tanpa nilai kembar.
-- Pencarian hanya boleh menelusuri satu sisi pada setiap simpul.
-- Contoh:
--   adaKode 7 Empty == False
--   adaKode 4 tb == True
--   adaKode 7 tb == True
--   adaKode 3 tb == False
--   adaKode 8 tb == False
-- TODO: Lengkapi fungsi sesuai spesifikasi.
adaKode :: Int -> BinTree Int -> Bool
adaKode _ Empty = False
adaKode x (Node a l r) = (x == a) || (adaKode x l) || (adaKode x r)

-- SPESIFIKASI
-- kodeTerkecil t menghasilkan nilai terkecil pada pohon terurut t.
-- Prasyarat: t adalah pohon terurut dan tidak kosong.
-- Contoh:
--   kodeTerkecil tx == 7
--   kodeTerkecil tb == 1
-- TODO: Lengkapi fungsi sesuai spesifikasi.
kodeTerkecil :: BinTree Int -> Int
kodeTerkecil Empty = 9999
kodeTerkecil (Node a Empty Empty) = a
kodeTerkecil (Node a l r) = min a (min (kodeTerkecil l) (kodeTerkecil r))
