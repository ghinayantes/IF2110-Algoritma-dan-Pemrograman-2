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

-- BENTUK POHON UJI COBA
--   e1:
--                 *
--         /-------|---\
--         +           5
--     /---|---\
--     3       4
--   e2:
--         -
--     /---|-------\
--     2           *
--             /---|---\
--             3       -4
--   e3:
--     7

-- POHON UJI COBA (boleh dipakai di GHCi untuk mencoba fungsi Anda)
e1 :: Expr
e1 = Op '*' (Op '+' (Angka 3) (Angka 4)) (Angka 5)
e2 :: Expr
e2 = Op '-' (Angka 2) (Op '*' (Angka 3) (Angka (-4)))
e3 :: Expr
e3 = Angka 7

-- SPESIFIKASI
-- evaluasi e menghasilkan nilai ekspresi e.
-- Sebuah Angka n bernilai n. Sebuah Op c l r bernilai hasil operator c terhadap nilai l dan nilai r (gunakan applyOp).
-- Contoh:
--   evaluasi e3 == 7
--   evaluasi e1 == 35
--   evaluasi e2 == 14
-- TODO: Lengkapi fungsi sesuai spesifikasi.
evaluasi :: Expr -> Int
evaluasi e = error "TODO"

-- SPESIFIKASI
-- notasiPrefix e menghasilkan penulisan e dengan urutan: operator, operan kiri, operan kanan (pre-order), dengan setiap lambang dipisahkan satu spasi, tanpa spasi di awal maupun akhir.
-- Contoh:
--   notasiPrefix e3 == "7"
--   notasiPrefix e1 == "* + 3 4 5"
--   notasiPrefix e2 == "- 2 * 3 -4"
-- TODO: Lengkapi fungsi sesuai spesifikasi.
notasiPrefix :: Expr -> String
notasiPrefix e = error "TODO"

-- SPESIFIKASI
-- notasiPostfix e menghasilkan penulisan e dengan urutan: operan kiri, operan kanan, operator (post-order), dengan setiap lambang dipisahkan satu spasi, tanpa spasi di awal maupun akhir.
-- Contoh:
--   notasiPostfix e3 == "7"
--   notasiPostfix e1 == "3 4 + 5 *"
--   notasiPostfix e2 == "2 3 -4 * -"
-- TODO: Lengkapi fungsi sesuai spesifikasi.
notasiPostfix :: Expr -> String
notasiPostfix e = error "TODO"
