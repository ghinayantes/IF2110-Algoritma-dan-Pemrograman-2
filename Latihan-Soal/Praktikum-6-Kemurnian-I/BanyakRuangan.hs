module BanyakRuangan where

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
--   ta:
--         2
--     /---|---\
--     1       3
--   tb:
--             4
--         /---|---\
--         2       5
--     /---|       |---\
--     1               7
--   tx:
--     7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
ta :: BinTree Int
ta = Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tx :: BinTree Int
tx = Node 7 Empty Empty

-- SPESIFIKASI
-- banyakRuangan t menghasilkan banyaknya simpul (ruangan) pada pohon t.
-- Pohon kosong tidak memiliki ruangan, sehingga hasilnya 0.
-- Contoh:
--   banyakRuangan Empty == 0
--   banyakRuangan tx == 1
--   banyakRuangan ta == 3
--   banyakRuangan tb == 5
-- TODO: Lengkapi fungsi sesuai spesifikasi.
banyakRuangan :: BinTree Int -> Int
banyakRuangan Empty = 0
banyakRuangan (Node a l r) 
  | isTreeEmpty l && isTreeEmpty r = 1
  | l /= Empty && r /= Empty = 1 + banyakRuangan l + banyakRuangan r
  | l /= Empty = 1 + banyakRuangan l
  | otherwise = 1 + banyakRuangan r


-- solusi:
-- banyakRuangan Empty = 0
-- banyakRuangan (Node _ l r) = 1 + banyakRuangan l + banyakRuangan r
