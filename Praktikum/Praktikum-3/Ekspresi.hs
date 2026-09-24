module Ekspresi where

-- EKSPRESI ARITMATIKA
-- DEFINISI TYPE
data Expr = Val Int | Add Expr Expr | Mul Expr Expr deriving (Show, Read)

-- DEFINISI DAN SPESIFIKASI
evaluasi :: Expr -> Int
-- evaluasi e menghasilkan hasil perhitungan ekspresi e.

-- REALISASI
evaluasi (Val x)     = x
evaluasi (Add e1 e2) = evaluasi e1 + evaluasi e2
evaluasi (Mul e1 e2) = evaluasi e1 * evaluasi e2

-- APLIKASI
-- evaluasi (Add (Val 3) (Mul (Val 2) (Val 4)))