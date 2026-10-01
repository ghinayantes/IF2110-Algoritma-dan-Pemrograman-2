module TreeAnalytics where

data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- SELEKTOR & PREDIKAT
akar :: BinTree Int -> Int
akar (Node v _ _) = v
akar Empty        = error "pohon kosong"

left :: BinTree Int -> BinTree Int
left (Node _ l _) = l
left Empty        = error "pohon kosong"

right :: BinTree Int -> BinTree Int
right (Node _ _ r) = r
right Empty         = error "pohon kosong"

isTreeEmpty :: BinTree a -> Bool
isTreeEmpty Empty = True
isTreeEmpty _     = False

-- HIGHER-ORDER FUNCTIONS (TREE FOLD)
treeFoldIn :: (a -> Int -> a -> a) -> a -> BinTree Int -> a
treeFoldIn func base tree
    | isTreeEmpty tree = base
    | otherwise = func (treeFoldIn func base (left tree)) (akar tree) (treeFoldIn func base (right tree))

treeFoldPre :: (Int -> a -> a -> a) -> a -> BinTree Int -> a
treeFoldPre func base tree
    | isTreeEmpty tree = base
    | otherwise = func (akar tree) (treeFoldPre func base (left tree)) (treeFoldPre func base (right tree))

-- ====================================================================
-- FUNGSI YANG HARUS DILENGKAPI
-- ====================================================================

-- 1. countEvens
-- Menghitung total bilangan genap pada pohon.
-- Hint: Gunakan treeFoldIn / treeFoldPre dengan lambda.
countEvens :: BinTree Int -> Int
countEvens tree = length (filter (\t -> mod t 2 == 0) (treeFoldPre (\n l r -> [n] ++ l ++ r) [] tree))

-- 2. isAllPositive
-- Mengembalikan True jika SELURUH elemen di pohon > 0, dan False jika ada elemen <= 0.
-- Pohon kosong bernilai True.
-- Hint: Gunakan treeFoldIn / treeFoldPre dengan operator boolean `&&`.
isAllPositive :: BinTree Int -> Bool
isAllPositive tree = treeFoldPre (\n l r -> n > 0 && l && r) True tree

-- 3. maxElement
-- Mengembalikan nilai elemen terbesar di dalam pohon.
-- Jika pohon kosong, kembalikan -999999.
-- Hint: Gunakan treeFoldIn / treeFoldPre dengan fungsi `max`.
maxElement :: BinTree Int -> Int
maxElement tree = treeFoldPre (\n l r -> max n (max l r)) (-999999) tree

-- APLIKASI
-- SAMPLE TREES
t1 :: BinTree Int
t1 = Node 4 
        (Node 2 (Node 1 Empty Empty) (Node 3 Empty Empty)) 
        (Node 6 (Node 5 Empty Empty) (Node 7 Empty Empty))

t2 :: BinTree Int
t2 = Node (-2) (Node 4 Empty Empty) (Node 10 Empty Empty)

-- ====================================================================
-- TEST CASE SOAL 1 (Tree Analytics)
-- ====================================================================
-- countEvens t1
-- EXPECTED: 3  (yaitu node 2, 4, 6)

-- isAllPositive t1
-- EXPECTED: True

-- isAllPositive t2
-- EXPECTED: False (karena ada -2)

-- maxElement t1
-- EXPECTED: 7