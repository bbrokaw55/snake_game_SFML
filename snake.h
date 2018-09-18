// ***
// Author : Ben Brokaw
// 
// CSCI 261 - A
//
// Declaration file for snake class
//
// Date created: 4/20/18
//
// ***

#ifndef SNAKE_H_
#define SNAKE_H_


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include "position.h"


class Snake {
    private:   
        float x = 5.0 * scl;        // The current possition of the snake
        float y = 5.0 * scl;        // The current possition of the snake
        float xspeed = 1.0;         // The direction the snake is moving
        float yspeed = 0.0;         // The direction the snake is moving
        int total = 0;              // The length of the sankes tail
        const float HEIGHT = 400.0; // Height of the window
        const float WIDTH = 500.0;  // Width of the window
        int scl = HEIGHT / 25;      // the amount of blocks on the screen
        std::vector<Pos> tail = {}; // Vector holding the positions of the tail
        
        // Calculates the position between two points in space
        float dist(float x1, float y1, float x2, float y2); 
    
    public:
        Snake();                            // Default Constructor
        float getXspeed();                  // Returns xspeed
        float getYspeed();                  // Returns yspeed
        int getTotal();                     // Returns total
        bool eat(Pos pos);                  // Checks if snake head crosses food
        void dir(int, int);                 // changes the direction of the snake
        void death();                       // Checks if the snake has died
        void update(sf::RenderWindow& w);   // Updates snakes head and tail positions
        void show(sf::RenderWindow& w);     // Draws head and tail to window
        sf::RectangleShape head;            // SFML snake head object
        sf::RectangleShape snake;           // SFML snake tail object

};

#endif