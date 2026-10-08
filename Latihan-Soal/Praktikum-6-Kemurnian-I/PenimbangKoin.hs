module PenimbangKoin where

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

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
ta :: BinTree Int
ta = Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))

-- SPESIFIKASI
-- sumIf p t menghasilkan jumlah nilai seluruh simpul x pada t yang memenuhi p x.
-- Jika tidak ada simpul yang memenuhi, atau t kosong, hasilnya 0.
-- Contoh:
--   sumIf even Empty == 0
--   sumIf even tb == 6
--   sumIf (> 3) tb == 16
--   sumIf (\x -> x `mod` 3 == 0) ta == 3
--   sumIf (> 100) ta == 0
-- TODO: Lengkapi fungsi sesuai spesifikasi.
sumIf :: (Int -> Bool) -> BinTree Int -> Int
sumIf p Empty = 0
sumIf p (Node a l r) 
  | p a = a + (sumIf p l) + (sumIf p r)
  | otherwise = (sumIf p l) + (sumIf p r)

-- SPESIFIKASI
-- banyakIf p t menghasilkan banyaknya simpul x pada t yang memenuhi p x.
-- Contoh:
--   banyakIf odd tb == 3
--   banyakIf (< 0) tb == 0
--   banyakIf (\x -> x > 1 && x < 5) tb == 2
-- TODO: Lengkapi fungsi sesuai spesifikasi.
banyakIf :: (Int -> Bool) -> BinTree Int -> Int
banyakIf p Empty = 0
banyakIf p (Node a l r) = if p a then 1 + (banyakIf p l) + (banyakIf p r) else (banyakIf p l) + (banyakIf p r) 

-- solusi
-- sumIf
-- sumIf :: (Int -> Bool) -> BinTree Int -> Int
-- sumIf _ Empty = 0
-- sumIf p (Node v l r) = (if p v then v else 0) + sumIf p l + sumIf p r

-- banyakIf
-- banyakIf :: (Int -> Bool) -> BinTree Int -> Int
-- banyakIf _ Empty = 0
-- banyakIf p (Node v l r) = (if p v then 1 else 0) + banyakIf p l + banyakIf p r

-- (bisa digabung pake if gitu)