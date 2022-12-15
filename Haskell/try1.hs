-- This is a single line comment

{-
This is a multi-line comment
-}

doubleMe x y = x + y

doubleSmallNumber x = if x > 100                           
    then x                           
    else  x*2  


-- return value is the last term(parameter)
addThree :: Int -> Int -> Int -> Int   
addThree x y z = x + y + z


-- 在定义函数时，你可以为不同的模式分别定义函数体，这就让代码更加简洁易读。你可以匹配一切数据类型---数字，字符，List，元组，等等
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

--  对list做模式匹配的方法
head' :: [a] -> a   
head' [] = error "Can't call head on an empty list, dummy!"   
head' (x:_) = x  

--  Guards
{-模式用来检查一个值是否合适并从中取值，而 guard 则用来检查一个值的某项属性是否为真。
咋一听有点像是 ​if ​语句，实际上也正是如此。不过处理多个条件分支时 guard 的可读性要高些，并且与模式匹配契合的很好。
-}
bmiTell :: (RealFloat a) => a -> String  
bmiTell bmi  
    | bmi <= 18.5 = "You're underweight, you emo, you!"  
    | bmi <= 25.0 = "You're supposedly normal. "  
    | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"  
    -- 最后的那个 guard 往往都是 ​otherwise​，它的定义就是简单一个 ​otherwise = True​ ，捕获一切。这与模式很相像，只是模式检查的是匹配，而它们检查的是布尔表达式 。
    | otherwise   = "You're a whale, congratulations!"

-- 我们的 where 关键字跟在 guard 后面(最好是与竖线缩进一致)，可以定义多个名字和函数。这些名字对每个 guard 都是可见的，这一来就避免了重复。
bmiTell2 :: (RealFloat a) => a -> a -> String  
bmiTell2 weight height  
    | bmi <= 18.5 = "You're underweight, you emo, you!"  
    | bmi <= 25.0 = "You're supposedly normal. Pffft, I bet you're ugly!"  
    | bmi <= 30.0 = "You're fat! Lose some weight, fatty!"  
    | otherwise   = "You're a whale, congratulations!"  
    where bmi = weight / height ^ 2

-- let 绑定与 where 绑定很相似。where 绑定是在函数底部定义名字，对包括所有 guard 在内的整个函数可见。
-- let 绑定则是个表达式，允许你在任何位置定义局部变量，而对不同的 guard 不可见。
cylinder :: (RealFloat a) => a -> a -> a  
cylinder r h = 
    let sideArea = 2 * pi * r * h  
        topArea = pi * r ^2  
    in  sideArea + 2 * topArea

-- let 的格式为 let [bindings] in [expressions]。
-- 在 let 中绑定的名字仅对 in 部分可见。let 里面定义的名字也得对齐到一列。不难看出，这用 where 绑定也可以做到。

-- Haskell 取了这一概念融合其中。如其名，case 表达式就是，嗯，一种表达式。
-- 跟 if..else 和 let 一样的表达式。用它可以对变量的不同情况分别求值，还可以使用模式匹配。
describeList :: [a] -> String  
describeList xs = "The list is " ++ case xs of [] -> "empty."  
                                               [x] -> "a singleton list."   
                                               xs -> "a longer list."

describeList2 :: [a] -> String  
describeList2 xs = "The list is " ++ what xs  
    where what [] = "empty."  
          what [x] = "a singleton list."  
          what xs = "a longer list."