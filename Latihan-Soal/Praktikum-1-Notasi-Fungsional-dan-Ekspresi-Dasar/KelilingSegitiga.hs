module KelilingSegitiga where
    import JarakTitik (distance)
    
    -- Definisi 
    -- Fungsi untuk menghitung keliling segitiga dari koordinat 3 titik yang diketahui
    -- Prasyarat: ketika titik koordinat membentuk segitiga valid
    toKeliling :: Double -> Double -> Double -> Double -> Double -> Double -> Double 

    -- Realisasi
    toKeliling px py x1 y1 x2 y2 = distance px py x1 y1 + distance x1 y1 x2 y2 + distance x2 y2 px py

    -- Implementasi
    -- toKeliling 0.0 0.0 3.0 0.0 0.0 4.0 = 12.0




    
    
    