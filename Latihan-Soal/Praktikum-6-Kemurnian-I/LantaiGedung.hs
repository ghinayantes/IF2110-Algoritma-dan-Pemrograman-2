module LantaiGedung where

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
-- isiLantai k t menghasilkan list nilai seluruh simpul pada lantai ke-k pohon t, dari kiri ke kanan. Akar berada di lantai 1.
-- Bila t tidak memiliki lantai ke-k, hasilnya list kosong.
-- Contoh:
--   isiLantai 1 tb == [4]
--   isiLantai 2 tb == [2,5]
--   isiLantai 3 tb == [1,7]
--   isiLantai 4 tb == []
-- TODO: Lengkapi fungsi sesuai spesifikasi.
isiLantai :: Int -> BinTree Int -> [Int]
isiLantai k t = error "TODO"

-- SPESIFIKASI
-- jumlahPerLantai t menghasilkan list yang elemen ke-i-nya adalah jumlah nilai seluruh simpul pada lantai ke-i, mulai dari lantai 1 sampai lantai terdalam.
-- Untuk pohon kosong, hasilnya list kosong.
-- Contoh:
--   jumlahPerLantai Empty == []
--   jumlahPerLantai tb == [4,7,8]
--   jumlahPerLantai tx == [7]
-- TODO: Lengkapi fungsi sesuai spesifikasi.
jumlahPerLantai :: BinTree Int -> [Int]
jumlahPerLantai t = error "TODO"
