#ifndef CUBE_HPP
#define CUBE_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Cube {
    public:

    /**
     * @brief Construct a new Cube object, initialized cube state to have yellow on top and green in the front
     * 
     */
    Cube();

    /**
     * @brief Construct a new Cube object, with a user selected cube string
     * 
     */
    Cube(std::string);


    /**
     * @brief moves the cube based on rubiks cube notion
     * 
     */
    void moveCube(std::string);

    /**
     * @brief prints the cubeState of the cube into sfml in a 2D format
     * 
     */
    void print2D(sf::RenderWindow&) const;

    /**
     * @brief Get the Cube State object
     * 
     * @return std::string 
     */
    std::string getCubeState() const;

    private:

    /**
     * @brief use for rotating the cube, used to translate each move onto a U move into to use the move cube function
     * 
     */
    void rotateCube(std::string);

    /**
     * @brief make a U or U' based on the integer input of either 1 or 0;
     * 
     */
    void move(int);

    protected:

    std::string _cubeState; // 54 lenght string reprsentation of the permutation of the rubiks cube
};

/**
 * @brief flops a side of the cube to account for the change in a cubes permutation when rotating the cube.
 * 
 * @return std::string 
 */
std::string flopString(std::string, int);

/**
 * @brief used to convert each sqaure representation in the cubeState to a sfml color to be printed, this function is used the the print2D public Cube function
 * 
 * @return sf::Color 
 */
sf::Color convertColor(std::string); 

using namespace std;
using namespace sf;

Cube::Cube(){
    _cubeState = "yyyyyyyyyrrrrrrrrrgggggggggooooooooobbbbbbbbbwwwwwwwww";
}

Cube::Cube(string cubeState){
    _cubeState = cubeState;
}

string flopString(string face, int clockwise){
    string temp;
    temp += face.at(6);
    temp += face.at(3);
    temp += face.at(0);
    temp += face.at(7);
    temp += face.at(4);
    temp += face.at(1);
    temp += face.at(8);
    temp += face.at(5);
    temp += face.at(2);
    face = temp;
    if (clockwise == 0){
        reverse(face.begin(), face.end());
    }
    return face;
}

Color convertColor(const char colorChar){
    char chars[6] = {'y', 'r', 'g', 'o', 'b', 'w'};
    Color colors[6] = {Color::Yellow, Color::Red, Color::Green, Color(255, 153, 0), Color::Blue, Color::White};
    for (int i = 0; i < 6; i++){
        if (chars[i] == colorChar){ 
            return colors[i];
        }
    }
    return Color::Black; // return black if color is not found
}

string Cube::getCubeState() const {return _cubeState;}

void Cube::move(int clockwise){
    // get all necessary info for cube state before altering the cube state
    string top = _cubeState.substr(0,9);
    string leftThree = _cubeState.substr(9,3);
    string frontThree = _cubeState.substr(18,3);
    string rightThree = _cubeState.substr(27,3);
    string backThree = _cubeState.substr(36,3);
    
    if (clockwise == 1){
        // orient top face properly
        _cubeState.replace(0, 9, flopString(top, 1));
        // currMove corners and edges below top side
        _cubeState.replace(9,3, frontThree);
        _cubeState.replace(18,3, rightThree);
        _cubeState.replace(27,3, backThree);
        _cubeState.replace(36,3, leftThree);
    }
    else {
        // orient top face properly
        _cubeState.replace(0, 9, flopString(top, 0));
        // currMove corners and edges below top side
        _cubeState.replace(9,3, backThree);
        _cubeState.replace(18,3, leftThree);
        _cubeState.replace(27,3, frontThree);
        _cubeState.replace(36,3, rightThree);
    }
}

void Cube::rotateCube(string rotation){
    string newState;
    // get faces of cube
    string top = _cubeState.substr(0, 9);
    string left = _cubeState.substr(9, 9);
    string front = _cubeState.substr(18, 9);
    string right = _cubeState.substr(27, 9);
    string back = _cubeState.substr(36, 9);
    string bottom = _cubeState.substr(45, 9);
    if (rotation == "y"){ 
        top = flopString(top, 1);
        bottom = flopString(bottom, 0);
        newState = top + front + right + back + left + bottom;
    }
    else if (rotation == "y'"){
        top = flopString(top, 0);
        bottom = flopString(bottom, 1);
        newState = top + back + left + front + right + bottom;
    }
    else if (rotation == "x"){
        left = flopString(left, 0);
        right = flopString(right, 1);
        reverse(top.begin(), top.end()); // account for faces moving
        reverse(back.begin(), back.end());
        newState = front + left + bottom + right + top + back; 
    }
    else if (rotation == "x'"){
        left = flopString(left, 1);
        right = flopString(right, 0);
        reverse(back.begin(), back.end());
        reverse(bottom.begin(), bottom.end()); // account for faces moving
        newState = back + left + top + right + bottom + front; 
    }
    else if (rotation == "z"){
        front = flopString(front, 1);
        back = flopString(back, 0);
        left = flopString(left, 1);
        right = flopString(right, 1);
        top = flopString(top, 1);
        bottom = flopString(bottom, 1);
        newState = left + bottom + front + top + back + right; 
    }
    else if (rotation == "z'"){
        front = flopString(front, 0);
        back = flopString(back, 1);
        left = flopString(left, 0);
        right = flopString(right, 0);
        top = flopString(top, 0);
        bottom = flopString(bottom, 0);
        newState = right + top + front + bottom + back + left; 
    }
    else{
        cout << rotation << " not a valid input" << '\n';
        newState = _cubeState;
    }
    _cubeState = newState;
}

void Cube::moveCube(string move){ // TODO: lighten code
    istringstream iss(move);
    string currMove;
    while (iss >> currMove){
    if (currMove == "U"){
        this->move(1);
    }
    else if(currMove == "U'"){
        this->move(0);
    }
    else if(currMove == "U2" || currMove == "U2'"){
        this->move(1);
        this->move(1);
    }
    else if (currMove == "L"){
        this->rotateCube("z");
        this->move(1);
        this->rotateCube("z'");
    }
    else if(currMove == "L'"){
        this->rotateCube("z");
        this->move(0);
        this->rotateCube("z'");
    }
    else if(currMove == "L2"){
        this->rotateCube("z");
        this->move(1);
        this->move(1);
        this->rotateCube("z'");
    }
    else if (currMove == "R"){
        this->rotateCube("z'");
        this->move(1);
        this->rotateCube("z");
    }
    else if(currMove == "R'"){
        this->rotateCube("z'");
        this->move(0);
        this->rotateCube("z");
    }
    else if(currMove == "R2"){
        this->rotateCube("z'");
        this->move(1);
        this->move(1);
        this->rotateCube("z");
    }
    else if (currMove == "F"){
        this->rotateCube("x");
        this->move(1);
        this->rotateCube("x'");
    }
    else if(currMove == "F'"){
        this->rotateCube("x");
        this->move(0);
        this->rotateCube("x'");
    }
    else if(currMove == "F2"){
        this->rotateCube("x");
        this->move(1);
        this->move(1);
        this->rotateCube("x'");
    }
    else if (currMove == "B"){
        this->rotateCube("x'");
        this->move(1);
        this->rotateCube("x");
    }
    else if(currMove == "B'"){
        this->rotateCube("x'");
        this->move(0);
        this->rotateCube("x");
    }
    else if(currMove == "B2"){
        this->rotateCube("x'");
        this->move(1);
        this->move(1);
        this->rotateCube("x");
    }
    else if (currMove == "D"){
        this->rotateCube("x");
        this->rotateCube("x");
        this->move(1);
        this->rotateCube("x'");
        this->rotateCube("x'");
    }
    else if(currMove == "D'"){
        this->rotateCube("x");
        this->rotateCube("x");
        this->move(0);
        this->rotateCube("x'");
        this->rotateCube("x'");
    }
    else if(currMove == "D2"){
        this->rotateCube("x");
        this->rotateCube("x");
        this->move(1);
        this->move(1);
        this->rotateCube("x'");
        this->rotateCube("x'");
    }
    // moves to add M, S, E, u, d, l, r, f, b
    else if (currMove == "M"){
        this->moveCube("R");
        this->moveCube("L'");
        this->rotateCube("x'");    
    }
    else if (currMove == "M'"){
        this->moveCube("R'");
        this->moveCube("L");
        this->rotateCube("x");    
    }
    else if (currMove == "M2"){
        this->moveCube("M");
        this->moveCube("M");  
    }
    else if (currMove == "S"){
        this->moveCube("F'");
        this->moveCube("B");
        this->rotateCube("z");  
    }
    else if (currMove == "S'"){
        this->moveCube("F");
        this->moveCube("B'");
        this->rotateCube("z'");  
    }
    else if (currMove == "S2"){
        this->moveCube("S");
        this->moveCube("S");
    }
    else if (currMove == "E"){
        this->moveCube("U");
        this->moveCube("D'");
        this->rotateCube("y'");  
    }
    else if (currMove == "E'"){
        this->moveCube("U'");
        this->moveCube("D");
        this->rotateCube("y");  
    }
    else if (currMove == "E2"){
        this->moveCube("E");
        this->moveCube("E"); 
    }
    else if (currMove == "r" || currMove == "Rw"){
        this->moveCube("L");
        this->rotateCube("x");
    }
    else if (currMove == "r'" || currMove == "Rw'"){
        this->moveCube("L");
        this->rotateCube("x'");
    }
    else if (currMove == "r2" || currMove == "Rw2"){
        this->moveCube("r");
        this->moveCube("r");
    }
     else if (currMove == "l" || currMove == "lw"){
        this->moveCube("R");
        this->rotateCube("x'");
    }
    else if (currMove == "l'" || currMove == "Lw'"){
        this->moveCube("R'");
        this->rotateCube("x");
    }
    else if (currMove == "l2" || currMove == "Lw2"){
        this->moveCube("l");
        this->moveCube("l");
    }
     else if (currMove == "f" || currMove == "Fw"){
        this->moveCube("B");
        this->rotateCube("z");
    }
    else if (currMove == "f'" || currMove == "Fw'"){
        this->moveCube("B'");
        this->rotateCube("z'");
    }
    else if (currMove == "f2" || currMove == "Fw2"){
        this->moveCube("f");
        this->moveCube("f");
    }
     else if (currMove == "b" || currMove == "Bw"){
        this->moveCube("F");
        this->rotateCube("z'");
    }
    else if (currMove == "b'" || currMove == "Bw'"){
        this->moveCube("F'");
        this->rotateCube("z");
    }
    else if (currMove == "b2" || currMove == "Bw2"){
        this->moveCube("b");
        this->moveCube("b");
    }
     else if (currMove == "u" || currMove == "Uw"){
        this->moveCube("D");
        this->rotateCube("y");
    }
    else if (currMove == "u'" || currMove == "Uw'"){
        this->moveCube("D'");
        this->rotateCube("y'");
    }
    else if (currMove == "u2" || currMove == "Uw2"){
        this->moveCube("u");
        this->moveCube("u");
    }
     else if (currMove == "d" || currMove == "Dw"){
        this->moveCube("U");
        this->rotateCube("y'");
    }
    else if (currMove == "d'" || currMove == "Dw'"){
        this->moveCube("U'");
        this->rotateCube("y");
    }
    else if (currMove == "d2" || currMove == "Dw2"){
        this->moveCube("d");
        this->moveCube("d");
    }
    else {
        this->rotateCube(move); // this assumes that none of the moves are invalid.
    }
    }
}

void Cube::print2D(RenderWindow& window) const {
     // int xStartPos(500), yStartPos(500), size(10), distance(1); // mini cube 
    int xStartPos(162), yStartPos(50), size(45), distance(4); // large cube
    int startHolder = xStartPos;
    RectangleShape square;
    square.setSize(Vector2f(size, size));
    square.setPosition(0,0);
    int j(0), z(0);
    for (int i = 0; i < 9; i++) {
        square.setFillColor(convertColor(_cubeState.at(i)));
        square.setPosition(xStartPos + (i - j) * (size+distance), yStartPos + z * (size+distance));
        if ((i + 1) % 3 == 0) {
                j += 3;
                z+=1;
            }
        window.draw(square);
    }
    yStartPos += 3 * (size + distance);
    for (int i = 0; i < 3; i++){
        xStartPos = startHolder -  3 * (size + distance);
        string leftThree = _cubeState.substr(9 + (i*3), 3);
        string frontThree = _cubeState.substr(18 + (i*3), 3);
        string rightThree = _cubeState.substr(27 + (i*3), 3);
        string backThree = _cubeState.substr(36 + (i*3), 3);
        for (int j = 0; j < 3; j++){
            square.setFillColor(convertColor(leftThree.at(j)));
            square.setPosition(xStartPos + (j) * (size+distance), yStartPos + i * (size+distance));
            window.draw(square);
        }
        xStartPos += 3 * (size + distance);
        for (int j = 0; j < 3; j++){
            square.setFillColor(convertColor(frontThree.at(j)));
            square.setPosition(xStartPos + (j) * (size+distance), yStartPos + i * (size+distance));
            window.draw(square);
        }
        xStartPos += 3 * (size + distance);
        for (int j = 0; j < 3; j++){
            square.setFillColor(convertColor(rightThree.at(j)));
            square.setPosition(xStartPos + (j) * (size+distance), yStartPos + i * (size+distance));
            window.draw(square);
        }
        xStartPos += 3 * (size + distance);
        for (int j = 0; j < 3; j++){
            square.setFillColor(convertColor(backThree.at(j)));
            square.setPosition(xStartPos + (j) * (size+distance), yStartPos + i * (size+distance));
            window.draw(square);
        }
    }
    xStartPos = startHolder;
    yStartPos += 3 * (size + distance);
    j = 0, z = 0;
    for (int i = 0; i < 9; i++) {
        square.setFillColor(convertColor(_cubeState.at(i + 45)));
        square.setPosition(xStartPos + (i - j) * (size+distance), yStartPos + z * (size+distance));
        if ((i + 1) % 3 == 0) {
                j += 3;
                z+=1;
            }
        window.draw(square);
    }
}

#endif
