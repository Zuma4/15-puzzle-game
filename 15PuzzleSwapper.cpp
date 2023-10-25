#include <iostream>
#include <SFML/Graphics.hpp>
#include "grid.h"


const grid winGrid{};
int main() {

    // render Window initializing
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);


    // object initializing
    // game grid
    grid mainGrid{};
    mainGrid.shuffle();
    // win grid
    // in-global

    // winCount
    int winCount = 0;
    sf::Text winCountText;
    sf::Font consola;
    consola.loadFromFile("consola.ttf");
    winCountText.setCharacterSize(15);
    winCountText.setFont(consola);
    winCountText.setPosition(10, 10);
    winCountText.setFillColor(sf::Color::Black);
    

    // timer for moving
    sf::Clock moveClock;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        // winning count
        winCountText.setString("Winning Count: " + std::to_string(winCount));


        // handling user input;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && moveClock.getElapsedTime().asSeconds() > 0.2) {
            mainGrid.move(1);
            moveClock.restart();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && moveClock.getElapsedTime().asSeconds() > 0.2) {
            mainGrid.move(2);
            moveClock.restart();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && moveClock.getElapsedTime().asSeconds() > 0.2) {
            mainGrid.move(3);
            moveClock.restart();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && moveClock.getElapsedTime().asSeconds() > 0.2) {
            mainGrid.move(4);
            moveClock.restart();
        }



        // check winning
        if (mainGrid == winGrid) {
            std::cout << "You Won.\n";
            winCount += 1;
            mainGrid.shuffle();
        }


        window.clear(sf::Color::White);
        mainGrid.draw(window);
        window.draw(winCountText);
        window.display();
    }
}

// show things (done)
// create grid (done)
// show grid (done)
// randomize grid (done)


// user things
// moving elements in grid (done)
// winning if grid == winning grid (done)
// randomize grid after winning (done)

