-- LIST SYNTAX

-- Haskell has a built-in type constructor for lists
-- which has nice syntax sugar

myHeadb :: [Int] -> Maybe Int

myHeadb [] = Nothing
myHeadb (x:xs) = Just x

-- main = print(myHeadb (1:2:[]))
-- main = print(myHeadb [1,2,3,4])

myHeadc :: [Char] -> Maybe Char
myHeadc [] = Nothing
myHeadc (x:xs) = Just x

-- main = print(myHeadc "Hi!")

-- Note [Char] is the same as String
-- there are convenient bits of notation for lists

-- 输出[1,2,3,4,5]
-- main = print([1..5])
-- 每次递增3
-- main = print([1,4..11])

-- List comprehension lets us build lists out of other lists

l = [(w,n) | w <- "Hi!", n <- [1,2], w /= 'i']  -- 不对i进行切片 

-- main = print(l)