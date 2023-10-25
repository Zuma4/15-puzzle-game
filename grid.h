#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class grid {
	sf::Font consola;
	std::array<std::array<int, 6>, 6> m_gridMap{ { 
		{ -1, -1, -1, -1, -1, -1 },
		{ -1, 1, 2, 3, 4, -1 },
		{ -1, 5, 6, 7, 8, -1 },
		{ -1, 9, 10, 11, 12, -1 },
		{ -1, 13, 14, 15, 0, -1},
		{ -1, -1, -1, -1, -1, -1}
		} };

	std::array<std::array<sf::RectangleShape, 4>, 4> m_gridVisual;
	std::array<std::array<sf::Text, 4>, 4> m_numText;

public :
	grid();
	void move(int userInput);
	void shuffle();
	void draw(sf::RenderWindow& window);
	bool operator==(grid grid);
	void print();
	// test functions
	void shuffleToWin();
};