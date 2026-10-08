module PenyambutNangor where

-- PENYAMBUT NANGOR
-- Ini adalah soal pertama yang memakai I/O (membaca dan mencetak).
-- DEFINISI DAN SPESIFIKASI
sambut :: IO ()
-- sambut adalah aksi I/O yang membaca dua baris dari input standar:
-- - Baris pertama berisi nama pengunjung (satu baris penuh, boleh mengandung spasi).
-- - Baris kedua berisi bilangan bulat n, nomor urut pengunjung.
-- sambut mencetak satu baris: Halo, <nama>! Kamu pengunjung ke-<n>.

-- REALISASI
sambut = do
    nama <- getLine 
    n <- readLn :: IO Integer
    putStrLn ("Halo, " ++ nama ++ "! Kamu pengunjung ke-" ++ show n ++ ".")

-- APLIKASI
-- Misalkan input standar berisi:
-- Dipper
-- 1
--
-- Maka sambut mencetak:
-- Halo, Dipper! Kamu pengunjung ke-1.
--
-- Misalkan input standar berisi:
-- Mabel Pines
-- 42
--
-- Maka sambut mencetak:
-- Halo, Mabel Pines! Kamu pengunjung ke-42.

-- Petunjuk: gunakan notasi do untuk merangkai aksi, misalnya
-- x <- getLine    membaca satu baris dan menamainya x (bertipe String)
-- n <- readLn :: IO Integer    membaca satu baris berisi bilangan bulat
-- putStrLn s      mencetak s lalu pindah baris
-- show n          mengubah bilangan menjadi teks; ++ menyambung teks
