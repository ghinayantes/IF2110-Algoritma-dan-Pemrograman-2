module KelilingLingkaran where
    -- Definisi
    -- Fungsi yang menerima masukan luas lingkaran dan memberikan keluaran keliling lingkaran berupa bilangan real
    -- Prasyarat: luas >= 0.0
    toKeliling :: Double -> Double

    -- Realisasi
    toKeliling luas = 2 * pi * sqrt (luas / pi)

    -- Implementasi
    -- toKeliling 78.53975 = 31.4159..

    