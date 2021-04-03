# skyscraperSolver
A little nogui program to solve 4*4 skyscraper puzzles

How to start ?

make
./skyscraper "4 1 2 3 1 2 2 2 2 2 2 1 3 2 1 4"


order of the digits in the argument: 
1 - checking columns from the top
2 - checking columns from the bottom
3 - checking rows from the left
4 - checking row from the right


               1
         ---------------
          4   1   2   3
        ===============
   | 2  |   |   |   |   |  3 |
   |     ===============     |
   | 2  |   |   |   |   |  2 |
3  |      ===============    |  4
   | 2  |   |   |   |   |  1 |
   |     ===============     |
   | 1  |   |   |   |   |  4 |
         ===============
         1   2   2   2
         ---------------- 
               2
    
