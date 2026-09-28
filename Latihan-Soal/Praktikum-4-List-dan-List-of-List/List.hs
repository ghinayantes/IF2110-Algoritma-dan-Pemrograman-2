module List where
-- KONSTRUKTOR
    konso :: Integer -> [Integer] -> [Integer] -- menambahkan elemen di depan list
    konsDot :: Integer -> [Integer] -> [Integer] -- menambahkan elemen di belakang list

-- SELEKTOR
    firstElmt :: [Integer] -> Integer
    lastElmt :: [Integer] -> Integer
    ambilHead :: [Integer] -> [Integer]
    ambilTail :: [Integer] -> [Integer]

-- PREDIKAT
    isEmpty :: [Integer] -> Bool
    isOneElmt ::  [Integer] -> Bool
    isMember :: Integer -> [Integer] -> Bool
    isEqual :: [Integer] -> [Integer] -> Bool
    isXElmtKeN :: Integer -> Integer -> [Integer] -> Bool

-- FUNGSI LAIN
    nbElmt :: [Integer] -> Integer  
    copy :: [Integer] -> [Integer]
    konkat :: [Integer] -> [Integer] -> [Integer]
    elmtKeN :: Integer -> [Integer] -> Integer
    maxList :: [Integer] -> Integer
    maxNb :: [Integer] -> (Integer, Integer)
    -- Fungsi menghasilkan nilai maksimum dan jumlah kemunculan nilai maksimum tsb pd list bilangan integer

-- REALISASI
    konso e l = [e] ++ l
    konsDot e l = l ++ [e]

    firstElmt [] = error "List kosong"
    firstElmt (x:xs) = x

    lastElmt [] = error "list kosong"
    lastElmt [x] = x
    lastElmt (x:xs) = lastElmt xs
                                                                                                           
    ambilHead [] = []                -- Jika list kosong, kembalikan kosong                                                       
    ambilHead [x] = []                -- Jika tinggal 1 elemen terakhir, buang (hasil [])                                          
    ambilHead (x:xs) = x : ambilHead xs  -- Simpan elemen depan (x), sambung rekursif ke sisanya (xs)     

    ambilTail [] = []
    ambilTail [x] = []
    ambilTail (x:xs) = xs


    isEmpty l = if l == [] then True else False

    isOneElmt l = if length l == 0 then False
                    else if length l == 1 then True
                        else False

    isMember _ [] = False                                                                                                     
    isMember x (y:ys) = (x == y) || isMember x ys 

    isEqual l1 l2 = if l1 == l2 then True else False

    -- ALTERNATIF isEqual
    -- isEqual l1 l2
    -- | (isEmpty l1) && (isEmpty l2) = True -- Basis
    -- | (isEmpty l1) && not (isEmpty l2) = False -- Basis
    -- | not (isEmpty l1) && (isEmpty l2) = False -- Basis
    -- | not (isEmpty l1) && not (isEmpty l2) = -- Recc
    -- ( (head l1)==(head l2) && (isEqual (tail l1) (tail l2))

    isXElmtKeN _ _ [] = error "list kosong"
    isXElmtKeN x 1 (bx:xs) = False
    isXElmtKeN x n l
        | n > (nbElmt l) = error "indeks melebihi panjang list"
        | elmtKeN n l == x = True
        | otherwise = isXElmtKeN x (n-1) (ambilTail l)

    nbElmt [] = 0                   -- Basis: list kosong panjangnya 0                                                            
    nbElmt (x:xs) = 1 + nbElmt xs   -- Rekurens: 1 ditambah panjang sisa list  

    -- ALTERNATIF isMember
    -- isMember x l = 
    --    if isEmpty l then False
    --    else if firstElmt l == x then True
    --    else isMember x (tail l) 

    copy l = if (isEmpty l) then [] -- Basis
            else (konso (firstElmt l) (copy (ambilTail l))) -- Rekurens

    konkat l1 l2 = if isEmpty l1 then l2 
                    else (konso (firstElmt l1) (konkat (ambilTail l1) l2))

    -- ALTERNATIF konkat
    -- konkat [] ys     = ys                                                                                                             
    -- konkat (x:xs) ys = x : konkat xs ys     

    elmtKeN _ [] = error "list kosong"
    elmtKeN 1 (x:xs) = x
    elmtKeN n l 
        | n > (nbElmt l) = error "indeks melebihi panjang list"
        | otherwise = elmtKeN (n-1) (ambilTail l)
                                                                                               
    maxList [] = error "list kosong"
    maxList l =                                                                                                                       
        let                                                                                                                           
            -- Definisi fungsi lokal max2                                                                                             
            max2 a b = if a > b then a else b                                                                                         
        in                                                                                                                            
            if isOneElmt l then lastElmt l                                                                                                            
            else max2 (lastElmt l) (maxList (ambilHead l))    

    -- HELPER
    maxNb [] = error "list kosong"                                                                                                    
    maxNb l =                                                                                                                         
        let countX _ [] = 0                                                                                                           
            countX x lst = if firstElmt lst == x                                                                                      
                           then 1 + countX x (ambilTail lst)                                                                          
                           else countX x (ambilTail lst)                                                                              
            m = maxList l                                                                                                             
        in (m, countX m l)                                 
