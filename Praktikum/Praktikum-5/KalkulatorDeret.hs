module KalkulatorDeret where

-- UTILITY FUNCTIONS
-- Fungsi pembantu yang dipakai oleh driver Olympia. JANGAN DIUBAH.
-- Anda juga dapat memakai fungsi untuk mencoba realisasi di ghci, misalnya:
-- sigma 1 5 (fungsi "id") (fungsi "tambah1")
-- Nama fungsi yang tersedia: "id", "kuadrat", "kubik", "linear", "tambah1", "tambah2", "tambah5", "ganda"
fungsi :: String -> (Integer -> Integer)
fungsi "id"      = \x -> x
fungsi "kuadrat" = \x -> x * x
fungsi "kubik"   = \x -> x * x * x
fungsi "linear"  = \x -> 3 * x + 1
fungsi "tambah1" = \x -> x + 1
fungsi "tambah2" = \x -> x + 2
fungsi "tambah5" = \x -> x + 5
fungsi "ganda"   = \x -> 2 * x
fungsi _         = \x -> x


-- SIGMA
-- DEFINISI DAN SPESIFIKASI
sigma :: Integer -> Integer -> (Integer -> Integer) -> (Integer -> Integer) -> Integer
-- Fungsi rekursif sigma menerima batas bawah a, batas atas b, fungsi suku f, dan fungsi langkah s, lalu mengembalikan jumlah f(a) + f(s(a)) + f(s(s(a))) + ... dengan hanya mengambil nilai a, s(a), s(s(a)), ... yang tidak melebihi b. Jika a > b, hasilnya adalah 0. Fungsi s selalu memenuhi s(x) > x, sehingga deret pasti berhenti.

-- REALISASI
sigma a b f s  
    | a > b = 0
    | otherwise = f a + sigma (s a) b f s


-- APLIKASI
-- sigma 1 5 (\x -> x) (\x -> x + 1)
-- 15
-- - nilai yang diambil: 1, 2, 3, 4, 5
-- - 1 + 2 + 3 + 4 + 5 = 15
--
-- sigma 1 10 (\x -> x * x) (\x -> x + 2)
-- 165
-- - nilai yang diambil: 1, 3, 5, 7, 9 (11 melebihi 10)
-- - 1 + 9 + 25 + 49 + 81 = 165
--
-- sigma 5 4 (\x -> x) (\x -> x + 1)
-- 0
-- - a > b, sehingga tidak ada suku yang dijumlahkan


-- ULANG
-- DEFINISI DAN SPESIFIKASI
ulang :: Int -> (a -> a) -> (a -> a)
-- Fungsi rekursif ulang menerima bilangan n dan sebuah fungsi f, lalu mengembalikan fungsi baru yang menerapkan f sebanyak n kali. Jika n = 0, fungsi yang dikembalikan tidak mengubah nilai yang diberikan.
-- Prasyarat: n >= 0

-- REALISASI
ulang 0 f = id
ulang n f = f . (ulang (n-1) f)

-- atau:
-- ulang 0 f = \x -> x
-- ulang n f = \x -> f (ulang (n - 1) f x)

-- APLIKASI
-- ulang 3 (\x -> 2 * x) 5