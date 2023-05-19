--- STUFF THAT GOES WRONG

-- not defined for all inputs
-- this causes a runtime error

oops True = True

--try running main = print (oops False)



-- this recursive function is badly defined and will
-- run forever on inputs other than 0

eep 0 = 0
eep n = 1 + eep n



-- printing yikes will cause Haskell to run forever
-- searching for a number x such that x = x + 1
-- 无限递归

yikes = let x = 5 in
    let x = x + 1

-- the following will also run forever:
-- even though there are plenty of values equal
-- to themselves, the defintion gives us no clue
-- about which one the programmer wanted
-- 无限递归

yikesB = let x = x in x

