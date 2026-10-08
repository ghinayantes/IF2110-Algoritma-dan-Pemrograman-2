module SilsilahPinus where

-- SILSILAH PINUS
-- DEFINISI TYPE
-- Type yang dipakai oleh driver Olympia. JANGAN DIUBAH.
-- Pohon n-aire: Anggota <nama> <list anak-anaknya>
-- Anggota yang list anaknya kosong adalah anggota tanpa anak (daun).
data Silsilah = Anggota String [Silsilah]
    deriving (Show, Read)


-- BANYAK ANGGOTA
-- Contoh yang sudah disediakan. JANGAN DIUBAH.
-- DEFINISI DAN SPESIFIKASI
banyakAnggota :: Silsilah -> Integer
-- banyakAnggota s adalah banyaknya anggota pada silsilah s, termasuk anggota teratasnya.
-- Hasilnya selalu lebih dari 0, karena setiap silsilah mempunyai anggota teratas.

banyakAnggotaList :: [Silsilah] -> Integer
-- banyakAnggotaList l adalah jumlah banyaknya anggota pada seluruh silsilah dalam l.
-- Jika l kosong, hasilnya 0.

-- REALISASI
banyakAnggota (Anggota _ anak) = 1 + banyakAnggotaList anak

banyakAnggotaList l
    | null l    = 0
    | otherwise = banyakAnggota (head l) + banyakAnggotaList (tail l)

-- APLIKASI
-- > banyakAnggota (Anggota "Deeper" [])
-- 1
--
-- > banyakAnggota (Anggota "Sermi" [Anggota "Deeper" [], Anggota "Mebel" []])
-- 3
--
-- > banyakAnggotaList []
-- 0
--
-- > banyakAnggotaList [Anggota "Stun" [], Anggota "Sermi" [Anggota "Deeper" []]]
-- 3


-- BANYAK GENERASI
-- DEFINISI DAN SPESIFIKASI
banyakGenerasi :: Silsilah -> Integer
-- banyakGenerasi s adalah banyaknya anggota pada jalur terpanjang dari anggota teratas s
-- sampai seorang anggota tanpa anak. Silsilah dengan satu anggota mempunyai 1 generasi.

banyakGenerasiList :: [Silsilah] -> Integer
-- banyakGenerasiList l adalah banyakGenerasi terbesar di antara seluruh silsilah dalam l.
-- Jika l kosong, hasilnya 0.

-- REALISASI
banyakGenerasi (Anggota _ anak) = if null anak then 1 else 1 + (banyakGenerasiList anak) 

banyakGenerasiList [] = 0
banyakGenerasiList l = maximum (map banyakGenerasi l)

-- APLIKASI
-- > banyakGenerasi (Anggota "Deeper" [])
-- 1
--
-- > banyakGenerasi (Anggota "Filbert" [Anggota "Stun" [], Anggota "Sermi" [Anggota "Deeper" []]])
-- 3
--
-- > banyakGenerasiList []
-- 0
--
-- > banyakGenerasiList [Anggota "Stun" [], Anggota "Sermi" [Anggota "Deeper" []]]
-- 2
