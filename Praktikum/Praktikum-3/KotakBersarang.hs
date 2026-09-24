module KotakBersarang where

-- KOTAK BERSARANG
-- DEFINISI TYPE
data Kotak = Kosong | Kotak Int Kotak
    deriving (Show, Read)

-- DEFINISI DAN SPESIFIKASI
totalKoin :: Kotak -> Int
-- totalKoin kotak menghasilkan jumlah koin pada seluruh susunan kotak.

-- REALISASI
totalKoin Kosong = 0
totalKoin (Kotak koin kotakDalam) = koin + totalKoin kotakDalam

-- APLIKASI
-- totalKoin (Kotak 5 (Kotak 0 (Kotak 3 Kosong)))