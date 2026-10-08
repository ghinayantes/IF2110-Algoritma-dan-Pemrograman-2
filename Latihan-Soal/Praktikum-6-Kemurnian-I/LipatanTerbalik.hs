module LipatanTerbalik where

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
-- treeFoldRevIn f b t menghasilkan akumulasi nilai pohon t dengan fold reverse in-order menggunakan f dan basis b.
-- Urutan proses: subpohon kanan, kemudian akar, dan terakhir subpohon kiri. Fungsi f menerima tiga argumen secara berurutan: hasil subpohon kanan, nilai akar, dan hasil subpohon kiri.
-- Untuk pohon kosong, hasilnya adalah b.
-- Contoh:
--   treeFoldRevIn (\r x l -> r ++ [x] ++ l) [] ta == [3,2,1]
--   treeFoldRevIn (\r x l -> r ++ [x] ++ l) [] tb == [7,5,4,2,1]
--   treeFoldRevIn (\r x l -> r + x + l) 0 tb == 19
--   treeFoldRevIn (\r x l -> x : (l ++ r)) [] tb == [4,2,1,5,7]
-- TODO: Lengkapi fungsi sesuai spesifikasi.
treeFoldRevIn :: (a -> Int -> a -> a) -> a -> BinTree Int -> a
treeFoldRevIn _ base Empty = base
treeFoldRevIn func base (Node a l r) = func (treeFoldRevIn func base r) a (treeFoldRevIn func base l)

-- SPESIFIKASI
-- kTermahal k t menghasilkan list berisi k nilai terbesar pada pohon terurut t, dari yang terbesar ke yang terkecil.
-- Jika t memiliki kurang dari k simpul, semua nilai t dikembalikan.
-- Prasyarat: t adalah pohon terurut (seluruh nilai di kiri < akar < seluruh nilai di kanan).
-- Contoh:
--   kTermahal 3 tb == [7,5,4]
--   kTermahal 10 tb == [7,5,4,2,1]
--   kTermahal 0 tb == []
--   kTermahal 2 Empty == []
-- TODO: Lengkapi fungsi sesuai spesifikasi.
kTermahal :: Int -> BinTree Int -> [Int]
kTermahal k t = take k (treeFoldRevIn (\r x l -> r ++ [x] ++ l) [] t)

-- solusi
-- (sama aja, malah ini lebih simpel)