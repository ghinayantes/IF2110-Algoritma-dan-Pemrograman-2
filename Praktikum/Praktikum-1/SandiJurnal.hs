module SandiJurnal where

-- SANDI JURNAL
-- DEFINISI DAN SPESIFIKASI
isSandiValid :: Int -> Bool
-- isSandiValid sandi benar jika sandi terdiri dari tiga digit,
-- digit pertama dan terakhir sama, digit tengah berbeda,
-- dan jumlah ketiga digit habis dibagi tiga

-- REALISASI
isSandiValid sandi = (((sandi < 1000 && sandi > 99) && ((sandi `div` 100) == (sandi `mod` 10) && (sandi `div` 100) /= (sandi `div` 10) - ((sandi `div` 100) * 10))) && ((((sandi `div` 100) + ((sandi `div` 10) - ((sandi `div` 100) * 10))) + (sandi `mod` 10))) `mod` 3 == 0)

-- APLIKASI
-- isSandiValid 252