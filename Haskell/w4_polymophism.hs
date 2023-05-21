-- PARAMETRIC POLYMORPHISM
-- ignore the following line:
-- {-# LANGUAGE RankNTypes #-}

-- In Week 9, we saw that a type can contain a type variable

f :: a -> Bool
f _ = True

-- This means the function is defined for all types a, but note that
-- we have to use the same definition for each type. This is called
-- "parametric polymorphism"

-- 输出True
main = print ((f 7) && (f False))

-- Now let's talk a bit more about what type variables mean in detail.
-- You should imagine that they are quantified by a "for all" which comes
-- before the start of the type.
-- This means the definition

-- g :: (b -> Bool) -> Bool

-- 约束了必须是整数或者Bool做输入，但是b是任意的，所以冲突
-- g h = (h 7) && (h False)

-- 报错
-- main = print(g f)

-- makes no sense! It looks similar to the way we used f above, but
-- here we are claiming that g is a function which given a function of type
-- b -> Bool FOR ALL TYPES B, will give you a Bool. But then g goes on to
-- assume that it can apply this to numbers and Booleans -- but that wouldn't
-- make sense for e.g. b = String.

-- An example which might be easier to understand is the type (a,a). Can we
-- construct an element of this type by itself?
-- We might think this means giving an element of (a,a) for *some* type a,
-- and trying

-- p :: (a,a)
-- p = (1,1)

-- But this does not typecheck because p::(a,a) means that p is in the type
-- (a,a) for *every* type a, which is impossible to satisfy (without using
-- bottom or error values...).

-- main = print ("")