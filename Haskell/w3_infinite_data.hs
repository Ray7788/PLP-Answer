-- INFINITE DATA

eInt :: Int
eInt = error "Hang on, I'm thinking..."

-- Suppose we define an Algebraic Data Type
data MyIntList = Emp | Cons Int (MyIntList)

-- lets construct a value of this datatype which contains an error, but which is not
-- an error in itself

v1 = Cons 10 (Cons eInt Emp)

v2 = Cons 11 (error "Hi!")

-- Let's write a function to get the head
myhead :: MyIntList -> Maybe Int
myhead Emp = Nothing
myhead (Cons x xs) = Just x

-- 正确
-- main = print(myhead v1)
-- main = print (myhead v2)

-- this tells us that it makes sense to think of values of algebraic Data Types as being
-- patially errors and partially sensible values. Functions which are non-strict in part
-- of the data structure  can work with these. We say that myhead is strict in the head of the list, and non-strict in the tail.

-- The built-in自带head功能 list type works the same way.正确
-- main = print(head [1,eInt])
-- main = print(head (1:(error "Hi!")))

-- Let's write a length function
mylen [] = 0
mylen (x : xs) = 1 + mylen xs

-- 正确
-- main = print(mylen [eInt,eInt,eInt])
-- 报错 因为mmylen会检测到输入类型是list，进而检测list内容，然后检测到error “Hi!”
-- main = print(mylen (1:(error "Hi!")))

-- This shows that mylen is strict in the spine of the list, but non-strict in the
-- elements of the list. But myhead was also non-strict in the spine of the list: it
-- didn't care that the tail was an error. Another function like that is the built in take.

-- main = print(take 1 (1:2:(error "hi!")))

-- This means we can write recursive definitions of lists which describe infinite lists
-- as long as we only apply functions to them which explore a finite part of the lists
-- everything will be ok!

ones = 1 : (ones)

-- main = print(take 5 ones)

-- there are built in bits of syntax which denote infinite lists
-- main = print(take 5 [0..])

-- 两个输出的内容一样
-- main = print ((take 5 (drop 6 [0 ..])), (take 5 [6 ..]))

-- We can try implementing [0..] by ourselves
nats :: [Integer]
nats = 0 : [n + 1 | n <- nats]

-- main = print(take 5 nats)

-- We can do very advanced things when recursively defining a list.
-- For instance in Haskell there is a !! operator which gets the n'th element of a list. We can use it to define the list of all fibbonacci numbers
-- !! 用来取数组fibb[index]中第n 个元素
fibb :: [Integer]
fibb = 1 : 1 : [(fibb !! n) + (fibb !! (n + 1)) | n <- [0 ..]]

-- main = print(take 6 fibb)

-- Finally, let's define the list of all primes. The way this is done following
-- https://hernandis.me/2019/10/20/haskell-infinite-structures.html
-- is to define a recursive function sieve on lists, which removes
-- all multiples of the head of the list from the result of sieving the
-- tail!
-- 质数
sieve :: [Integer] -> [Integer]
sieve [] = []
sieve (x : xs) = x : [v | v <- xs, v `mod` x /= 0]

primes = sieve [2 ..]

main = print (take 10 primes)