# Tommy Jernigan, Section D, Rubik's Cube Solver

![output](https://github.com/user-attachments/assets/f4c976ad-e263-47f3-99bf-82defcce1140)

## Project Overview 
This program solves a Rubik's cube as well as display the cube in 2D. The cube will be scrambled based on the rubiks cube notation in the 'moves.txt' file, then it will find a solution and display the moves and final solved state of the cube.

Here are a few scrambles to try:
- `L B' L2 U' B L2 D' F' U D2 L2 U2 R2 F2 R U2 R' D2 R2 U2 F2`
- `D2 L2 U2 F2 U' R2 U' B2 U R2 U L2 F R' B U' B' U' R2 B R2`
- `F2 L2 R2 U' F2 U' L2 D2 L2 F2 R2 D F' U B' F R B2 L' D2 B'`
- `L2 F2 D2 F' R2 F D2 R2 B L2 D2 F2 U R F2 L D L D2 F2 U'`
- `L2 D2 L' U2 B2 F2 L' B2 D2 U2 R F' U' B D2 U L2 D2 L R`
- `R' U R' U2 L' D' B2 R2 F' R B2 L U2 F2 U2 R2 F2 R F2 U2`

## Class Description
I created two classes: a Parent class `Cube` and a Child class `Thistle`. The `Cube` class allows for a Rubik's cube state to be tracked by moves and rotations, as well as a 2D representation of this state to be printed into SFML. The `Thistle` class allows for the user to get a solution given the representation of the cube. `Thistle` is a child class of `Cube` so that you can track the cubeState of just the current path on the solution, as well as print the `Thistle` representation of the cube for debugging and so forth.
