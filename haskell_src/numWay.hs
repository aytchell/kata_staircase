
numWay_i :: (Integral n) => n -> n
numWay_i 0 = 1
numWay_i 1 = 1
numWay_i x = numWay_i (x - 1) + numWay_i (x - 2)

numWay :: (Integral n) => n -> n
numWay 0 = 0
numWay x = numWay_i x
