# Rod Cutting & Coin Change

This program has 2 parts to it. One is the rod cutting algorithm, and the other is the coin change algorithm. Each have an explanation about them below.

A sample output of the program in `results.txt`

## Explanation of the Rod Cutting Algorithm

The algorithm has a list of lengths and the prices associated with each length. Every rod has to be cut to one of the specified lengths. The algorithm is then given a length and must find the maximum amount of revenue that can come from cutting the rod. It will go through all the combination of smaller rods that can make the large rod then output the one which provides the most amount of revenue. 

The program outputs the following to the standard output:
- the length it was given
- the maximum revenue that can be made from that length
- the time it took to find that length into a table.

## Explanation of the Coin Change Algorithm

The coin change algorithm has 4 parts, A, B, A reconstruction, and B reconstruction.

For the A and B parts, the algorithm has a specified coin denominations (example: US coins are 1, 5, 10, 25, etc.). It is then given a value and the algorithm find all the combinations that would make that value. It then prints out the following to the standard output:
- the length it was given
- the maximum revenue that can be made from that length
- the time it took to find that length into a table.

For the A part, it will use the US coin denominations of 1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000 for the coins that it can be.
For the B part, it uses a made up coins system that uses 1, 29, 493 as the coins.
Both parts work exactly the same, just with different coin denominations.

For the A and B reconstruction part, the algorithm is given a coin denominations and 4 coin amounts (10, 25, 50, 100). It will then go through and make all the possible combinations to get the coin amounts. It will then print of the following to the standard output:
- what value the coins are making
- the coin combinations to get that value (if the value is 10, one line would be: 5 5)
- the time it took to reconstruct all the coin combinations for that coin value

Both of the reconstruction parts work exactly the same, just with US coin denominations or the made up coin denominations.

## Execution of program

The `MakeFile` will compile everything in `RodCuttingAndCoinChange.cc`, which can then be executed using `./RodAndCoin > results.txt`