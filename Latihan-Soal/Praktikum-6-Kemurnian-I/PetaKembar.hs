module PetaKembar where

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
--   tp:
--         2
--     /---|
--     1
--   ts:
--             1
--         /---|---\
--         2       2
--     /---|       |---\
--     3               3
--   tt:
--             1
--         /---|-------\
--         2           2
--     /---|       /---|
--     3           3
--   tu:
--         1
--     /---|---\
--     2       2

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
ta :: BinTree Int
ta = Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tb2 :: BinTree Int
tb2 = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tp :: BinTree Int
tp = Node 2 (Node 1 Empty Empty) Empty
ts :: BinTree Int
ts = Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 2 Empty (Node 3 Empty Empty))
tt :: BinTree Int
tt = Node 1 (Node 2 (Node 3 Empty Empty) Empty) (Node 2 (Node 3 Empty Empty) Empty)
tu :: BinTree Int
tu = Node 1 (Node 2 Empty Empty) (Node 2 Empty Empty)

-- SPESIFIKASI
-- petaSama t1 t2 bernilai True bila t1 dan t2 memiliki bentuk dan nilai simpul yang persis sama.
-- Fungsi ini harus ditulis secara rekursif, tanpa memakai operator == pada pohon.
-- Contoh:
--   petaSama Empty Empty == True
--   petaSama ta ta == True
--   petaSama ta tb == False
--   petaSama tp ta == False
-- TODO: Lengkapi fungsi sesuai spesifikasi.
petaSama :: BinTree Int -> BinTree Int -> Bool
petaSama t1 t2 = t1 == t2

-- SPESIFIKASI
-- petaPotongan s t bernilai True bila s adalah sebuah upapohon dari t, yaitu terdapat simpul pada t (atau t sendiri) yang beserta seluruh keturunannya persis sama dengan s.
-- Pohon kosong dianggap upapohon dari pohon apa pun.
-- Contoh:
--   petaPotongan tp tb == True
--   petaPotongan ta tb == False
--   petaPotongan Empty tb == True
--   petaPotongan tb tb == True
-- TODO: Lengkapi fungsi sesuai spesifikasi.
petaPotongan :: BinTree Int -> BinTree Int -> Bool
petaPotongan Empty _ = True
petaPotongan _ Empty = False
petaPotongan s (Node a l r) = s == (Node a l r) || (petaPotongan s l) || (petaPotongan s r)

-- SPESIFIKASI
-- petaSimetris t bernilai True bila subpohon kiri dan kanan t saling bercermin, yaitu bentuknya merupakan pencerminan dan nilai simpul yang bersesuaian sama.
-- Pohon kosong dianggap simetris.
-- Contoh:
--   petaSimetris Empty == True
--   petaSimetris tu == True
--   petaSimetris ta == False
--   petaSimetris ts == True
--   petaSimetris tt == False
-- TODO: Lengkapi fungsi sesuai spesifikasi.
petaSimetris :: BinTree Int -> Bool
petaSimetris Empty = True
petaSimetris (Node _ l r) = bercermin l r
  where
    bercermin Empty Empty = True
    bercermin (Node a l1 r1) (Node b l2 r2) = a == b && bercermin l1 r2 && bercermin r1 l2
    bercermin _ _ = False

