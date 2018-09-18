// ***
// Author : Ben Brokaw
// 
// CSCI 261 - A
//
// Definition file for position class
//
// Date created: 4/20/18
//
// ***

#include "position.h"

//using namespace std;

// Initializes to center of window
Pos::Pos() {
    this->x = (500 / 2);
    this->y = (400 / 2);
}

// Initializes to X,Y coordinates
Pos::Pos(float x, float y) {
    this->x = x;
    this->y = y;
}

// Multiplies coordinates by the scale
void Pos::mult(float scl) {
    this->x = (this->x * scl);
    this->y = (this->y * scl);
}
