module SandiPamanFrod where

-- DEFINISI DATA STRUKTUR
-- Pohon ekspresi: sebuah bilangan, atau operator biner dengan dua operan
data Expr = Angka Int | Op Char Expr Expr
  deriving (Show, Eq)

-- PREDIKAT
isAngka :: Expr -> Bool
isAngka (Angka _) = True
isAngka _         = False

-- FUNGSI YANG SUDAH DISEDIAKAN (tidak perlu diubah)
-- applyOp c a b menghasilkan hasil operasi c terhadap a dan b.
-- Prasyarat: c adalah salah satu dari '+', '-', '*'
applyOp :: Char -> Int -> Int -> Int
applyOp '+' a b = a + b
applyOp '-' a b = a - b
applyOp '*' a b = a * b
applyOp c _ _   = error ("applyOp: operator tidak dikenal " ++ [c])


-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
e1 :: Expr
e1 = Op '*' (Op '+' (Angka 3) (Angka 4)) (Angka 5)
e2 :: Expr
e2 = Op '-' (Angka 2) (Op '*' (Angka 3) (Angka (-4)))
e3 :: Expr
e3 = Angka 7

-- evaluasi
evaluasi :: Expr -> Int
evaluasi (Angka n) = n
evaluasi (Op c l r) = applyOp c (evaluasi l) (evaluasi r)

-- notasiPrefix
notasiPrefix :: Expr -> String
notasiPrefix (Angka n) = show n
notasiPrefix (Op c l r) = [c] ++ " " ++ notasiPrefix l ++ " " ++ notasiPrefix r

-- notasiPostfix
notasiPostfix :: Expr -> String
notasiPostfix (Angka n) = show n
notasiPostfix (Op c l r) = notasiPostfix l ++ " " ++ notasiPostfix r ++ " " ++ [c]
