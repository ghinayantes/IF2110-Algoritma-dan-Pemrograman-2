module SihirPohon where

-- SIHIR POHON
-- UTILITY FUNCTIONS
-- Type dan fungsi pembantu yang dipakai oleh driver Olympia. JANGAN DIUBAH.
-- Pohon biner: Kosong, atau Simpul <upapohon kiri> <info> <upapohon kanan>
data Pohon = Kosong | Simpul Pohon Integer Pohon
    deriving (Show, Read)

-- sihir s menghasilkan fungsi mantra bernama s.
-- Anda dapat memakainya untuk mencoba realisasi di ghci, misalnya:
-- mapPohon (sihir "ganda") (Simpul Kosong 5 Kosong)
-- Nama mantra yang tersedia: "id", "ganda", "tambah1", "kuadrat", "negasi", "nol"
sihir :: String -> (Integer -> Integer)
sihir "id"      x = x
sihir "ganda"   x = 2 * x
sihir "tambah1" x = x + 1
sihir "kuadrat" x = x * x
sihir "negasi"  x = -x
sihir "nol"     _ = 0
sihir _         x = x


-- MAP POHON
-- DEFINISI DAN SPESIFIKASI
mapPohon :: (Integer -> Integer) -> Pohon -> Pohon
-- mapPohon f t menghasilkan pohon baru yang bentuknya sama persis dengan t,
-- tetapi setiap info v pada t diganti dengan f v.
-- Jika t kosong, hasilnya adalah pohon kosong.

-- REALISASI
mapPohon _ Kosong = Kosong
mapPohon f (Simpul l v r) = Simpul (mapPohon f l) (f v) (mapPohon f r)

-- APLIKASI
-- > mapPohon (sihir "ganda") Kosong
-- Kosong
--
-- > mapPohon (sihir "ganda") (Simpul (Simpul Kosong 3 Kosong) 5 (Simpul Kosong 8 Kosong))
-- Simpul (Simpul Kosong 6 Kosong) 10 (Simpul Kosong 16 Kosong)
--
-- > mapPohon (sihir "negasi") (Simpul Kosong 4 (Simpul Kosong 7 Kosong))
-- Simpul Kosong (-4) (Simpul Kosong (-7) Kosong)


-- MANTRA BILL
-- DEFINISI DAN SPESIFIKASI
mantraBill :: Integer -> Integer
-- mantraBill x adalah hasil mantra Bill pada satu info x:
-- - jika x genap, hasilnya x div 2,
-- - jika x ganjil, hasilnya 3 * x + 1.

-- REALISASI
mantraBill x = if even x then div x 2 else 3 * x + 1

-- APLIKASI
-- > mantraBill 8
-- 4
--
-- > mantraBill 5
-- 16
--
-- > mantraBill (-3)
-- -8


-- SIHIR BILL
-- DEFINISI DAN SPESIFIKASI
sihirBill :: Pohon -> Pohon
-- sihirBill t menghasilkan pohon t setelah setiap infonya dikenai mantraBill.
-- Bentuk pohon tidak berubah.
-- Disarankan memanfaatkan mapPohon dan mantraBill, sehingga penelusuran pohon tidak perlu ditulis ulang.

-- REALISASI
sihirBill Kosong = Kosong
sihirBill t@(Simpul l v r) = mapPohon (\x -> mantraBill x) t

-- APLIKASI
-- > sihirBill Kosong
-- Kosong
--
-- > sihirBill (Simpul (Simpul Kosong 3 Kosong) 5 (Simpul Kosong 8 Kosong))
-- Simpul (Simpul Kosong 10 Kosong) 16 (Simpul Kosong 4 Kosong)
--