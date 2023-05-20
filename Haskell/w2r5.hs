-- ERROR VALUES

-- We have seen that sometimes things can 'go wrong' at runtime
-- for example

x = x

-- the meaning of this expression is undefined. It is sometimes called
-- 'bottom'   永不停止

bottom = bottom

-- We definitely don't want to run
-- print(bottom)
-- as this will cause the computer to go into an infinite loop!

-- We have seen other runtime errors, like what happens when we
-- evaluate a function defined by pattern matching on an argument where it is *not defined*
-- Non-exhaustive patterns in function badhead

badhead :: [Int] -> Int
badhead (x : xs) = x

-- uhoh = badhead []
-- main = print (uhoh)

-- When reasoning about a function is is easier to only consider the case where
-- it's inputs don't go wrong. But what if we want to reason about all inputs?
-- Let's probe the behaviour of some functions when given error values
-- Rather than testing with real errors, we can use the 'error' expression to deliberately
-- cause errors

eInt :: Int
eInt = error "Hang on, I'm thinking..."

eBool :: Bool
eBool = error "Hang on, I'm thinking..."

-- we should avoid the use of the error expression at all costs! It is *not* a good way
-- of implementing error handling in Haksel. For instance, badhead should be re-rwitten to use the Maybe datatype, which will mean it can be totally defined.
-- However, it is useful for testing code to see what it would do in the presence of an error as input.

-- main = print(eInt)

-- Now let's define a function and see how it behaves when its input goes wrong

f x = x + 3

-- main = print (f eInt)

-- But something interesting happens if the function does not look at the argument

g x = 5

-- main = print(g eInt)

-- just prints 5 !
-- this means it is safe to call g with the value bottom!

-- main = print(g bottom)

-- even though trying to print bottom will cause an infinite loop, Haskell never evaluates
-- the unused argument. We say that f is *strict* in its argument, but g is *not strict*
-- in its argument. A function is strict in an argument if and only if when that argument is
-- bottom or an error, the value of the function is bottom or an error.

-- Let's see if the * operator is strict or not in its arguments running
-- main = print(0 * (eInt))
-- strict in the second argument

-- main = print((eInt) * 0)
-- strict in the first argument

main = print ((5) * 0)
