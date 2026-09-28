-- Praktikum: List of List
-- Nama : 
-- NIM  :
--
-- Ganti setiap `undefined` dengan realisasi Anda. Jangan ubah tanda type.
-- Tuliskan -- Basis-0 atau -- Basis-1 di bawah spesifikasi setiap fungsi rekursif.
-- Fungsi bantu tambahan boleh ditulis sendiri.
-- Uji dengan: runghc Tes.hs
module LatListofList where

-- ===================================================================
-- Type bentukan yang disediakan
-- ===================================================================

type Matrix = [[Integer]]   -- list of list bilangan bulat, tiap sublist adalah satu baris

-- ===================================================================
-- Bagian A: Operasi dasar list of list
-- ===================================================================



flattenLL :: [[a]] -> [a]
-- flattenLL ll adalah seluruh elemen setiap sublist ll, digabung berurutan
flattenLL [] = []
flattenLL (x:xs) = x ++ flattenLL xs

-- Helper untuk menghitung panjang list biasa
nbElmt :: [a] -> Integer
nbElmt [] = 0
nbElmt (x:xs) = 1 + nbElmt xs

lengthLL :: [[a]] -> Integer
lengthLL l = nbElmt (flattenLL l)

sumLL :: [[Integer]] -> Integer
-- sumLL ll adalah jumlah seluruh elemen di seluruh sublist ll

-- Helper
sumElmt :: [Integer] ->Integer
sumElmt [] = 0
sumElmt (x:xs) = x + sumElmt xs

sumLL l = 
    let listLL = flattenLL l
    in sumElmt listLL

maxLL :: [[Integer]] -> Integer
-- maxLL ll adalah elemen terbesar di seluruh sublist ll
-- Prasyarat: ll tidak kosong dan memuat sekurang-kurangnya satu elemen

-- Helper mencari nilai maksimum dari list biasa
maxElmt :: [Integer] -> Integer
maxElmt [x] = x
maxElmt (x:xs) = max x (maxElmt xs)

maxLL l = 
  let listLL = flattenLL l
  in maxElmt listLL
  
countEmpty :: [[a]] -> Integer
-- countEmpty ll adalah banyaknya sublist kosong di dalam ll
countEmpty [] = 0
countEmpty (l:ls)
  | null l    = 1 + countEmpty ls
  | otherwise = countEmpty ls

longestList :: [[a]] -> [a]
-- longestList ll adalah sublist terpanjang di ll; bila ada beberapa yang sama
-- panjang, ambil yang muncul lebih dulu
-- Prasyarat: ll tidak kosong
longestList [l] = l
longestList (l:ls)
  | length l >= length (longestList ls) = l
  | otherwise = longestList ls

filterNonEmpty :: [[a]] -> [[a]]
-- filterNonEmpty ll adalah ll tanpa sublist yang kosong, urutan tetap
filterNonEmpty [] = [] 
filterNonEmpty (l:ls)
  | null l    = filterNonEmpty ls
  | otherwise = l : filterNonEmpty ls

-- ===================================================================
-- Bagian B: Operasi baris dan kolom (matrix)
-- ===================================================================

isRectangular :: [[a]] -> Bool
-- isRectangular ll bernilai True bila seluruh sublist ll memiliki panjang sama
isRectangular [] = True
isRectangular [l] = True
isRectangular (l1:l2:ls) = length l1 == length l2 && isRectangular (l2:ls)

rowSums :: Matrix -> [Integer]
-- rowSums m adalah list jumlah elemen tiap baris m, urutan sesuai baris
rowSums [] = []
rowSums (row:rows) = sumRow row : rowSums rows
  where
    sumRow [] = 0
    sumRow (x:xs) = x + sumRow xs

colSums :: Matrix -> [Integer]
-- colSums m adalah list jumlah elemen tiap kolom m, urutan sesuai kolom
-- Prasyarat: m adalah matrix persegi panjang (isRectangular m == True)
colSums [] = []
colSums (row:rows)
  | null row  = []
  | otherwise = sumHeads (row:rows) : colSums (removeHeads (row:rows))
  where
    sumHeads [] = 0
    sumHeads ((x:_):rs) = x + sumHeads rs

    removeHeads [] = []
    removeHeads ((_:xs):rs) = xs : removeHeads rs

getRow :: Integer -> Matrix -> [Integer]
-- getRow i m adalah baris ke-i pada m
-- Basis-1
getRow = undefined

getColumn :: Integer -> Matrix -> [Integer]
-- getColumn j m adalah kolom ke-j pada m
-- Basis-1
-- Prasyarat: m adalah matrix persegi panjang
getColumn = undefined

transpose' :: [[a]] -> [[a]]
-- transpose' ll adalah transpos dari ll (baris menjadi kolom, kolom menjadi baris)
-- Prasyarat: ll adalah matrix persegi panjang
transpose' = undefined

-- ===================================================================
-- Bagian C: Pencarian dan keanggotaan
-- ===================================================================

memberLL :: Eq a => a -> [[a]] -> Bool
-- memberLL x ll bernilai True bila x muncul di salah satu sublist ll
memberLL = undefined

findRow :: Eq a => a -> [[a]] -> Integer
-- findRow x ll adalah nomor urut (mulai dari 1) sublist pertama yang memuat x;
-- bernilai 0 bila x tidak ditemukan di ll manapun
findRow = undefined

countOccurrences :: Eq a => a -> [[a]] -> Integer
-- countOccurrences x ll adalah banyaknya kemunculan x di seluruh sublist ll
countOccurrences = undefined

-- ===================================================================
-- Bagian D: Transformasi
-- ===================================================================

mapLL :: (a -> b) -> [[a]] -> [[b]]
-- mapLL f ll adalah ll yang setiap elemennya telah dikenai f, struktur sublist tetap
mapLL = undefined

scaleLL :: Integer -> Matrix -> Matrix
-- scaleLL k m adalah m yang setiap elemennya dikalikan k
scaleLL = undefined

addMatrix :: Matrix -> Matrix -> Matrix
-- addMatrix m1 m2 adalah hasil penjumlahan m1 dan m2 per posisi
-- Prasyarat: m1 dan m2 berukuran sama
addMatrix = undefined

reverseEach :: [[a]] -> [[a]]
-- reverseEach ll adalah ll yang urutan elemen tiap sublistnya dibalik,
-- urutan sublist di ll sendiri tetap
reverseEach = undefined

reverseLL :: [[a]] -> [[a]]
-- reverseLL ll adalah ll dengan urutan sublist dibalik, isi tiap sublist tetap
reverseLL = undefined

-- ===================================================================
-- Bagian E: Pengelompokan
-- ===================================================================

chunk :: Integer -> [a] -> [[a]]
-- chunk n l adalah l yang dipotong-potong menjadi sublist berukuran n;
-- potongan terakhir boleh lebih pendek dari n bila elemen l tidak habis dibagi n
-- Prasyarat: n > 0
chunk = undefined

groupConsecutive :: Eq a => [a] -> [[a]]
-- groupConsecutive l adalah l yang dikelompokkan sehingga elemen-elemen yang
-- sama dan berdampingan berada dalam satu sublist, urutan tetap
groupConsecutive = undefined

splitOnZero :: [Integer] -> [[Integer]]
-- splitOnZero l adalah l yang dipecah menjadi beberapa sublist, dipisahkan oleh
-- setiap kemunculan angka 0 (angka 0 sendiri tidak disertakan pada hasil)
splitOnZero = undefined

-- ===================================================================
-- Bagian F (bonus)
-- ===================================================================

diagonal :: Matrix -> [Integer]
-- diagonal m adalah elemen-elemen pada diagonal utama m
-- Prasyarat: m adalah matrix persegi (banyak baris = banyak kolom)
diagonal = undefined

rotate90 :: [[a]] -> [[a]]
-- rotate90 ll adalah ll yang telah diputar 90 derajat searah jarum jam
rotate90 = undefined

isSymmetric :: Matrix -> Bool
-- isSymmetric m bernilai True bila m sama dengan transposenya
-- Prasyarat: m adalah matrix persegi
isSymmetric = undefined