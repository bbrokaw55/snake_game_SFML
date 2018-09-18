// ***
// Author : Ben Brokaw
// 
// CSCI 261 - A
//
// Declaration File for position class
//
// Date created: 4/20/18
//
// ***

#ifndef POSITION_H_
#define POSITION_H_

// Stores a Vector consiting of X-position and Y-Position
class Pos {
public:
    Pos();                          // Default Constructor (Center of Window)
    Pos(float x, float y);          // Initialize with X,Y Coordinates
    void mult(float scl);           // Multiplys Coords by Scale
    
    float x;                        // X Position
    float y;                        // Y Position
};

#endif  /* POSITION_H */