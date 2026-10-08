module SisipBuku where

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
--   te:
--     5
--     |---\
--         8
--   tx:
--     7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
te :: BinTree Int
te = Node 5 Empty (Node 8 Empty Empty)
tx :: BinTree Int
tx = Node 7 Empty Empty

-- SPESIFIKASI
-- sisipBuku x t menghasilkan pohon terurut yang berisi seluruh nilai t beserta x.
-- Bila x sudah ada pada t, hasilnya adalah t.
-- Prasyarat: t adalah pohon terurut tanpa nilai kembar.
-- Contoh:
--   sisipBuku 5 Empty == Node 5 Empty Empty
--   sisipBuku 6 tb == Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 (Node 6 Empty Empty) Empty))
--   sisipBuku 4 tb == Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
--   sisipBuku 0 tb == Node 4 (Node 2 (Node 1 (Node 0 Empty Empty) Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
-- TODO: Lengkapi fungsi sesuai spesifikasi.
sisipBuku :: Int -> BinTree Int -> BinTree Int
sisipBuku x t = error "TODO"

-- SPESIFIKASI
-- keluarkanTerkecil t menghasilkan pohon terurut t tanpa nilai terkecilnya.
-- Prasyarat: t adalah pohon terurut dan tidak kosong.
-- Contoh:
--   keluarkanTerkecil tb == Node 4 (Node 2 Empty Empty) (Node 5 Empty (Node 7 Empty Empty))
--   keluarkanTerkecil te == Node 8 Empty Empty
--   keluarkanTerkecil tx == Empty
-- TODO: Lengkapi fungsi sesuai spesifikasi.
keluarkanTerkecil :: BinTree Int -> BinTree Int
keluarkanTerkecil t = error "TODO"
