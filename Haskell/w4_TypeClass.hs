-- TYPECLASSES

-- 特定多态 There is also a different kind of polymorphism in Haskell, often called
-- 'ad hoc polymorphism', or 'overloading', which means we can have a
-- function name defined for several types, but in such a way that
-- it behaves *differenty* for each type. This is in contrast to
-- parametric polymorphism where we use the same definition for all types

-- main =   print((1::Float) + (1::Float))
-- main =   print((1::Float) + (1::Float))

-- This works using 'typeclasses' which are more like what is called
-- 'interfaces' in imperative languages. A typeclass describes a bunch
-- of operations which a type could implement.

-- a typeclass with a function that returns a string description of an element
-- 定义一个 “类型 类”
class Descriptive a where
  describe :: a -> String

-- To implement the 'describe' function for a type, we declare that
-- type to be an instance of the typeclass

instance Descriptive Bool where
  describe False = "Bool True!"
  describe True = "Bool False!"

instance Descriptive Int where
  describe 1 = "The number 1!"
  describe _ = "A boring number..."

-- main = print(describe (1 == 2))
-- 整数有Overloading
-- main = print(describe (1::Int))

-- note that type inference doesn't work well here -- ghc doesn't
-- try to use the fact that we've only implemented this for one numberical
-- type

-- We can now implement polymorphic functions which don't work for all
-- types, but only those types which are instances of a typeclass
-- 双箭头表示类型约束：如果a是Descriptive可接受的一种类型，则可以使用a做descrLen的输入
descrLen :: Descriptive a => a -> Int
descrLen x = length (describe x)

-- return "Bool False!"的长度
-- main = print (descrLen False)

-- How would we go about implementing a describe function for
-- lists? The problem is that we can have a type [b] of lists of any
-- type b, but the type b might not be an instance of Descriptive.
-- We can solve this by saying that IF b is Descriptive, THEN so is [b]

instance (Descriptive b) => Descriptive [b] where
  describe [] = "Nothing left!"
  describe (x : xs) = (describe x) ++ ", then " ++ (describe xs)

-- main = print(describe [True,False])

-- A more realistic example is the typeclass Eq of types whose elements
-- can be compared for equality. For instance, we expect numbers to be
-- comparable for equality, but not functions since we are modelling
-- computable equality!

-- Syntax: a Haskell function name can consist of all symbols. Such
-- functions are treated as infix operators. When defining them or passing
-- them to higher-order functions, we have to wrap the name in brackets.

class MyEq a where
  (===) :: a -> a -> Bool -- Equal
  (/==) :: a -> a -> Bool -- Not Equal
  x /== y = not (x === y) -- Revere 反转Equal

-- Note that I couldn't use == and /= as these are already used by
-- the built-in Eq typeclass -- more on that later.

-- In the above typeclass, we provide an implementation of /== in terms of
-- === , so instance only have to define ===

instance MyEq Bool where
  False === False = True
  True === True = True
  _ === _ = False

-- main = print (True /== False)

-- Functions can specify that an input type must be an instance of multiple typeclasses
ifEqD :: (MyEq a, Descriptive a) => a -> a -> a -> a -> String
ifEqD w x y z = if w === x then (describe y) else (describe z)

-- 只限定前2个，或者可以这样写
ifEqD1 :: (MyEq a, Descriptive b, Descriptive c) => a -> a -> b -> c -> String
ifEqD1 w x y z = if w === x then (describe y) else (describe z)

-- 内容一样
main = print (ifEqD False False True False, ifEqD1 False False True False)
