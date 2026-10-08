module AuditKatalog where

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
--   tf:
--         5
--     /---|-------\
--     3           8
--             /---|---\
--             4       9
--   tg:
--         2
--     /---|
--     2
--   th:
--                 5
--         /-------|---\
--         3           8
--     /---|---\
--     1       6

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
tb :: BinTree Int
tb = Node 4 (Node 2 (Node 1 Empty Empty) Empty) (Node 5 Empty (Node 7 Empty Empty))
tf :: BinTree Int
tf = Node 5 (Node 3 Empty Empty) (Node 8 (Node 4 Empty Empty) (Node 9 Empty Empty))
tg :: BinTree Int
tg = Node 2 (Node 2 Empty Empty) Empty
th :: BinTree Int
th = Node 5 (Node 3 (Node 1 Empty Empty) (Node 6 Empty Empty)) (Node 8 Empty Empty)

-- SPESIFIKASI
-- katalogValid t bernilai True bila t memenuhi invarian pohon terurut: untuk setiap simpul, seluruh nilai di kiri < nilai simpul < seluruh nilai di kanan.
-- Pohon kosong dan pohon satu simpul selalu valid.
-- Nilai kembar membuat pohon tidak valid.
-- Contoh:
--   katalogValid Empty == True
--   katalogValid tb == True
--   katalogValid tf == False
--   katalogValid tg == False
--   katalogValid th == False
-- TODO: Lengkapi fungsi sesuai spesifikasi.
katalogValid :: BinTree Int -> Bool
katalogValid t = error "TODO"
