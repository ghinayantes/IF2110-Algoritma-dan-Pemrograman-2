module KasirMysteryShack where

import Control.Monad (replicateM)

-- KASIR MYSTERY SHACK
-- Lengkapi kasir, subtotal, dan totalHarga. Fungsi pembantu I/O sudah disediakan.
-- subtotal dan totalHarga adalah fungsi murni: hasilnya hanya ditentukan oleh argumen,
-- tanpa membaca masukan atau mencetak keluaran. kasir menangani aksi I/O.
-- UTILITY FUNCTIONS
-- Bagian ini sudah disediakan. JANGAN DIUBAH.

bacaBarang :: IO (String, Integer, Integer)
-- bacaBarang membaca satu baris barang dan menghasilkan tuple (nama, harga, jumlah).
-- Baris pertama yang berisi n tidak dibaca oleh fungsi ini.
bacaBarang = do
    baris <- getLine
    return (parseBarang baris)

cetakStruk :: [(String, Integer, Integer)] -> IO ()
-- cetakStruk daftar mencetak subtotal tiap barang dan total belanja.
-- Perhitungannya memakai fungsi subtotal dan totalHarga yang Anda lengkapi.
cetakStruk daftar = do
    mapM_ putStrLn (map cetakBarang daftar)
    putStrLn ("Total: " ++ show (totalHarga daftar))

parseBarang :: String -> (String, Integer, Integer)
parseBarang s = case words s of
    [nama, harga, jumlah] -> (nama, read harga, read jumlah)
    _                     -> error "format barang salah"

cetakBarang :: (String, Integer, Integer) -> String
cetakBarang (nama, harga, jumlah) = nama ++ ": " ++ show (subtotal harga jumlah)

-- DEFINISI DAN SPESIFIKASI
kasir :: IO ()
-- kasir membaca bilangan n pada baris pertama, lalu membaca n barang memakai bacaBarang.
-- Setelah semua barang dibaca, cetak struk memakai cetakStruk.
-- Jika n = 0, struk hanya berisi "Total: 0".
-- Petunjuk: replicateM n aksi mengulang aksi n kali dan mengumpulkan hasilnya sebagai list.
-- Banyaknya pengulangan pada replicateM bertipe Int.

subtotal :: Integer -> Integer -> Integer
-- subtotal harga jumlah menghasilkan harga satuan dikalikan jumlah yang dibeli.

totalHarga :: [(String, Integer, Integer)] -> Integer
-- totalHarga daftar menghasilkan jumlah seluruh subtotal barang dalam daftar.
-- Setiap barang berupa tuple (nama, harga, jumlah). Jika daftar kosong, hasilnya 0.

-- REALISASI
kasir = do
    n <- readLn :: IO Integer
    daftar <- replicateM (fromIntegral n) bacaBarang
    cetakStruk daftar



subtotal harga jumlah = harga * jumlah

totalHarga [] = 0
totalHarga ((_, harga, jumlah):xs) = subtotal harga jumlah + totalHarga xs

-- APLIKASI
-- > subtotal 5 4
-- 20
-- > totalHarga [("permen",5,4),("topi",120,1),("stiker",2,10)]