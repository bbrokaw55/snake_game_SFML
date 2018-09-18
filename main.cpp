/* CSCI 261 Final Project: Snake Game
 *
 * CSCI 261 - A
 *
 * Author: Ben Brokaw
 *
 * Plays a simple snake game in SFML
 */

#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "snake.h"
// #include "position.h"

const float HEIGHT = 400.0;     // Height of the window
const float WIDTH = 500.0;      // Width of the window
int scl = HEIGHT / 25;          // Scale of the objects on screen
int cols = WIDTH/scl;           // Number of collums in the window
int rows = HEIGHT/scl;          // Number of rows in the window
Pos food;                       // Position Struct for X,Y coords of food
Snake s;                        // Snake class object

//Initializes the food and render window in SFML
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game");
sf::RectangleShape foodBlock(sf::Vector2f(scl, scl));


// picks a new random location for the food object
void pickLocation() {
  int cols = WIDTH/scl;
  int rows = HEIGHT/scl;
  food.x = (rand() % cols);
  food.y = (rand() % rows);
  food.mult(scl);
}

// The main loop for the game
// Checks for food being eater, death conditions
// updates the position of the snake and food if nessecary
// draws the food ,snake head, and tail to the screen
void draw() {

  if ((s.eat(food)) == true) {
    scl = scl + 5;
    pickLocation();
  }
  s.death();
  s.update(window);
  s.show(window);
  window.draw(foodBlock);
}

// Allows the user to move the snake with arrowkeys
void keyPressed() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true) {
        if (s.getYspeed() != 1) {   // Prevents snake from moving moving backwards
            s.dir(0, -1);
        }
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true) {
        if (s.getYspeed() != -1) {  // Prevents snake from moving moving backwards
            s.dir(0, 1);
        }
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) {
        if (s.getXspeed() != -1) {  // Prevents snake from moving moving backwards
            s.dir(1, 0);
        }
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true) {
        if (s.getXspeed() != 1) {   // Prevents snake from moving moving backwards
            s.dir(-1, 0);
        }
    }
}

// Updates the score text to the current total
void updateScore(sf::Text& t) {
    std::string score = "Score: " + std::to_string(s.getTotal());
    t.setString(score);
}

int main() {
    
    // Declare and load a font
    sf::Font font;
    font.loadFromFile("cmtt10.ttf");

    // Create a text
    sf::Text score("Score", font);
    score.setCharacterSize(20);
    score.setStyle(sf::Text::Bold);
    score.setColor(sf::Color::White);
    score.setPosition(WIDTH - 150.0, HEIGHT - 40.0);
    
    foodBlock.setFillColor(sf::Color::Yellow);
    window.setFramerateLimit(10);
    pickLocation();
    
    // Draw Loop    
	while (window.isOpen())
	{
		sf::Event event;                
		while (window.pollEvent(event))
		{   // Keypresses happen in poll event loop to prevent multiple clicks
		    keyPressed();
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// ANIMATION LOOP START //
        window.clear();
        
        foodBlock.setPosition(sf::Vector2f(food.x, food.y)); // set food position
        draw();                 
        updateScore(score);
        window.draw(score);
        
        window.display();
        // ANIMATION LOOP END //
	}
    
    
    
    return 0;
}