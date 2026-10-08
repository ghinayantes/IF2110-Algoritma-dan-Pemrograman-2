module SuhuRuangan where

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


-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tx :: BinTree Int
tx = Node 7 Empty Empty
td :: BinTree Int
td = Node 3 (Node (-4) Empty (Node 9 Empty Empty)) (Node 0 Empty Empty)

-- suhuMaks
suhuMaks :: BinTree Int -> Int
suhuMaks (Node v Empty Empty) = v
suhuMaks (Node v l Empty) = max v (suhuMaks l)
suhuMaks (Node v Empty r) = max v (suhuMaks r)
suhuMaks (Node v l r) = max v (max (suhuMaks l) (suhuMaks r))
suhuMaks Empty = error "suhuMaks: pohon kosong"

-- suhuMin
suhuMin :: BinTree Int -> Int
suhuMin (Node v Empty Empty) = v
suhuMin (Node v l Empty) = min v (suhuMin l)
suhuMin (Node v Empty r) = min v (suhuMin r)
suhuMin (Node v l r) = min v (min (suhuMin l) (suhuMin r))
suhuMin Empty = error "suhuMin: pohon kosong"

-- rentangSuhu
rentangSuhu :: BinTree Int -> Int
rentangSuhu t = suhuMaks t - suhuMin t
