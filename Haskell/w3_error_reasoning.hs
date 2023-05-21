-- REASONING IN THE PRESENCE OF ERRORS

-- if we probe functions using error values, we might get behaviour we don't expect. 非确定性的！！
-- for instace, we might try to see which argument + looks at first, which breaks the abstraction that it is a mathematical functions

-- 输出 right
-- main = print((error "left!" + error "right!"))
-- 输出 left
-- main = print (error "right!" + error "left!")

-- In Haskell, if the value of an expression is an *error*, including non-termination, its theoretical value is the set of all errors which could result from evaluating in any order.

-- An implementation can freely choose which of these actually happens, and that could
-- depend on random factors at the time of running. So theoretically + is still commutative in the presence of errors, because the *set* of possible behaviours doesn't depend on the order of the arguments, even though the error we actualy see might depend on that, and on other, perhaps mysterious things!
-- However, we could define a "short circuiting" definition of * which ignores one of its arguments

stimes :: Int -> Int -> Int
stimes 0 _ = 0
stimes x y = x * y

-- Remark: one nice bit of Haskell syntax is that you can a funtion as an inline operator
-- if you enclose it's name in backticks: `...` （算子）

-- 正常
-- main = print(0 `stimes` eInt)
-- 错误
-- main = print (eInt `stimes` 0)

-- this is fundamentally “noncommutative”, because if an expression denotes a non-error
-- value, then it is *not* allowed to return an error that would have resulted from
-- evaluating part of the expression that is not looked at!

-- This means it is safe to apply stimes to bottom in the second arguments
-- main = print(0 `stimes` bottom)

-- 错误信息
eInt :: Int
eInt = error "Hang on, I'm thinking..."

eBool :: Bool
eBool = error "Hang on, I'm thinking..."

-- 自己尝试
addUp :: (Int, Int) -> Int
addUp (m, 0) = m
addUp (0, n) = n
addUp (m, n) = m + n

-- 会报错！！ 因为执行addUp会按照声明顺序先带入 addUp (m, 0) = m进行尝试，所以会检测到第2个是error
-- main = print (addUp (0, eInt))

-- the boolean operators && and || are impememnted in this way:

-- main = print(False && eBool)
-- main = print(True && eBool)
-- main = print(eBool && False)

-- So && is strict in its first argument, but non-strict in its second argument.

-- Something interesting happens for more complicated kinds of data, like pairs.
strangePair = (eInt, eBool)

ePair = error "Hang on, I'm thinking..."

h :: (Int, Bool) -> Int
-- 输入2个变量（一组）
h (x, y) = 42

j :: (Int, Bool) -> Int
-- 输入1个变量
j p = 10

-- 正确输出
-- main = print (h strangePair)
-- main = print(j ePair)
-- 错误
-- main = print(h ePair)

-- so there is a dfference between an error of type (a,b), and a pair of errors!
-- we can pattern match on a pair of errors sucessfully, as long as we don't try to use
-- the components. But a pair which is an error in itself can't even be pattern matched on.
-- Some people would say that the function h is strict in the 'spine' (i.e. shape) of the pair, but non-strict in the components, whereas j is non-strict in the spine.

-- This is necessary if we want the fst and snd operations, which get the first and
-- second components of a pari, to obey the expected equations
-- fst(x,y) == x
-- and
-- snd(x,y) == y

-- 正确
-- main = print (fst (1, eBool))
-- 正确，snd直接检查第二个
-- main = print (snd (eInt, True))

-- but it *breaks* another expected equation, namely that for all pairs p we have
-- p == (fst p, snd p), because of what happens when the components are errors

-- 一对错误 one pair of errors
ePairB = (fst ePair, snd ePair)

-- 正确 检查输入类型正确就直接输出值,不会进一步细查
-- main = print(h ePairB)

-- so ePairb behaves differently to ePair when passed to h.
-- This is why it is usually easier to reason about how function behave when their arguments are not errors.