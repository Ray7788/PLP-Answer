-- TYPES AND TYPE INFERENCE

-- we can explicitly give the type of a function
f :: Int -> Int
f x = x + 1

-- Note: Int is fixed precision, Integer unbounded
-- We also have Float, Double

fd :: Double -> Double
fd x = x + 1

-- ok:
-- main = print(fd 10)
-- not ok:
-- main = print(fd (10::Int))
-- main = print((1::Int) + (1::Integer))

-- 检测是否大于10
big :: Integer -> Bool
big x = x > 10

-- main = print(big 11)

-- In Haskell, every expression has a type
-- How come last week we didn't have to
-- delcare them? Haskell infers types
-- we don't give explicitly E.g.
j :: Bool -> Bool
j x = True

-- main = print (j False)  -- 会输出True

-- What is the type of j?
-- We can give it several types, like

-- 不添加constructor会进行通用处理
-- jj :: Int -> Bool
jj x = False

-- Note we can't give it type Bool -> Int!
-- But the original has a strange feature:

-- 会输出False
-- main = print (jj 1 && jj True)

-- Is this 'dynamic typing'? No it is called
-- 'parametic polymorphism'. We can use
-- type variables to indicate that something
-- works for all types!
-- 泛型
jjj :: a -> Bool
jjj x = False

main = print (jjj 2)  -- 会输出False
