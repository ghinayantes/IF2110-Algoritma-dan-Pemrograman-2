module AmplifikasiQuantum where

-- AMPLIFIKASI QUANTUM
-- DEFINISI DAN SPESIFIKASI
amplifikasiQuantum :: (Int -> Int) -> Int -> Int -> Int -> Int
-- amplifikasiQuantum f start end step menghasilkan perkalian barisan dari:
-- f(start) * f(start + step) * f(start + 2*step) * ... 
-- selama nilai frekuensi <= end.
-- Jika start > end, hasilnya 1. step >= 1.
-- Seluruh nilai dan perhitungan dijamin berada dalam rentang Int.

-- REALISASI
amplifikasiQuantum f start end step 
    | start > end = 1
    | otherwise = (f start) * amplifikasiQuantum f (start + step) end step