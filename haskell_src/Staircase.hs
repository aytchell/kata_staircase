module Staircase
( numWay
, numWays
) where

numWay :: (Integral n) => n -> n
numWays :: (Integral n) => n -> [n] -> n


numWay_i :: (Integral n) => n -> n
numWay_i 0 = 1
numWay_i 1 = 1
numWay_i x = numWay_i (x - 1) + numWay_i (x - 2)

numWay 0 = 0
numWay x = numWay_i x


numWays_i :: (Integral n) => n -> [n] -> n
numWays_i_ifpossible :: (Integral n) => n -> n -> [n] -> n

numWays_i_ifpossible x y lst
    | x < y = 0
    | otherwise = numWays_i (x - y) lst

numWays_i 0 lst = 1
numWays_i x lst =
    let nums_per_startstep = map (\y -> numWays_i_ifpossible x y lst) lst
    in foldl1 (+) nums_per_startstep

numWays 0 lst = 0
numWays x [] = 0
numWays x lst = numWays_i x lst
