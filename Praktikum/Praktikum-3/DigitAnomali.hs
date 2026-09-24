module DigitAnomali where

-- DIGIT ANOMALI
-- DEFINISI DAN SPESIFIKASI
hitungDigit :: Int -> Int -> Int
-- hitungDigit n d menghasilkan banyak kemunculan digit d dalam bilangan n.

-- REALISASI
hitungDigit n d
  | n == 0 = if d == 0 then 1 else 0
  | otherwise = hitung n d
  where
    hitung 0 _ = 0
    hitung x d
      | x `mod` 10 == d = 1 + hitung (x `div` 10) d
      | otherwise       = hitung (x `div` 10) d

-- APLIKASI
-- hitungDigit 707070 7