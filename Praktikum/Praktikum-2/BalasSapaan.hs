module BalasSapaan where

-- KODE JURNAL
-- DEFINISI DAN SPESIFIKASI
sing :: String -> String
-- sing x membalas sapaan dari input string x dengan pemetaan yang telah ditentukan

-- REALISASI
sing input 
    | (input == "halo") = "hi"
    | (input == "hi") = "halo"
    | (input == "bunda") = "ayah"
    | (input == "ayah") = "bunda"
    | (input == "pagi") = "sore"
    | (input == "sore") = "pagi"
    | (input == "siang") = "malam"
    | (input == "malam") = "siang"
    | (input == "kiri") = "kanan"
    | (input == "kanan") = "kiri"
    | (input == "atas") = "bawah"
    | (input == "bawah") = "atas"
    | otherwise = "tidak dikenali"


-- APLIKASI
-- sing "halo"