#ifndef HASH_HPP
#define HASH_HPP
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief hashes the orientation of the edges on the cube using a cubestate
 * 
 * @return std::string 
 */
std::string hashOne(std::string);

/**
 * @brief hashes the location of the E edges and the orientation of the corners using a cubestate string
 * 
 * @return std::string 
 */
std::string hashTwo(std::string);

/**
 * @brief searches through a file to find a value, has parameter for key and the location of the file
 * 
 * @return std::string 
 */
std::string lookUpKey(std::string, std::string);


/**
 * @brief Create a hash map for a specific file, keys being the first value on a line, the value being the rest of the line
 * 
 * @return std::unordered_map<std::string, std::string> 
 */
std::unordered_map<std::string, std::string> createMap(std::string);

using namespace std;

string hashOne(string cubeState){
    char Ucolor = cubeState[4];
    char Fcolor = cubeState[22];
    char Bcolor = cubeState[40];
    char Dcolor = cubeState[49];
    // loop through edges
    int edgeValues[12][2] = {{1,37}, {3,10}, {5,28}, {7,19}, {41,12}, {21,14}, {23,30}, {39, 32}, {46, 25}, {48, 16}, {50, 34}, {52, 43}};
    string hash;
    char edge1, edge2;
    for (int i = 0; i < 12; i++){
        // check the orientation of the edge
        edge1 = cubeState[edgeValues[i][0]];
        edge2 = cubeState[edgeValues[i][1]];
        if (i < 4){
            if (edge1 == Ucolor || edge1 == Dcolor){
                hash += '0';
            }
            else if (edge2 == Ucolor || edge2 == Dcolor){
                hash += '1';
            }
            else if (edge1 == Fcolor || edge1 == Bcolor){
                hash += '0';
            }
            else{
                hash += '1';
            }
        }
        else if (i >= 4 and i < 8){
            if (edge1 == Ucolor || edge1 == Dcolor){
                hash += '0';
            }
            else if (edge2 == Ucolor || edge2 == Dcolor){
                hash += '1';
            }
            else if (edge1 == Fcolor || edge1 == Bcolor){
                hash += '0';
            }
            else{
                hash += '1';
            }
        }
        else{
            if (edge1 == Ucolor || edge1 == Dcolor){
                hash += '0';
            }
            else if (edge2 == Ucolor || edge2 == Dcolor){
                hash += '1';
            }
            else if (edge1 == Fcolor || edge1 == Bcolor){
                hash += '0';
            }
            else{
                hash += '1';
            }
        }
    }
    return hash;
}

string hashTwo(string cubeState){
    char Ucolor = cubeState[4];
    char Lcolor = cubeState[13];
    char Fcolor = cubeState[22];
    char Rcolor = cubeState[31];
    char Bcolor = cubeState[40];
    char Dcolor = cubeState[49];
    // corner and edge locations, index so that good orientation is first index in nested array
    int edgeValues[12][2] = {{1,37}, {3,10}, {5,28}, {7,19}, {41,12}, {21,14}, {23,30}, {39, 32}, {46, 25}, {48, 16}, {50, 34}, {52, 43}};
    int cornerValues[8][3] = {{0,38,9},{2,36,29},{6,18,11},{8,20,27},{45,24,17},{47,26,33},{51,44,15},{53,42,35}};
    // char sliceEdges[4][2] = {{Ucolor, Fcolor}, {Ucolor, Bcolor}, {Dcolor, Bcolor}, {Dcolor, Fcolor}};
    string hash;
    char edge1, edge2, currCorner;
    // loop through edges
    for (int i = 0; i < 12; i++){
        // check the location of slice edges
        edge1 = cubeState[edgeValues[i][0]];
        edge2 = cubeState[edgeValues[i][1]];
        if ((edge1 == Fcolor || edge1 == Bcolor) && (edge2 == Lcolor || edge2 == Rcolor)){
            hash += to_string(i);
        }
    }
    // loop through corners
    for (int i = 0; i < 8; i++){ 
        for (int j = 0; j < 3; j++){
            currCorner = cubeState[cornerValues[i][j]];
            if (currCorner == Ucolor || currCorner == Dcolor){
                // add orientation of important stick in corner
                hash += to_string(j);
                break; // exit nested loop if important sticker is found
            }    
        }
    }
    return hash;
}

string lookUpKey(string key, string table){
    ifstream fin (table);
    string currentKey;
    string line;
    while (getline(fin, line)){
        istringstream iss(line);
        iss >> currentKey;
        if (currentKey == key){
            return line.substr(key.length() + 1, line.length() - key.length() + 1); // returns moves that correspond to said key
        }
    }
    return "hashing failed"; // return if key was not found in the look up table
}

std::unordered_map<std::string, std::string> createMap(std::string file){
    cout << "creating tables...\n";
    std::unordered_map<std::string, std::string> map;
    ifstream fin(file);
    string currentKey;
    string line;
    while (getline(fin, line)){
        istringstream iss(line);
        iss >> currentKey;
        map[currentKey] = line.substr(currentKey.length() + 1, line.length() - currentKey.length() + 1);
    }
    cout << "done!\n";
    return map; // return if key was not found in the look up table
}

#endif
