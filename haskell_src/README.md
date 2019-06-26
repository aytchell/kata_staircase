# Example outputs

## numWay n

    *Staircase> map Staircase.numWay [0..20]
    [0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946]

## numWays n lst

    *Staircase> Staircase.numWays 4 [1,3,5]
    3

    *Staircase> map (\x -> Staircase.numWays x [1,2]) [1..10]
    [1,2,3,5,8,13,21,34,55,89]

    *Staircase> map (\x -> Staircase.numWays x [1,3,5]) [1..10]
    [1,1,2,3,5,8,12,19,30,47]

