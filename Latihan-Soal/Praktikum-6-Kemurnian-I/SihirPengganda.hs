module SihirPengganda where

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
-- mapTree f t menghasilkan pohon dengan bentuk yang sama seperti t, dengan nilai tiap simpul x diganti menjadi f x.
-- Contoh:
--   mapTree (* 2) Empty == Empty
--   mapTree (* 2) ta == Node 4 (Node 2 Empty Empty) (Node 6 Empty Empty)
--   mapTree (\x -> x * x - 1) tb == Node 15 (Node 3 (Node 0 Empty Empty) Empty) (Node 24 Empty (Node 48 Empty Empty))
-- TODO: Lengkapi fungsi sesuai spesifikasi.
mapTree :: (Int -> Int) -> BinTree Int -> BinTree Int
mapTree f Empty = Empty
mapTree f (Node a l r) = Node (f a) (mapTree f l) (mapTree f r)

-- SPESIFIKASI
-- ulangTree n f t menghasilkan pohon dengan bentuk yang sama seperti t, dengan nilai tiap simpul x diganti menjadi f yang diterapkan n kali pada x.
-- Jika n = 0, hasilnya adalah t tanpa perubahan.
-- Contoh:
--   ulangTree 0 (* 2) ta == Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
--   ulangTree 3 (+ 2) ta == Node 8 (Node 7 Empty Empty) (Node 9 Empty Empty)
--   ulangTree 2 (\x -> x * x) ta == Node 16 (Node 1 Empty Empty) (Node 81 Empty Empty)
--   ulangTree 2 (* 2) tb == Node 16 (Node 8 (Node 4 Empty Empty) Empty) (Node 20 Empty (Node 28 Empty Empty))
-- TODO: Lengkapi fungsi sesuai spesifikasi.
ulangTree :: Int -> (Int -> Int) -> BinTree Int -> BinTree Int
ulangTree 0 _ t = t
ulangTree n f t = ulangTree (n-1) f (mapTree f t)

-- solusi
-- ulangTree 0 _ t = t
-- ulangTree n f t = mapTree f (ulangTree (n - 1) f t)
