module Staircase
( numWay
, numWays
, showWays
) where

-- Signatures of exported functions

numWay :: (Integral n) => n -> n
numWays :: (Integral n) => n -> [n] -> n
showWays :: (Integral n) => n -> [n] -> [[n]]

-- Internal helper function for numWay

numWay_i :: (Integral n) => n -> n
numWay_i 0 = 1
numWay_i 1 = 1
numWay_i x = numWay_i (x - 1) + numWay_i (x - 2)

-- Implementation of numWay

numWay 0 = 0
numWay x = numWay_i x

-- Internal helper functions for numWays

numWays_i :: (Integral n) => n -> [n] -> n
numWays_i_ifpossible :: (Integral n) => n -> n -> [n] -> n

numWays_i_ifpossible x y lst
    | x < y = 0
    | otherwise = numWays_i (x - y) lst

numWays_i 0 lst = 1
numWays_i x lst =
    let nums_per_startstep = map (\y -> numWays_i_ifpossible x y lst) lst
    in foldl1 (+) nums_per_startstep

-- Implementation of numWays

numWays 0 lst = 0
numWays x [] = 0
numWays x lst = numWays_i x lst

-- Internal helper functions for showWays

showWays_i :: (Integral n) => n -> [n] -> [[n]]
showWays_i_ifpossible :: (Integral n) => n -> n -> [n] -> [[n]]

showWays_i_ifpossible x y lst
    | x < y = []
    | otherwise =
        let shown_of_remainder = showWays_i (x - y) lst
        in map (\h -> y:h) shown_of_remainder

showWays_i 0 lst = [[]]
showWays_i x lst =
    let shown_per_startstep = map (\y -> showWays_i_ifpossible x y lst) lst
    in concat shown_per_startstep

-- Implementation of showWays

showWays 0 lst = []
showWays x [] = []
showWays x lst = showWays_i x lst
