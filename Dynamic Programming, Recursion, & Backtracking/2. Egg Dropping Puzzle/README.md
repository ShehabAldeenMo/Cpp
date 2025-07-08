# Longest Common Subsequence

## Explanation 
This problem is explained totally from youtube channel in this video [Microsoft Interview Puzzles](https://www.youtube.com/watch?v=uBhSIKLlvdk)

## Hints and Notes:
There's several solutions. Let assume (# of eggs = unlimited) and (# of floors = 100).
1. Brute Force:
Test drop egg from each floor sequentially. lead to at worst case # of moves = # floors.

2. Binary Search:
lead to at worst case # of moves = # floors / 2.

3. Conquer bit:
move upwards on steps. assume step = 10 moves upwards. lead to # of moves = 19 steps.

4. Balaced linear drop
assume step = x and next step = x - 1 and so on .....
then (x + x-1 + x-2 + ..... + 1  = 100) then (x(x+1)/2 = 100) then x will equal 13.5658 ups to 14 then moves will lead to 14 moves. must optimal.

## Explanation 
This problem is explained totally from youtube channel in this video [Egg Dropping Problem](https://www.youtube.com/watch?v=iOaRjDT0vjc)

## Hints and Notes
1. There's some great quote "In recursion problems, we don't know solution of problem but we know solution of base case" you can depend on this quote at all.

2. Cases:
    2.1. # of moves = # of floors if we have only one egg. in this case we need to move sequentially.
    2.2. if # of floors = 0 or 1. then # of moves will be 0 or 1 according to of # of floors.
    2.3. other cases: we have two options
    -   egg broke at floor i then we have # of moves = eggsdrop(n-1,i-1);
    -   egg isn't broke at floor i then we have # of moves = eggsdrop(n,k-i); which k is # of floors.
    at worst case search, # of moves = 1+max(option1,option2);

3. to memorize these calculations to prevent recalculating use cache memory initialize with -1 and assign each calculation to speed up.

4. use dynamic programming by make 2D array. and initialize row 0 with zeros. and initialize row 1 with # of floors in each colume. initialize col 0 with zeros. and col 1 with # of floors which is = 1. and iterate on each cell and calculation will be (1+max(option1,option2)).

the solution is supported by this [video](https://www.youtube.com/watch?v=KVfxgpI3Tv0)