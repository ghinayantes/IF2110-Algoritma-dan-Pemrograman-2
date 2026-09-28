module Main where

-- 1. Menghitung panjang list
length' :: [a] -> Integer
length' []       = 0
length' (_ : xs) = 1 + length' xs

-- 2. Memeriksa apakah x merupakan anggota dari list
isMember :: Eq a => a -> [a] -> Bool
isMember _ []       = False
isMember x (y : ys) = y == x || isMember x ys

-- 3. Menyaring dan menyisakan elemen yang bernilai positif
keepPositive :: [Integer] -> [Integer]
keepPositive []       = []
keepPositive (x : xs)
  | x > 0     = x : keepPositive xs
  | otherwise = keepPositive xs

-- Main function untuk pengujian/testing
main :: IO ()
main = do
  let angka = [-3, 5, 0, -2, 8, 10]
  
  putStrLn "=== UJI COBA FUNGSI HASKELL ==="
  putStrLn $ "List awal: " ++ show angka
  putStrLn $ "1. Length: " ++ show (length' angka)
  putStrLn $ "2. Apakah 8 ada di list? " ++ show (isMember 8 angka)
  putStrLn $ "   Apakah 9 ada di list? " ++ show (isMember 9 angka)
  putStrLn $ "3. Elemen positif saja: " ++ show (keepPositive angka)