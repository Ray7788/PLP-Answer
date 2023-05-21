--- HIGHER ORDER FUNCTIONS

-- this function takes a number and returns
-- the function which adds that number to
-- its input

addConst n m = n + m

-- we can test it by evaluating it at 3
-- and seeing what function we get

addThree = addConst 3

-- main = print(addThree 2)

-- we can use anonymous functions to make it
-- obvious that this returns a function

addConstB n = \m -> n + m

-- main = print(addConstB 3 2)

-- indeed, we can define a function explicitly
-- using anonymous functions, rather than equations

addConstC = \n -> (\m -> n + m)

-- main = print(addConstC 3 2)

-- note: when a variable is used, it refers to
-- the definition closest  to the usage, so 就近原则!!!
-- the following returns the identity function, not
-- a constant function. This is called 'shadowing'

h n = (\n -> n)

-- 输出4
main = print(h 3 4)

-- but the following expression defines a function
-- which returns a constant function.

h2 n = (\m -> n)

-- 此时输出第一个数： h2 3 4 会输出3
-- main = print(h2 3 4)

-- here is a function which takes another function
-- as input

thriceFromZero f = f (f (f (0)))

-- we can define recursive higher-order functions
-- just like any other functions

repFromZero 0 f = 0
repFromZero n f = f (repFromZero (n - 1) f)

 -- main = print (repFromZero 3 (\x -> x + 1))
-- main = print (h 5 2)
-- print (addConst 3 5)
