#include "Cube.hpp"
#include "Thistle.hpp"
#include "hash.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/System/Clock.hpp>
using namespace std;

int main(){
    
    ifstream fin ("moves.txt"); // gets all moves in moves.txt into the vector moves
    string move;
    vector<string> moves;
    while (fin >> move){
        moves.push_back(move);
    }

    Cube cube;
    RenderWindow window( VideoMode(640, 640),  "Cube");
    int update = 150;

    size_t i(0);
    int done = 0;

    while (window.isOpen()){
        window.clear();
        if(i != moves.size()) {
            cube.moveCube(moves.at(i));
            i += 1;
        }
        else if (i == moves.size() && done == 0){
            Thistle solver(cube.getCubeState());
            string Solution = solver.Solve();
            cout << "Solution: " << Solution << '\n';
            cout << "Solution Length: " << solver.GetSolutionLength() << '\n';
            istringstream iss(Solution);
            while(iss >> move){
                moves.push_back(move);
            }
            done = 1;
        }
        cube.print2D(window);
        window.display();
        Event event;
        while ( window.pollEvent(event) ){
            if ( event.type == Event::Closed ){
                window.close();
            }
        }
        sf::sleep(sf::milliseconds(update)); 
    }

    return 0;
}
