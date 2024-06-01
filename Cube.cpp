#include "Cube.h"

using namespace std;
using namespace sf;

Cube::Cube(){
    for ()
}

Color convertColor(const char colorChar){ // converts sides into sfml color
    char chars[6] = {'D', 'R', 'F', 'L', 'B', 'U'}; 
    Color colors[6] = {Color::Yellow, Color::Red, Color::Green, Color(255, 153, 0), Color::Blue, Color::White};
    for (int i = 0; i < 6; i++){
        if (chars[i] == colorChar){ 
            return colors[i];
        }
    }
    return Color::Black; // return black if color is not found
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
