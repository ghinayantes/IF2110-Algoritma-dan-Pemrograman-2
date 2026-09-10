module JarakTitik where
    sqrDif :: Double -> Double -> Double
    -- sqrDif a b adalah kuadrat dari selisih a dan b
    sqrDif a b = (a - b) * (a - b)

    distance :: Double -> Double -> Double -> Double -> Double
    -- distance x1 y1 x2 y2 adalah jarak antara titik (x1,y1) dan (x2,y2)
    distance x1 y1 x2 y2 = sqrt (sqrDif x1 x2 + sqrDif y1 y2)
