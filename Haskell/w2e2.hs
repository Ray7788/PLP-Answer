-- TYPE CONSTRUCTORS

-- We can use type constructors to make
-- more complicated types out of other types!
-- e.g. the type of pairs

sumPair :: (Int, Int) -> Int
sumPair (x, y) = x + y

-- main = print(sumPair(2,3))

-- Similarly, given two types we can construct the type of functions from one to the other

-- Bool是最终输出
atTen :: (Int -> Bool) -> Bool
atTen f = f 10
-- 与10无关，重点是input是x和True

-- main = print (atTen (\x -> False))

-- note this is an example of type inference!
-- we could write explicitly

-- main = print(atTen ((\x -> True):: Int -> Bool))

-- We can use more than one type variable to indicate which inputs have to have matching types (Generic type)
myApp :: (a -> b) -> a -> b
myApp f x = f x

-- main = print(myApp (\x -> True) 10)
-- note that it would also be correct to give myApp a less general type e.g.

-- myApp :: (Int -> Bool) -> Int -> Bool

-- which still lets the example work:
-- main = print(myApp (\x -> True) 10)

-- but also
-- myApp :: (a -> a) -> a -> a

-- which doesn't! But it works for e.g.
-- main = print(myApp (\x -> 11) 10)
-- where the types are all the same

-- Note that we can't have
-- myApp :: (a -> b) -> b -> a
-- because this doesn't match what happens
-- in the definition: we can't apply a funtion
-- of type (a -> b) to an input of type b!