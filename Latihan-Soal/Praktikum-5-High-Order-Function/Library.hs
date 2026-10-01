module Library where

data Book = Book { bookTitle :: String, author :: String, copies :: Int }
    deriving (Show, Eq)

type Library = [Book]

-- 1. Fungsi borrowBook
-- Mengurangi atribut `copies` sebesar 1 untuk buku dengan `bookTitle` target
-- (Asumsikan copies selalu cukup / > 0).
-- Hint: Gunakan `map` dan lambda
borrowBook :: String -> Library -> Library
borrowBook targetTitle library = 
    let updateBook = \b ->
            if bookTitle b == targetTitle then b {copies = copies b - 1}
            else b
    in map updateBook library

-- 2. Fungsi totalCopiesByAuthor
-- Menghitung total jumlah eksemplar (`copies`) dari semua buku yang ditulis oleh `targetAuthor`.
-- Hint: Kombinasikan `filter`, `map`, dan `sum` (atau gunakan `foldr`)
totalCopiesByAuthor :: String -> Library -> Int
totalCopiesByAuthor targetAuthor library = sum (map copies (filter (\b -> author b == targetAuthor) library))

-- 3. Fungsi updateAuthorName
-- Mengubah nama penulis `oldAuthor` menjadi `newAuthor` untuk semua buku karangan penulis tersebut.
-- Hint: Gunakan `map` dan lambda
updateAuthorName :: String -> String -> Library -> Library
updateAuthorName oldAuthor newAuthor library = 
    let updateBook = \b ->
            if author b == oldAuthor then b {author = newAuthor}
            else b 
    in map updateBook library

-- APLIKASI
-- ====================================================================
-- TEST CASE SOAL 4 (Library)
-- ====================================================================
sampleLibrary :: Library
sampleLibrary = 
    [ Book "Haskell Basics" "John Doe" 5
    , Book "Advanced Haskell" "John Doe" 3
    , Book "Learn Python" "Jane Smith" 10
    ]

-- Test borrowBook:
-- borrowBook "Haskell Basics" sampleLibrary
-- EXPECTED: Buku "Haskell Basics" atribut copies-nya berkurang dari 5 menjadi 4.

-- Test totalCopiesByAuthor:
-- totalCopiesByAuthor "John Doe" sampleLibrary
-- EXPECTED: 8

-- Test updateAuthorName:
-- updateAuthorName "John Doe" "J. Doe" sampleLibrary
-- EXPECTED: Penulis "John Doe" pada kedua buku pertama berubah menjadi "J. Doe".