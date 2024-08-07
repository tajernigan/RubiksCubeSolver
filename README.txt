![](data/rubiks_vid.mov)
# Tommy Jernigan, Section D, Rubik's Cube Solver

## Problem Description
This program solves a Rubik's cube. The user puts moves into the `moves.txt` file to move the cube. After you have put moves in proper Rubik's cube notation, running the executable will show you each move in the `moves.txt`, display the final scramble of the cube, then find a solution and display the moves and final solved state of the cube.

## Program Documentation
To run this program, type `make` in the command line. Before running the executable, write your desired moves into the `moves.txt` file. You do not need to recompile the program after putting different moves into the `moves.txt` file. I recommend [cstimer.net](https://cstimer.net/) to get random scrambles.

One feature I wish I had included was allowing the user to interact with the cube in the SFML window, as well as improving the lookup tables, as some scrambles for the cube do not get hashed properly. This is something I will probably come back and do myself.

Here are a few scrambles to try:
- `L B' L2 U' B L2 D' F' U D2 L2 U2 R2 F2 R U2 R' D2 R2 U2 F2`
- `D2 L2 U2 F2 U' R2 U' B2 U R2 U L2 F R' B U' B' U' R2 B R2`
- `F2 L2 R2 U' F2 U' L2 D2 L2 F2 R2 D F' U B' F R B2 L' D2 B'`
- `L2 F2 D2 F' R2 F D2 R2 B L2 D2 F2 U R F2 L D L D2 F2 U'`
- `L2 D2 L' U2 B2 F2 L' B2 D2 U2 R F' U' B D2 U L2 D2 L R`
- `R' U R' U2 L' D' B2 R2 F' R B2 L U2 F2 U2 R2 F2 R F2 U2`

## Class Description
I created two classes: a Parent class `Cube` and a Child class `Thistle`. The `Cube` class allows for a Rubik's cube state to be tracked by moves and rotations, as well as a 2D representation of this state to be printed into SFML. The `Thistle` class allows for the user to get a solution given the representation of the cube. `Thistle` is a child class of `Cube` so that you can track the cubeState of just the current path on the solution, as well as print the `Thistle` representation of the cube for debugging and so forth.

## List Data Structure
I chose a vector data structure to keep track of the moves to do in `main`. A vector was the best choice because of the ease of dynamically allocating memory, as you don't know how many moves a solution may require. It was also helpful for displaying moves at time intervals. I also used a hash map; although it isn't a list data structure, it was a useful data structure in moving from stage 3 into stage 4.

## File I/O
File I/O is used to input the moves the user wanted to perform, as well as the lookup tables for each stage of the cube. The lookup tables are used to hash the cube state at a current stage then find the desired moves in the `.txt` file for that stage.

## Reflections
I learned a lot about the theory of Rubik's cubes while doing this project, including counting permutations at various stages of the cube. If I were to do this project again, I would use a more universal representation of the cube. The 54-character string is somewhat inefficient for move operations, especially when you have to linear search through a lookup table. I also spent a lot of time trying to get the cube to be 3D when I could have focused more on the solution/SFML side of the program, which would have been a better use of my time.
