module Waktu where

-- TYPE WAKTU
-- DEFINISI TYPE
-- type waktu: <jam: Int, menit: Int, detik: Int>
-- {<jam,menit,detik> adalah sebuah penunjuk waktu pada suatu hari,
--  dengan 0 <= jam <= 23, 0 <= menit <= 59, 0 <= detik <= 59}

data Waktu = Waktu Int Int Int
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- jam: waktu -> Int
-- {jam(W) memberikan komponen jam dari Waktu W}
jam :: Waktu -> Int
jam (Waktu j _ _) = j

-- menit: waktu -> Int
-- {menit(W) memberikan komponen menit dari Waktu W}
menit :: Waktu -> Int
menit (Waktu _ m _) = m

-- detik: waktu -> Int
-- {detik(W) memberikan komponen detik dari Waktu W}
detik :: Waktu -> Int
detik (Waktu _ _ d) = d

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeWaktu: Int -> Int -> Int -> waktu
-- {makeWaktu(j,m,d) membentuk sebuah Waktu dari jam j, menit m, detik d}
makeWaktu :: Int -> Int -> Int -> Waktu
makeWaktu j m d = (Waktu j m d)

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isValidWaktu: waktu -> Bool
-- {isValidWaktu(W) benar jika W adalah Waktu yang sah:
--  0 <= jam <= 23, 0 <= menit <= 59, 0 <= detik <= 59}
isValidWaktu :: Waktu -> Bool
isValidWaktu w = (jam w >= 0) && (jam w <= 23) && (menit w >= 0) && (menit w <= 59) && (detik w >= 0) && (detik w <= 59)

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP WAKTU
-- keDetik: waktu -> Int
-- {keDetik(W) mengubah Waktu W menjadi jumlah detik sejak tengah malam}
keDetik :: Waktu -> Int
keDetik w = (jam w) * 3600 + (menit w) * 60 + detik w

-- isSebelum: waktu -> waktu -> Bool
-- {isSebelum(W1,W2) benar jika W1 terjadi sebelum W2 pada hari yang sama}
isSebelum :: Waktu -> Waktu -> Bool
isSebelum w1 w2 = keDetik w1 < keDetik w2

w1 = makeWaktu 8 30 0
w2 = makeWaktu 8 30 0
w3 = makeWaktu 8 30 15
w4 = makeWaktu 8 45 0
w5 = makeWaktu 9 0 0
w6 = makeWaktu 10 59 59