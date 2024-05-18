#ifndef THISTLE_HPP
#define THISTLE_HPP
#include <fstream>
#include "Cube.hpp"
#include "hash.hpp"

class Thistle : public Cube {
public:
    /**
     * @brief Construct a new Thistle object with a cubestring.
     * 
     */
    Thistle(string);

    /**
     * @brief Solves the cube using the private stage functions
     * 
     * @return std::string 
     */
    std::string Solve();

    /**
     * @brief Set the Cube State of solution object
     * 
     */
    void setCubeState(std::string);

    /**
     * @brief Get the Solution Length object, or number of moves that are currently part of the solution string
     * 
     * @return int 
     */
    int GetSolutionLength() const;
private:

    /**
     * @brief orientents corners of cube state, adds solution to _solution, and makes moves to influence cubeState of class
     * 
     */
    void stageOne();

    /**
     * @brief fixed slice edges and orients corners, adds solution to _solution, and makes moves to influence cubeState of class
     * 
     */
    void stageTwo();

    /**
     * @brief fixed edges and corner in there tetrads to avoid edge or corner parity in the next stage, adds solution to _solution, and makes moves to influence cubeState of class
     * 
     */
    void stageThree();

    /**
     * @brief finished the solution to the cube, adds solution to _solution, and makes moves to influence cubeState of class
     * 
     */
    void stageFour();

    std::string _solution; // current found solution to the cube

    std::unordered_map<std::string, std::string> _map; // hash map of the last stage to make solving stage 3 and stage 4 easier.
};

using namespace std;

Thistle::Thistle(string cubeState){
    _cubeState = cubeState;
    _solution = "";
    _map = createMap("data/thistlethwaite/lookUpStage3.txt");
}

void Thistle::setCubeState(string cubeState){
    _cubeState = cubeState;
}

int Thistle::GetSolutionLength() const{
    istringstream iss(_solution);
    string move;
    vector<string> moves;
    while(iss >> move){
        moves.push_back(move);
    }
    return int(moves.size());
}

void Thistle::stageOne(){
    string hash = hashOne(_cubeState);
    string moves = lookUpKey(hash, "data/thistlethwaite/lookUpStage0.txt");
    cout << "Stage 1: " << moves << '\n';
    if (moves != "hashing failed"){
        _solution += moves;
        this->moveCube(moves);
    }
}

void Thistle::stageTwo(){
    string hash = hashTwo(_cubeState);
    string moves = lookUpKey(hash, "data/thistlethwaite/lookUpStage1.txt");
    cout << "Stage 2: " << moves << '\n';
    if (moves != "hashing failed"){
        _solution += moves;
        this->moveCube(moves);
    }
}

void Thistle::stageThree(){
    string save = _cubeState;
    string moves;
    ifstream fin("data/thistlethwaite/stage2.txt");
    while (getline(fin, moves)){
        this->moveCube(moves);
        if (_map.find(_cubeState) != _map.end()){
            cout << "Stage 3: " << moves << '\n';
            _solution += moves;
            break;
        }
        _cubeState = save;
    }
}

void Thistle::stageFour(){
    string hash = _cubeState;
    if (_map.find(hash) == _map.end()){
        cout << "sorry something went wrong :(" << '\n';
    }
    else{
        cout << "Stage 4: " << _map[hash] << '\n';
        _solution += _map[hash];
        this->moveCube(_map[hash]);
    }
}

string Thistle::Solve(){
    _solution = ""; // make solution an empty string to avoid adding solution on to each other
    this->stageOne();
    this->stageTwo();
    this->stageThree();
    this->stageFour();
    return _solution;
}

#endif
