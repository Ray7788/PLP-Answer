-- This is a single line comment

{-
This is a multi-line comment
-}

-- main  = do
--     max 4 5

doubleMe x y = x + y

doubleSmallNumber x = if x > 100                           
    then x                           
    else  x*2  


-- return value is the last term(parameter)
addThree :: Int -> Int -> Int -> Int   
addThree x y z = x + y + z



lucky :: (Integral a) => a -> String   
lucky 7 = "LUCKY NUMBER SEVEN!"   
lucky x = "Sorry, you're out of luck, pal!"   

sayMe :: (Integral a) => a -> String   
sayMe 1 = "One!"   
sayMe 2 = "Two!"   
sayMe 3 = "Three!"   
sayMe 4 = "Four!"   
sayMe 5 = "Five!"   
sayMe x = "Not between 1 and 5"  

-- 先说明0的阶乘是1，再说明每个正整数的阶乘都是这个数与它前驱(predecessor)对应的阶乘的积。
factorial :: (Integral a) => a -> a   
factorial 0 = 1   
factorial n = n * factorial (n - 1) 

-- 在定义模式时，一定要留一个万能匹配的模式，这样我们的程序就不会为了不可预料的输入而崩溃了。

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)   
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2) 

-- 注意下，你若要绑定多个变量（用_也是如此），我们必须用括号将其括起。
-- 同时注意下我们用的这个error函数，它可以生成一个运行时错误，用参数中的字符串表示对错误的描述。它会直接导致程序崩溃，因此应谨慎使用。
tell :: (Show a) => [a] -> String   
tell [] = "The list is empty"   
tell (x:[]) = "The list has one element: " ++ show x   
tell (x:y:[]) = "The list has two elements: " ++ show x ++ " and " ++ show y   
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ " and " ++ show y  