-- BASIC DEFINITIONS

-- some examples of values

b = False || (False && True)

-- 必须在同一行
n = 9
--   1
--     + 7

b2 = n /= 8

b3 = (0, 0) == (0, 0)

v = 7 * (if b then 5 else 6)

-- defining a function by an equation

add7 n = n + 7


-- defining a function by pattern matching
-- change the order and see what happens!

small 0 = True
small 1 = True
small n = False

-- defining a function on pairs
-- by pattern matching gives us
-- more interresting examples

addUp (0, n) = n
addUp (m, 0) = m
addUp (m, n) = m + n

-- ignore 2nd parameter
first (e, _) = e

-- defining a reursive function

fib 0 = 0
fib 1 = 1
fib n = fib (n - 2) + fib (n - 1)

main = print (b)
