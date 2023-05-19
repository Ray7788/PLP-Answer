--- USEFUL FORMS OF DEFINITION

-- recall the definition of small above:

-- small 0 = True

-- small 1 = True

-- small n = False

-- we define a function which returns
-- True when it's argument plus one is small
-- using a case expression:

smallB n = case n + 1 of
  0 -> True
  1 -> True
  n -> False

-- a guard expression lets you define a value
-- differently in different situations, defined
-- by boolean expressions.
-- It can also contain a 'where' clause to define
-- a repeated part of the boolean conditions.

sideOfFive n
  | d > 0 = 1
  | d < 0 = -1
  | otherwise = 0
  where
    d = n - 5

-- a 'let' expression allows us to name
-- a value and use it in an expression
-- it is useful for making long formulas
-- more readable

y =
  let x = 10 + 10
   in x + x

-- the let expression also exhibits shadowing:
-- the innermost let below is the one used for the
-- meaning of x.
-- Note that the below is not an intruction to
-- 'change' x from 10 to 20. In Haskell nothing
-- ever changes! We are just saying that locally
-- we want x to be defined in various ways.
-- 就近原则!!!
z =
  let x = 10
    in let x = 20
       in x

-- now we can see that functions do behave just like
-- ordinary values in at least one way:
-- at the point the definition of f below, the local
-- definition of x is 5, so f is defined to be the
-- constant function 5.
-- We don't need to worry about local definitions
-- of x in other parts of the code to understand
-- what f does.

w =
  let x = 5
    in let f = \n -> x
        in let x = 6
            in -- in f 0 -- 此时会输出5
                x -- 此时会输出6

main = print (y, z, w)