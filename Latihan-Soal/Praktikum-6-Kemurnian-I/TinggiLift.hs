module TinggiLift where

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
--   tc:
--     1
--     |---\
--         2
--         |---\
--             3
--             |---\
--                 4
--   tx:
--     7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
ta :: BinTree Int
ta = Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tc :: BinTree Int
tc = Node 1 Empty (Node 2 Empty (Node 3 Empty (Node 4 Empty Empty)))
tx :: BinTree Int
tx = Node 7 Empty Empty

-- SPESIFIKASI
-- tinggiLift t menghasilkan banyaknya simpul pada jalur terpanjang dari akar sampai sebuah daun.
-- Tinggi pohon kosong adalah 0, dan tinggi pohon dengan satu simpul adalah 1.
-- Contoh:
--   tinggiLift Empty == 0
--   tinggiLift tx == 1
--   tinggiLift ta == 2
--   tinggiLift tb == 3
--   tinggiLift tc == 4
-- TODO: Lengkapi fungsi sesuai spesifikasi.
tinggiLift :: BinTree Int -> Int
tinggiLift Empty = 0
tinggiLift v = tinggiLiftLantai 0 v 

-- helper ukur kedalaman 
tinggiLiftLantai :: Int -> BinTree Int -> Int
tinggiLiftLantai f Empty = f
tinggiLiftLantai f (Node _ l r) = max (tinggiLiftLantai (f+1) l) (tinggiLiftLantai (f+1) r)

-- solusi 
-- tinggiLift Empty = 0
-- tinggiLift (Node _ l r) = 1 + max (tinggiLift l) (tinggiLift r)
-- (ga perlu helper)