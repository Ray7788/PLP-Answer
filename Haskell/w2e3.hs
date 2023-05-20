-- ALGEBRAIC DATA TYPES

-- we can make our own types by using the 'data'
-- keyword. The simplest are enumerations, which

data SwitchState = On | Off

-- we can define fun ctions by pattern matching
toggle :: SwitchState -> SwitchState
toggle On = Off
toggle Off = On

isOn :: SwitchState -> Bool
isOn On = True
isOn Off = False

-- main = print(isOn (toggle On))
-- Note we can't do
-- main = print (toggle Off)
-- because we haven't told Haskell how to print
-- a value of this type. We look at that in week 11

-- we can also attach data from existing types

data MyIntPair = IntPair Int Int

mySumPair :: MyIntPair -> Int
mySumPair (IntPair x y) = x + y

-- main = print(mySumPair(IntPair 3 6))

-- we can also ignore some fields of a constructor
myfst :: MyIntPair -> Int
myfst (IntPair x _) = x

main = print (myfst (IntPair 1 2))

-- we can combine the ideas of enums and data
-- fields

data BoolOrInt = Abool Bool | Anint Int

-- This is called an 'algebraic datatype'
intval :: BoolOrInt -> Int
intval (Abool True) = 1
intval (Abool False) = 0
intval (Anint x) = x

opposite :: BoolOrInt -> BoolOrInt
opposite (Abool True) = (Abool False)
opposite (Abool False) = (Abool True)
opposite (Anint x) = (Anint (-x))

-- main = print(intval(opposite (Abool False)))

-- This can be useful for error handling
-- data MaybeInt = NoInt | GotInt Int

-- we can use type variables to create a new type
-- constructor!
data MyPair a b = Pair a b

mySumPairb :: MyPair Int Int -> Int
mySumPairb (Pair x y) = x + y

-- main = print(mySumPairb (Pair 10 11))

-- e.g. error handling at any type
-- data Maybe a = Nothing | Just a
-- this is so useful it is built in!

-- main = print(Just 1)

-- Algebraic datatypes can be recursive. This
-- is useful for recursively defined data
-- structures

-- Append 有两个parameters
data MyList a = Empty | Append a (MyList a)

myHead Empty = Nothing
myHead (Append x l) = Just x

-- main = print(myHead (Append 10 (Append 11 Empty)))
