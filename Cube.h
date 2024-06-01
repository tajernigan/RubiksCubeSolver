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
     * @brief moves the cube based on rubiks cube notion
     * 
     */
    void moveCube(std::string);

    /**
     * @brief prints the cubeState of the cube into sfml in a 2D format
     * 
     */
    void print2D(sf::RenderWindow&) const;

    private:

    struct edge {
        char top;
        char front;
        
        void swap(){ // swaps edges
            char hold = top;
            top = front;
            front = hold;
        }
    };

    struct corner { // needs a swap thing
        char top;
        char front;
        char side;
    };
    

    edge* edges[12]; // represents cubes edges
    corner* corners[8]; // represents cubes corners
};

#endif
