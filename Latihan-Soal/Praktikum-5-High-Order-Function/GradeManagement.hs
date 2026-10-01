module GradeManagement where

data Student = Student { studentName :: String, studentId :: Int, score :: Double }
    deriving (Show, Eq)

type ClassRoster = [Student]

-- 1. Fungsi updateScore
-- Mengubah nilai mahasiswa yang memiliki studentId sesuai target dengan nilai baru.
-- Hint: Gunakan `map` dan lambda
updateScore :: Int -> Double -> ClassRoster -> ClassRoster
updateScore targetId newScore roster = 
    let updateStudent = \s ->
            if studentId s == targetId then s {score = newScore}
            else s
    in map updateStudent roster

-- 2. Fungsi filterPassing
-- Mengembalikan daftar mahasiswa yang nilainya >= passingGrade.
-- Hint: Gunakan `filter` dan lambda
filterPassing :: Double -> ClassRoster -> ClassRoster
filterPassing passingGrade roster = 
    let lulus = (filter (\s -> score s >= passingGrade) roster)
    in lulus

isEmpty :: [a] -> Bool
isEmpty l = null l

-- 3. Fungsi averageScore
-- Menghitung nilai rata-rata dari seluruh mahasiswa di dalam ClassRoster.
-- Jika roster kosong, kembalikan 0.0.
-- Hint: Gunakan `map`, `sum`, `fromIntegral`, dan `length`
averageScore :: ClassRoster -> Double
averageScore roster = 
    if isEmpty roster then 0.0
    else let total = sum (map score roster)
        in total / fromIntegral (length roster)
            
-- APLIKASI
-- ====================================================================
-- TEST CASE SOAL 2 (Grade Management)
-- ====================================================================
sampleRoster :: ClassRoster
sampleRoster = 
    [ Student "Alice" 101 85.0
    , Student "Bob" 102 55.0
    , Student "Charlie" 103 70.0
    ]

-- Test updateScore:
-- updateScore 102 65.0 sampleRoster
-- EXPECTED:
-- [ Student {studentName = "Alice", studentId = 101, score = 85.0}
-- , Student {studentName = "Bob", studentId = 102, score = 65.0}
-- , Student {studentName = "Charlie", studentId = 103, score = 70.0}
-- ]

-- Test filterPassing:
-- filterPassing 70.0 sampleRoster
-- EXPECTED:
-- [ Student {studentName = "Alice", studentId = 101, score = 85.0}
-- , Student {studentName = "Charlie", studentId = 103, score = 70.0}
-- ]

-- Test averageScore:
-- averageScore sampleRoster
-- EXPECTED: 70.0