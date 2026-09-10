module Buku where

-- TYPE BUKU
-- DEFINISI TYPE
-- type buku: <judul: String, penulis: String, tahunTerbit: Int, stok: Int>
-- {<judul, penulis, tahunTerbit, stok> adalah sebuah buku pada
--  perpustakaan, dengan judul dan penulis sebagai identitas, tahunTerbit
--  adalah tahun buku diterbitkan, dan stok adalah jumlah eksemplar yang
--  tersedia untuk dipinjam}

data Buku = Buku String String Int Int
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- judul: buku -> String
-- {judul(B) memberikan judul Buku B}
judul :: Buku -> String
judul (Buku j _ _ _) = j

-- penulis: buku -> String
-- {penulis(B) memberikan penulis Buku B}
penulis :: Buku -> String
penulis (Buku _ p _ _) = p

-- tahunTerbit: buku -> Int
-- {tahunTerbit(B) memberikan tahun terbit Buku B}
tahunTerbit :: Buku -> Int
tahunTerbit (Buku _ _ t _) = t

-- stok: buku -> Int
-- {stok(B) memberikan jumlah eksemplar Buku B yang tersedia}
stok :: Buku -> Int
stok (Buku _ _ _ s) = s

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeBuku: String -> String -> Int -> Int -> buku
-- {makeBuku(judul,penulis,tahunTerbit,stok) membentuk sebuah Buku baru.
--  Prasyarat: tahunTerbit > 0, stok >= 0}
makeBuku :: String -> String -> Int -> Int -> Buku
makeBuku j p t s = (Buku j p t s)

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isTersedia: buku -> Bool
-- {isTersedia(B) benar jika Buku B memiliki stok lebih dari 0}
isTersedia :: Buku -> Bool
isTersedia b = stok b > 0

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP BUKU
-- pinjamBuku: buku -> buku
-- {pinjamBuku(B) mengurangi stok Buku B sebanyak 1.
--  Prasyarat: isTersedia(B)}
pinjamBuku :: Buku -> Buku
pinjamBuku b = makeBuku (judul b) (penulis b) (tahunTerbit b) ((stok b) - 1)

-- kembalikanBuku: buku -> buku
-- {kembalikanBuku(B) menambah stok Buku B sebanyak 1}
kembalikanBuku :: Buku -> Buku
kembalikanBuku b = makeBuku (judul b) (penulis b) (tahunTerbit b) ((stok b) + 1)

-- klasifikasiUmurBuku: buku -> Int -> String
-- {klasifikasiUmurBuku(B,tahunSekarang) mengklasifikasikan Buku B
--  berdasarkan usianya terhadap tahunSekarang}
-- Dengan ketentuan:
-- usia < 5 tahun            : "Baru"
-- 5 <= usia < 20 tahun      : "Lama"
-- usia >= 20 tahun          : "Klasik"
klasifikasiUmurBuku :: Buku -> Int -> String
klasifikasiUmurBuku b tahunSekarang
    | tahunSekarang - (tahunTerbit b) < 5 = "Baru"
    | tahunSekarang - (tahunTerbit b) < 20 = "Lama"
    | otherwise = "Klasik"

-- test case
buku1 = makeBuku "Laskar Pelangi" "Andrea Hirata" 2005 3
buku0 = makeBuku "Buku Kosong" "Penulis X" 2020 0