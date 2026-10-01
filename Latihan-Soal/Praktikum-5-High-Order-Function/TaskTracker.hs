module TaskTracker where

data Task = Task { title :: String, duration :: Int, isDone :: Bool }
    deriving (Show, Eq)

type TodoList = [Task]

-- 1. Fungsi markAsDone
-- Mengubah atribut `isDone` menjadi True untuk tugas dengan `title` yang sesuai target.
-- Hint: Gunakan `map` dan lambda
markAsDone :: String -> TodoList -> TodoList
markAsDone targetTitle todoList = 
    let updateTask = \t ->
            if title t == targetTitle then t {isDone = True}
            else t
    in map updateTask todoList

-- 2. Fungsi filterQuickPendingTasks
-- Mengembalikan tugas yang BELUM selesai (`isDone == False`) AND durasinya <= maxDuration.
-- Hint: Gunakan `filter` dan lambda
filterQuickPendingTasks :: Int -> TodoList -> TodoList
filterQuickPendingTasks maxDuration todoList = (filter (\t -> isDone t == False && duration t <= maxDuration) todoList)

-- 3. Fungsi Generic QuickSort untuk Task
sortByTask :: (Task -> Task -> Ordering) -> TodoList -> TodoList
sortByTask compareFunc [] = []
sortByTask compareFunc (x:xs) = 
    let smaller = sortByTask compareFunc (filter (\y -> compareFunc y x == LT) xs)
        equal = filter (\y -> compareFunc y x == EQ) xs  
        greater = sortByTask compareFunc (filter (\y -> compareFunc y x == GT) xs)
    in smaller ++ [x] ++ equal ++ greater

-- 4. Fungsi sortByDuration
-- Menyortir TodoList berdasarkan `duration` (secara ascending).
-- Hint: Gunakan `sortByTask`, `compare`, dan lambda
sortByDuration :: TodoList -> TodoList
sortByDuration todoList = sortByTask (\a b -> compare (duration a) (duration b)) todoList

-- APLIKASI
-- ====================================================================
-- TEST CASE SOAL 3 (Task Tracker)
-- ====================================================================
sampleTodoList :: TodoList
sampleTodoList = 
    [ Task "Design DB" 3 False
    , Task "Code API" 5 False
    , Task "Write Docs" 1 True
    , Task "Fix Bug" 1 False
    ]

-- Test markAsDone:
-- markAsDone "Code API" sampleTodoList
-- EXPECTED: Task "Code API" berubah status isDone-nya menjadi True.

-- Test filterQuickPendingTasks:
-- filterQuickPendingTasks 3 sampleTodoList
-- EXPECTED:
-- [ Task {title = "Design DB", duration = 3, isDone = False}
-- , Task {title = "Fix Bug", duration = 1, isDone = False}
-- ]

-- Test sortByDuration:
-- sortByDuration sampleTodoList
-- EXPECTED:
-- Sorted by duration ascending (1, 1, 3, 5).