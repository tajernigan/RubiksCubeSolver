TITLE: Tommy Jernigan, Section D, Rubiks cube solver.

PROBLEM DESCRIPTION: This program solves a rubiks cube. The user puts moves into the moves.txt file to move the cube.
After you have put moves in proper rubiks cube notation, when you run the executable the program will show you
each move in the moves.txt and display the final scramble of the cube, then the cube will find a solution and
display the moves and final solved state of the cube.

PROGRAM DOCUMENTATION: In order to run this program type make in the command line, before you run the executable
write your desired moves into the moves.txt, you do not need to recompile the program after putting different moves
into the moves.txt file, I recommend cstimer.net to get random scrambles. One features I wish I had included was making the user be able to interact with the cube in the sfml
window, as well as improve the look up tables, as some scrambles for the cube do not get hashed properly. This is something I will
probably come back and do myself.
here are a few scrambles to try:
L B' L2 U' B L2 D' F' U D2 L2 U2 R2 F2 R U2 R' D2 R2 U2 F2
D2 L2 U2 F2 U' R2 U' B2 U R2 U L2 F R' B U' B' U' R2 B R2
F2 L2 R2 U' F2 U' L2 D2 L2 F2 R2 D F' U B' F R B2 L' D2 B'
L2 F2 D2 F' R2 F D2 R2 B L2 D2 F2 U R F2 L D L D2 F2 U'
L2 D2 L' U2 B2 F2 L' B2 D2 U2 R F' U' B D2 U L2 D2 L R
R' U R' U2 L' D' B2 R2 F' R B2 L U2 F2 U2 R2 F2 R F2 U2


CLASS DESCRIPTION: I created two classes, one being a Parent class Cube and the other being a Child class of cube Thistle.
The cube class allows for a rubiks cube state to be tracked by moves and rotations. As well as a 2D representation of this
state to be printed into sfml. The Thistle class allows for the user to get a solution given the representation of the cube
Thistle is a child class of cube so that you can track the cubeState of just the current path on the solution, as well as print
the Thistle representation of the cube for debugging and so forth.

LIST DATA STRUCTURE: I chose a vector data structure, this was chosen to check track of the moves to do in main.
A vector was the best choice for this because of the ease of dynamically allocating memory, as you don't know how many
moves a solution may be. I was also helpful for display moves at time intervals. I also used a hash map, also it isn't
a list data structure it was a useful data structure in moving from stage 3 into stage 4.

FILE I/O: File I/O is used to input the moves the user wanted to perform, as well as the lookup tables for each stage of the cube.
The lookup tables are used to hash the cube state at a current stage then find the desired moves in the .txt file for that stage.

REFLECTIONS: I learned a lot about the theory of rubiks cube while doing this project as well as counting, such as how many permutations
are in the cube at this stage and so on so forth. I think if I were to do this next time I would have a more universal representation of the cube
the 54 character string is somewhat ineffiecent for move operations, especially when you have to linear search through a lookup table. I also spend
a lot of time trying to get the cube to be 3D when I could have been focusing more time on the solution/sfml side of the program which would 
have been a better way to spend my time.