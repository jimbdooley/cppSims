#include <iostream>
#include "modules/TestModule.h"
#include "modules/NeuralNetwork.hpp"
#include <eigen3/Eigen/Eigen>

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    // Ball movement variables
    float xSpeed = 0.1f; // Horizontal speed
    float ySpeed = 0.1f; // Vertical speed

    // Initial position
    shape.setPosition(375, 275); // Center it in the window

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update ball position
        sf::Vector2f position = shape.getPosition();
        position.x += xSpeed;
        position.y += ySpeed;

        // Check for collisions with window borders
        if (position.x < 0 || position.x + shape.getRadius() * 2 > window.getSize().x) {
            xSpeed = -xSpeed; // Reverse horizontal direction
        }
        if (position.y < 0 || position.y + shape.getRadius() * 2 > window.getSize().y) {
            ySpeed = -ySpeed; // Reverse vertical direction
        }

        shape.setPosition(position);

        // Clear, draw, and display
        window.clear();
        window.draw(shape);
        window.display();

        // Limit frame rate to approximately 60 fps
        sf::sleep(sf::milliseconds(16)); // ~60 fps
    }

    return 0;
}
