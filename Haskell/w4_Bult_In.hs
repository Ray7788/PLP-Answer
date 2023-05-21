-- BUILT-IN TYPECLASSES

-- There is a typeclass Show a which is like Descriptive: it provides
-- a function show :: a -> String, but usually you give a sensible
-- string, not like the example above! This is how the print function knows
-- how to turn various values into strings

--main = print(take 5 (show [1,2,3,4,5,6]))

-- We can manually implement this for our own types if we want:

data Pcolours = R | G | B

instance Show Pcolours where
  show R = "Red"
  show G = "Green"
  show B = "Blue"

main = print([R,G,B])

-- but for this built-in typeclass there is also a default implementation
-- which we can access by adding "deriving (Show)" to the type definition

data Colour = RGB Int Int Int | HSV Int Int Int deriving (Show)

-- main = print(RGB 10 11 12)

-- Similarly we mentioned the built-in typeclass Eq which provides == and /=
 
data ToyType =  Bird | Comet | Cloud deriving (Eq, Show)

data Mobile = Toy ToyType | Stick Mobile Mobile deriving (Show)
 
-- For Mobile we will define our own instance of Eq to get custom behaviour
 
instance Eq Mobile where
   Toy a == Toy b = a == b
   Stick w x == Stick y z = (w == y && x == z) || (w == z) && (x == y)
   _ == _ = False
 
-- main = print((Stick (Toy Bird) (Stick (Toy Cloud) (Toy Comet))) == (Stick  (Stick (Toy Comet) (Toy Cloud) ) (Toy Bird))  )