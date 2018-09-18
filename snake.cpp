// ***
// Author : Ben Brokaw
// 
// CSCI 261 - A
//
// Definition file for snake class
//
// Date created: 4/20/18
//
// ***

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <vector>
//#include "position.h"
#include "snake.h"



Snake::Snake() {
                                                        // SFML TAIL STUFF
    snake.setSize(sf::Vector2f(scl ,scl));             //
    snake.setFillColor(sf::Color::Red);               //
    
                                                    // SFML HEAD STUFF
    head.setFillColor(sf::Color::Red);             //
    head.setSize(sf::Vector2f(scl ,scl));         //
    head.setPosition(x, y);                      //
}   

// Returns the speed in the X direction
float Snake::getXspeed() {
    return this->xspeed;
}

// Returns the speed in the Y direction
float Snake::getYspeed() {
    return this->yspeed;
}

// Returns the  length of the snakes tail
int Snake::getTotal() {
    return this->total;
}

// Checks if the snake's head is within eating distance 
// if so
// incriments tail length
bool Snake::eat(Pos pos) {
    float d = sqrt(pow(this->x - pos.x, 2) + pow(this->y - pos.y, 2));
    if (d < 10) {
        total++;
        return true;
    } 
    else {
        return false;
    }
}

// Changes the direction the snake is moving
void Snake::dir(int x, int y) {
    this->xspeed = x;
    this->yspeed = y;
}

// Checks if the snake has died
// If so
// Restarts game
void Snake::death() {
    
    for (int i = 0; i < int(tail.size()); i++) {
        Pos temp = tail.at(i);
        float d = dist(x, y, temp.x, temp.y);
        if (d < 1) {
          std::cout << "starting over\n";
          total = 0;
          tail.clear();
          this->xspeed = 1;
          this->yspeed = 0;
        }
    }   
}

// Updates the position of the snakes head and tail
void Snake::update(sf::RenderWindow& w) {
    if (total > 0) {
        if (total == int(tail.size()) && (int(tail.size()) != 0)) {
            tail.erase(tail.begin());
        }
        Pos temp(x,y);
        tail.push_back(temp);
    }

    x = x + (xspeed*scl);   // Incriments snake position by scale and speed
    y = y + (yspeed*scl);  //

    
    if (x > (WIDTH - scl)) {            // Allows snake to move outside the window
      x = 0;                           //
    }                                 //
    else if (x < 0) {                //
      x = WIDTH - scl;              //
    }                              //
    else if (y > HEIGHT - scl) {  //
      y = 0;                     //
    }                           //
    else if (y < 0) {          //
      y = HEIGHT - scl;       //
    }                        //
    
    
        for (int i = 0; i < int(tail.size()); ++i) {
        snake.setPosition(sf::Vector2f(tail.at(i).x, tail.at(i).y));
        
        }
    head.setPosition(sf::Vector2f(x, y));
    // std::cout   << head.getPosition().x << ", " << head.getPosition().y 
    //             << ", -->" << y << "\n";
}

// Draws the snake
void Snake::show(sf::RenderWindow& w) {
    for (int i = 0; i < int(tail.size()); ++i) {
        snake.setPosition(sf::Vector2f(tail.at(i).x, tail.at(i).y));
        w.draw(snake);
    }
    head.setPosition(sf::Vector2f(x, y));
    w.draw(head);
}

// Calculates the distance between to points
float Snake::dist(float x1, float y1, float x2, float y2)
{
    float distanceX = (x2 - x1);
    distanceX *= distanceX;
    float distanceY = (y2 - y1);
    distanceY *= distanceY;
    float finalD = sqrt(distanceX + distanceY);
    return finalD;
}