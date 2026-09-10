module TarifListrik where

-- Sebuah rumah tangga dikenai tarif listrik berjenjang berdasarkan
-- jumlah pemakaian dalam kWh pada bulan tersebut, sebagai berikut:
--   0   kWh sampai dengan 100  kWh : Rp1.500 per kWh
--   di atas 100 kWh s.d. 300 kWh  : Rp2.000 per kWh untuk seluruh pemakaian
--   di atas 300 kWh               : Rp2.500 per kWh untuk seluruh pemakaian
-- (bukan tarif progresif per lapis, melainkan satu tarif yang berlaku
-- atas seluruh pemakaian, bergantung golongan pemakaiannya)
--
-- Contoh: tarifListrik 50  = 75000   (50 * 1500)
-- Contoh: tarifListrik 100 = 150000  (100 * 1500)
-- Contoh: tarifListrik 250 = 500000  (250 * 2000)
-- Contoh: tarifListrik 300 = 600000  (300 * 2000)
-- Contoh: tarifListrik 301 = 752500  (301 * 2500)

-- DEFINISI DAN SPESIFIKASI UTAMA
-- tarifListrik: Int -> Int
-- {tarifListrik(k) menghitung total tagihan listrik (rupiah) untuk
--  pemakaian k kWh. Prasyarat: k >= 0}
tarifListrik :: Int -> Int

tarifListrik k 
    | (k >= 0) && (k <= 100) = k * 1500
    | (k > 100) && (k <= 300) = k * 2000
    | otherwise = k * 2500