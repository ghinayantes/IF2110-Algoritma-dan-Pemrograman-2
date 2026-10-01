module Inventory where

-- Data type untuk Item
data Item = Item { itemName :: String, category :: String, price :: Double }
    deriving (Show, Eq)

type Inventory = [Item]

-- 1. Constructor function menggunakan lambda
-- Parameter: itemName, category, price -> Item
makeItem :: String -> String -> Double -> Item
makeItem = (\itemName category price -> Item itemName category price)

-- 2. Fungsi applyDiscount
-- Mengurangi harga sebesar persen tertentu (persen dalam desimal, misal 0.2 untuk diskon 20%)
-- hanya untuk barang yang berada pada kategori target Category.
-- Hint: Gunakan `map` dan lambda
applyDiscount :: String -> Double -> Inventory -> Inventory
applyDiscount targetCategory discountPercent inventory = 
    let updateItem = \i ->
            if category i == targetCategory then i {price = price i * (1 - discountPercent)}
            else i 
    in map updateItem inventory

-- 3. Fungsi filterByPriceRange
-- Menyaring barang yang harganya berada di antara minPrice dan maxPrice (inklusif).
-- Hint: Gunakan `filter` dan lambda
filterByPriceRange :: Double -> Double -> Inventory -> Inventory
filterByPriceRange minPrice maxPrice inventory = filter (\i -> (price i) >= minPrice && (price i) <= maxPrice) inventory

-- TEST CASE SOAL 1 (Inventory)
-- ====================================================================
sampleInventory :: Inventory
sampleInventory = 
    [ makeItem "Laptop" "Electronics" 1000.0
    , makeItem "Mouse" "Electronics" 25.0
    , makeItem "Shirt" "Apparel" 50.0
    ]

-- Test applyDiscount:
-- applyDiscount "Electronics" 0.1 sampleInventory
-- EXPECTED:
-- [ Item {itemName = "Laptop", category = "Electronics", price = 900.0}
-- , Item {itemName = "Mouse", category = "Electronics", price = 22.5}
-- , Item {itemName = "Shirt", category = "Apparel", price = 50.0}
-- ]

-- Test filterByPriceRange:
-- filterByPriceRange 20.0 100.0 sampleInventory
-- EXPECTED:
-- [ Item {itemName = "Mouse", category = "Electronics", price = 25.0}
-- , Item {itemName = "Shirt", category = "Apparel", price = 50.0}
-- ]