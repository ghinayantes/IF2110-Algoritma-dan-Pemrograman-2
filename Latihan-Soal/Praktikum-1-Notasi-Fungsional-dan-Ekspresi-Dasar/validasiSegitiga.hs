module Segitiga where
    -- Definisi
    -- Fungsi yang mengecek apakah 3 buah sisi dapat membentuk segtiga yang valid
    isSegitiga :: Integer -> Integer -> Integer -> Bool

    -- Realisasi
    isSegitiga x y z = if x + y > z && x + z > y && z + y > x then True else False

    -- Implementasi
    -- isSegitiga 3 4 5 = True

    
