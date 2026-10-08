module PohonNangor where

-- POHON NANGOR FALLS
-- UTILITY FUNCTIONS
-- Type dan fungsi pembantu yang dipakai oleh driver Olympia. JANGAN DIUBAH.
-- Pohon biner: Kosong, atau Simpul <upapohon kiri> <info> <upapohon kanan>
data Pohon = Kosong | Simpul Pohon Integer Pohon
    deriving Show

-- preorder t menghasilkan list info pohon t dengan urutan: akar, kiri, kanan
preorder :: Pohon -> [Integer]
preorder Kosong = []
preorder (Simpul l v r) = v : (preorder l ++ preorder r)

-- inorder t menghasilkan list info pohon t dengan urutan: kiri, akar, kanan
inorder :: Pohon -> [Integer]
inorder Kosong = []
inorder (Simpul l v r) = inorder l ++ [v] ++ inorder r

-- DEFINISI DAN SPESIFIKASI
sisipPohon :: Integer -> Pohon -> Pohon
-- sisipPohon x t menyisipkan x ke dalam pohon pencarian biner t dan menghasilkan pohon baru.
-- Pohon pencarian biner: untuk setiap Simpul l v r, semua info pada l < v dan semua info pada r > v.
-- - Jika t kosong, hasilnya adalah pohon dengan satu simpul berisi x.
-- - Jika x < info akar, x disisipkan ke upapohon kiri.
-- - Jika x > info akar, x disisipkan ke upapohon kanan.
-- - Jika x sama dengan info akar, pohon tidak berubah (tidak ada nilai ganda).
-- Bagian pohon lain yang tidak dilewati penyisipan harus tetap sama.

-- REALISASI
sisipPohon x Kosong = Simpul Kosong x Kosong
sisipPohon x t@(Simpul l v r) 
    | x < v = (Simpul (sisipPohon x l) v r)
    | x > v = (Simpul l v (sisipPohon x r))
    | otherwise = t

-- APLIKASI
-- > sisipPohon 3 Kosong
-- Simpul Kosong 3 Kosong
--
-- > sisipPohon 3 (Simpul Kosong 5 Kosong)
-- Simpul (Simpul Kosong 3 Kosong) 5 Kosong
--
-- > sisipPohon 8 (Simpul (Simpul Kosong 3 Kosong) 5 Kosong)
-- Simpul (Simpul Kosong 3 Kosong) 5 (Simpul Kosong 8 Kosong)
--
-- > sisipPohon 5 (Simpul Kosong 5 Kosong)
-- Simpul Kosong 5 Kosong
--
-- > inorder (foldr sisipPohon Kosong [7,4,8,1,3,5])
-- [1,3,4,5,7,8]
