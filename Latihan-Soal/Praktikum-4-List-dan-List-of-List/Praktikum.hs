-- Praktikum: List of List — PEMBAHASAN
-- Berisi realisasi lengkap beserta penjelasan tiap fungsi.
-- Gaya rekursi mengikuti pola praktikum: dekomposisi pada elemen pertama
-- list terluar (head/tail), kecuali disebutkan lain.
-- Uji dengan: runghc PraktikumListOfList_Pembahasan.hs
module Praktikum where

type LL a = [[a]]     -- singkatan untuk "list of list"

-- ===================================================================
-- Bagian A — Properti dasar
-- ===================================================================

allEmpty :: [[a]] -> Bool
-- allEmpty l bernilai True bila seluruh sublist di l kosong
-- Basis-0: list kosong -> trivially True (vacuously true)
allEmpty [] = True
allEmpty (x:xs) = null x && allEmpty xs
-- Penjelasan: cek sublist pertama kosong (null x), lalu rekursi ke sisanya.
-- Karena && "malas" (short-circuit), begitu satu sublist tak kosong, langsung False.

anyEmpty :: [[a]] -> Bool
-- anyEmpty l bernilai True bila terdapat sublist di l yang kosong
-- Basis-0
anyEmpty [] = False
anyEmpty (x:xs) = null x || anyEmpty xs
-- Penjelasan: kebalikan logis dari allEmpty; cukup satu sublist kosong sudah True.

lengthsOf :: [[a]] -> [Integer]
-- lengthsOf l adalah list berisi panjang setiap sublist di l, urutan tetap
-- Basis-0
lengthsOf [] = []
lengthsOf (x:xs) = lenOf x : lengthsOf xs
  where
    lenOf :: [a] -> Integer
    lenOf [] = 0
    lenOf (_:ys) = 1 + lenOf ys
-- Penjelasan: lenOf menghitung panjang satu sublist secara rekursif (tanpa `length`
-- bawaan agar tipe langsung Integer), lalu dipetakan ke tiap sublist.

totalLength :: [[a]] -> Integer
-- totalLength l adalah banyaknya seluruh elemen di seluruh sublist l
-- Basis-0
totalLength [] = 0
totalLength (x:xs) = lenOf x + totalLength xs
  where
    lenOf :: [a] -> Integer
    lenOf [] = 0
    lenOf (_:ys) = 1 + lenOf ys
-- Penjelasan: sama seperti lengthsOf tapi hasilnya dijumlahkan langsung (fold),
-- bukan dikumpulkan sebagai list.

isRectangular :: [[a]] -> Bool
-- isRectangular l bernilai True bila seluruh sublist di l memiliki panjang yang sama
-- Basis-0 (list kosong) dan basis tambahan (satu sublist tersisa)
isRectangular [] = True
isRectangular [_] = True
isRectangular (x:y:xs) = length x == length y && isRectangular (y:xs)
-- Penjelasan: bandingkan dua sublist bertetangga; bila semua pasangan bertetangga
-- sama panjang, seluruh list otomatis sama panjang (relasi transitif).

-- ===================================================================
-- Bagian B — Transformasi
-- ===================================================================

flattenLL :: [[a]] -> [a]
-- flattenLL l adalah seluruh elemen l digabung jadi satu list, urutan tetap
-- Basis-0
flattenLL [] = []
flattenLL (x:xs) = x ++ flattenLL xs
-- Penjelasan: append sublist pertama ke hasil rekursi flatten sisanya.

mapEach :: (a -> b) -> [[a]] -> [[b]]
-- mapEach f l adalah l dengan f diterapkan ke setiap elemen di setiap sublist
-- Basis-0
mapEach _ [] = []
mapEach f (x:xs) = mapOne f x : mapEach f xs
  where
    mapOne :: (a -> b) -> [a] -> [b]
    mapOne _ [] = []
    mapOne g (y:ys) = g y : mapOne g ys
-- Penjelasan: mapOne adalah map manual untuk satu sublist; mapEach memetakannya
-- ke tiap sublist (dua lapis rekursi karena strukturnya dua lapis list).

filterEach :: (a -> Bool) -> [[a]] -> [[a]]
-- filterEach p l adalah l dengan setiap sublist disaring memakai predikat p
-- Basis-0
filterEach _ [] = []
filterEach p (x:xs) = filterOne p x : filterEach p xs
  where
    filterOne :: (a -> Bool) -> [a] -> [a]
    filterOne _ [] = []
    filterOne q (y:ys)
      | q y       = y : filterOne q ys
      | otherwise = filterOne q ys
-- Penjelasan: sama pola dua-lapis seperti mapEach, tapi elemen yang tidak lolos p
-- dibuang, bukan diganti.

reverseEach :: [[a]] -> [[a]]
-- reverseEach l membalik urutan elemen di dalam setiap sublist
-- Basis-0
reverseEach [] = []
reverseEach (x:xs) = revOnto x [] : reverseEach xs
  where
    revOnto :: [a] -> [a] -> [a]
    revOnto [] acc = acc
    revOnto (y:ys) acc = revOnto ys (y : acc)
-- Penjelasan: revOnto adalah reverse dengan akumulator (tail-recursive) untuk satu
-- sublist; urutan antar-sublist (list terluar) tidak diubah.

reverseLL :: [[a]] -> [[a]]
-- reverseLL l membalik urutan sublist (isi tiap sublist tidak berubah)
-- Basis-0
reverseLL [] = []
reverseLL (x:xs) = reverseLL xs ++ [x]
-- Penjelasan: kebalikan dari reverseEach — yang dibalik urutan list terluarnya,
-- bukan isinya. Rekursi sisa dulu, sublist pertama ditaruh di ujung.

-- ===================================================================
-- Bagian C — Agregasi numerik
-- ===================================================================

sumEach :: [[Integer]] -> [Integer]
-- sumEach l adalah list berisi jumlah elemen tiap sublist di l
-- Basis-0
sumEach [] = []
sumEach (x:xs) = sumOf x : sumEach xs
  where
    sumOf :: [Integer] -> Integer
    sumOf [] = 0
    sumOf (y:ys) = y + sumOf ys
-- Penjelasan: sumOf menjumlahkan satu sublist; sumEach memetakannya ke tiap sublist.

sumAll :: [[Integer]] -> Integer
-- sumAll l adalah jumlah seluruh elemen di seluruh sublist l
-- Basis-0
sumAll [] = 0
sumAll (x:xs) = sumOf x + sumAll xs
  where
    sumOf :: [Integer] -> Integer
    sumOf [] = 0
    sumOf (y:ys) = y + sumOf ys
-- Penjelasan: sama seperti sumEach tapi hasil akhirnya satu angka (fold total).
-- Bisa juga ditulis sebagai `sumAll = sum . map sum` (built-in), tapi di sini
-- ditulis eksplisit rekursif sesuai pola praktikum.

maxEach :: [[Integer]] -> [Integer]
-- maxEach l adalah list berisi elemen terbesar tiap sublist
-- Prasyarat: setiap sublist di l tidak kosong
-- Basis-0
maxEach [] = []
maxEach (x:xs) = maxOf x : maxEach xs
  where
    maxOf :: [Integer] -> Integer
    maxOf [y] = y
    maxOf (y:ys) = max y (maxOf ys)
    maxOf [] = error "maxOf: sublist kosong"
-- Penjelasan: maxOf membandingkan elemen pertama dengan maksimum sisanya (basis-1
-- untuk satu elemen). Prasyarat sublist tak kosong menghindari kasus [].

maxAll :: [[Integer]] -> Integer
-- maxAll l adalah elemen terbesar di seluruh elemen l
-- Prasyarat: l tidak kosong dan setiap sublist di l tidak kosong
maxAll l = maxOf (maxEach l)
  where
    maxOf :: [Integer] -> Integer
    maxOf [y] = y
    maxOf (y:ys) = max y (maxOf ys)
    maxOf [] = error "maxOf: list kosong"
-- Penjelasan: manfaatkan maxEach untuk mendapat maksimum tiap baris, lalu cari
-- maksimum dari kumpulan maksimum tersebut — hasilnya maksimum global.

-- ===================================================================
-- Bagian D — Pencarian
-- ===================================================================

countElemLL :: Integer -> [[Integer]] -> Integer
-- countElemLL x l adalah banyaknya kemunculan x di seluruh sublist l
-- Basis-0
countElemLL _ [] = 0
countElemLL x (y:ys) = countIn x y + countElemLL x ys
  where
    countIn :: Integer -> [Integer] -> Integer
    countIn _ [] = 0
    countIn v (z:zs)
      | v == z    = 1 + countIn v zs
      | otherwise = countIn v zs
-- Penjelasan: countIn menghitung kemunculan x pada satu sublist; hasilnya
-- dijumlahkan untuk seluruh sublist.

memberLL :: Integer -> [[Integer]] -> Bool
-- memberLL x l bernilai True bila x muncul di salah satu sublist l
-- Basis-0
memberLL _ [] = False
memberLL x (y:ys) = memberIn x y || memberLL x ys
  where
    memberIn :: Integer -> [Integer] -> Bool
    memberIn _ [] = False
    memberIn v (z:zs) = v == z || memberIn v zs
-- Penjelasan: bisa juga didefinisikan sebagai `countElemLL x l > 0`, tapi versi
-- ini berhenti lebih awal (short-circuit) begitu ditemukan.

findRow :: Integer -> [[Integer]] -> Integer
-- findRow x l adalah nomor urut (mulai dari 1) sublist pertama yang memuat x;
-- 0 bila x tidak ditemukan
-- Basis-0
findRow x l = go x l 1
  where
    go :: Integer -> [[Integer]] -> Integer -> Integer
    go _ [] _ = 0
    go v (r:rs) i
      | memberIn v r = i
      | otherwise    = go v rs (i + 1)
    memberIn :: Integer -> [Integer] -> Bool
    memberIn _ [] = False
    memberIn w (z:zs) = w == z || memberIn w zs
-- Penjelasan: go membawa akumulator nomor baris i (basis-1) yang bertambah
-- setiap rekursi maju ke sublist berikutnya.

-- ===================================================================
-- Bagian E — Struktur (gaya matriks)
-- ===================================================================

rowAt :: Integer -> [[a]] -> [a]
-- rowAt i l adalah sublist ke-i pada l (basis-1)
-- Basis-1
rowAt 1 (x:_) = x
rowAt i (_:xs) = rowAt (i - 1) xs
rowAt _ [] = error "rowAt: indeks di luar jangkauan"
-- Penjelasan: turunkan i sambil membuang sublist di depan, sampai i == 1.

colAt :: Integer -> [[a]] -> [a]
-- colAt j l adalah kolom ke-j dari l (elemen ke-j tiap sublist), basis-1
-- Prasyarat: l rectangular
-- Basis-0
colAt _ [] = []
colAt j (x:xs) = elemAt j x : colAt j xs
  where
    elemAt :: Integer -> [a] -> a
    elemAt 1 (y:_) = y
    elemAt n (_:ys) = elemAt (n - 1) ys
    elemAt _ [] = error "colAt: indeks di luar jangkauan"
-- Penjelasan: untuk tiap sublist (baris), ambil elemen ke-j; dikumpulkan jadi
-- satu list yang merepresentasikan kolom ke-j.

transposeLL :: [[a]] -> [[a]]
-- transposeLL l adalah transpos dari l (baris menjadi kolom)
-- Prasyarat: l rectangular
transposeLL [] = []
transposeLL l@(x:_)
  | null x    = []
  | otherwise = colAt 1 l : transposeLL (dropFirstCol l)
  where
    dropFirstCol :: [[a]] -> [[a]]
    dropFirstCol [] = []
    dropFirstCol (r:rs) = tail r : dropFirstCol rs
-- Penjelasan: basis berhenti ketika sublist pertama sudah habis kolomnya
-- (semua baris sudah kosong, karena rectangular). Tiap langkah mengambil
-- "kolom depan" (colAt 1) lalu membuang kolom itu dari setiap baris, dan
-- berulang untuk kolom berikutnya.

diagonal :: [[a]] -> [a]
-- diagonal l adalah elemen diagonal utama l (elemen ke-i pada sublist ke-i)
-- Prasyarat: l rectangular dan berbentuk persegi
-- Basis-1
diagonal l = go 1 l
  where
    go :: Integer -> [[a]] -> [a]
    go _ [] = []
    go i (r:rs) = elemAt i r : go (i + 1) rs
    elemAt :: Integer -> [a] -> a
    elemAt 1 (y:_) = y
    elemAt n (_:ys) = elemAt (n - 1) ys
    elemAt _ [] = error "diagonal: indeks di luar jangkauan"
-- Penjelasan: go membawa akumulator posisi baris i yang juga dipakai sebagai
-- indeks kolom yang diambil dari baris tersebut — persis definisi diagonal utama.

-- ===================================================================
-- Bagian F — Menggabungkan dua list of list
-- ===================================================================

zipRowsWith :: (a -> b -> c) -> [[a]] -> [[b]] -> [[c]]
-- zipRowsWith f l1 l2 menerapkan f sejajar per elemen antar sublist bersesuaian;
-- kelebihan elemen/sublist yang tidak berpasangan diabaikan
-- Basis-0
zipRowsWith _ [] _ = []
zipRowsWith _ _ [] = []
zipRowsWith f (x:xs) (y:ys) = zipOne f x y : zipRowsWith f xs ys
  where
    zipOne :: (a -> b -> c) -> [a] -> [b] -> [c]
    zipOne _ [] _ = []
    zipOne _ _ [] = []
    zipOne g (p:ps) (q:qs) = g p q : zipOne g ps qs
-- Penjelasan: zipOne adalah zipWith manual untuk sepasang sublist; zipRowsWith
-- memetakannya ke pasangan sublist yang bersesuaian, berhenti di list terpendek.

appendPairwise :: [[a]] -> [[a]] -> [[a]]
-- appendPairwise l1 l2 menggabungkan sublist ke-i pada l1 dengan sublist ke-i pada l2;
-- sisa sublist dari list yang lebih panjang disertakan apa adanya
-- Basis-0
appendPairwise [] l2 = l2
appendPairwise l1 [] = l1
appendPairwise (x:xs) (y:ys) = (x ++ y) : appendPairwise xs ys
-- Penjelasan: berbeda dari zipRowsWith yang berhenti di list terpendek,
-- appendPairwise tetap menyertakan sisa sublist milik list yang lebih panjang
-- (basis pada [] salah satu argumen mengembalikan argumen lainnya utuh).

concatLL :: [[a]] -> [[a]] -> [[a]]
-- concatLL l1 l2 adalah seluruh sublist l1 diikuti seluruh sublist l2
-- Basis-0
concatLL [] l2 = l2
concatLL (x:xs) l2 = x : concatLL xs l2
-- Penjelasan: append biasa pada list terluar; sublist itu sendiri (elemen a-nya)
-- tidak disentuh sama sekali, hanya "dijajarkan".

-- ===================================================================
-- Bagian G — Bonus
-- ===================================================================

longestRow :: [[a]] -> [a]
-- longestRow l adalah sublist terpanjang di l; bila seri, ambil yang pertama
-- Prasyarat: l tidak kosong
-- Basis-1
longestRow [x] = x
longestRow (x:xs)
  | lenOf x >= lenOf rest = x
  | otherwise             = rest
  where
    rest = longestRow xs
    lenOf :: [a] -> Integer
    lenOf [] = 0
    lenOf (_:ys) = 1 + lenOf ys
-- Penjelasan: bandingkan sublist pertama dengan hasil terbaik dari sisa list;
-- pakai `>=` (bukan `>`) supaya yang pertama menang bila terjadi seri.

removeEmptyRows :: [[a]] -> [[a]]
-- removeEmptyRows l adalah l tanpa sublist-sublist yang kosong, urutan tetap
-- Basis-0
removeEmptyRows [] = []
removeEmptyRows (x:xs)
  | null x    = removeEmptyRows xs
  | otherwise = x : removeEmptyRows xs
-- Penjelasan: filter biasa pada list terluar, predikatnya "bukan sublist kosong".