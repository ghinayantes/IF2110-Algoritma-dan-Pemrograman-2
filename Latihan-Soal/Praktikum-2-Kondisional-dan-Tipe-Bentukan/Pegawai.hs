module Pegawai where

-- TYPE PEGAWAI
-- DEFINISI TYPE
-- type pegawai: <nama: String, golongan: Int, gajiPokok: Float>
-- {<nama,golongan,gajiPokok> adalah seorang pegawai, dengan golongan
--  adalah golongan jabatan pegawai (1..4) dan gajiPokok adalah gaji
--  pokok bulanan pegawai dalam rupiah}

data Pegawai = Pegawai String Int Float
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- nama: pegawai -> String
-- {nama(P) memberikan nama Pegawai P}
nama :: Pegawai -> String
nama (Pegawai n _ _) = n

-- golongan: pegawai -> Int
-- {golongan(P) memberikan golongan Pegawai P}
golongan :: Pegawai -> Int
golongan (Pegawai _ g _) = g

-- gajiPokok: pegawai -> Float
-- {gajiPokok(P) memberikan gaji pokok Pegawai P}
gajiPokok :: Pegawai -> Float
gajiPokok (Pegawai _ _ gp) = gp

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makePegawai: String -> Int -> Float -> pegawai
-- {makePegawai(nama,golongan,gajiPokok) membentuk Pegawai baru.
--  Prasyarat: 1 <= golongan <= 4, gajiPokok > 0.0}
makePegawai :: String -> Int -> Float -> Pegawai
makePegawai n g gp = (Pegawai n g gp)

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isValidPegawai: pegawai -> Bool
-- {isValidPegawai(P) benar jika P memiliki nama tidak kosong,
--  1 <= golongan <= 4, dan gajiPokok > 0.0}
isValidPegawai :: Pegawai -> Bool
isValidPegawai p = (nama p /= "") && (golongan p >= 1) && (golongan p <= 4) && (gajiPokok p > 0.0) -- bisa juga not (null (nama p))

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP PEGAWAI
-- hitungBonus: pegawai -> Float
-- {hitungBonus(P) menghitung bonus tahunan Pegawai P berdasarkan
--  golongannya}
-- Dengan ketentuan:
-- golongan 1 : 10% dari gajiPokok
-- golongan 2 : 20% dari gajiPokok
-- golongan 3 : 35% dari gajiPokok
-- golongan 4 : 50% dari gajiPokok
hitungBonus :: Pegawai -> Float
hitungBonus p 
    | (golongan p == 1) = 0.1 * (gajiPokok p)
    | (golongan p == 2) = 0.2 * (gajiPokok p)
    | (golongan p == 3) = 0.35 * (gajiPokok p)
    | (golongan p == 4) = 0.5 * (gajiPokok p)
    | otherwise = 0.0

-- naikGolongan: pegawai -> pegawai
-- {naikGolongan(P) menaikkan golongan Pegawai P sebesar 1,
--  maksimum golongan adalah 4}
naikGolongan :: Pegawai -> Pegawai
naikGolongan p = if (golongan p < 4) then makePegawai (nama p) ((golongan p) + 1) (gajiPokok p) else p

p1 = makePegawai "Andi" 1 4000000
p2 = makePegawai "Budi" 2 5000000
p3 = makePegawai "Citra" 3 6000000
p4 = makePegawai "Dedi" 4 7000000