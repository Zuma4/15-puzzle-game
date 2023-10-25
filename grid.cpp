#include "grid.h"
#include "random.h"
#include <iostream>
#include "global.h"

void grid::move(int userInput) {

	std::array<int, 2> emptyIndex{};

	for (int y = 0; y < m_gridMap.size(); ++y) {
		for (int x = 0; x < m_gridMap[0].size(); ++x) {
			if (m_gridMap[y][x] == 0) {
				emptyIndex = { y, x };
				break;
			}
		}
	}

	// 1 = up
	// 2 = down
	// 3 = right
	// 4 = left
	if (userInput == 2) {
		if (m_gridMap[emptyIndex[0] - 1][emptyIndex[1]] != -1)
			std::swap(m_gridMap[emptyIndex[0] - 1][emptyIndex[1]], m_gridMap[emptyIndex[0]][emptyIndex[1]]);
	}

	else if (userInput == 1) {
		if (m_gridMap[emptyIndex[0] + 1][emptyIndex[1]] != -1)
			std::swap(m_gridMap[emptyIndex[0] + 1][emptyIndex[1]], m_gridMap[emptyIndex[0]][emptyIndex[1]]);
	}

	else if (userInput == 4) {
		if (m_gridMap[emptyIndex[0]][emptyIndex[1] + 1] != -1)
			std::swap(m_gridMap[emptyIndex[0]][emptyIndex[1] + 1], m_gridMap[emptyIndex[0]][emptyIndex[1]]);
	}

	else if (userInput == 3) {
		if (m_gridMap[emptyIndex[0]][emptyIndex[1] - 1] != -1)
			std::swap(m_gridMap[emptyIndex[0]][emptyIndex[1] - 1], m_gridMap[emptyIndex[0]][emptyIndex[1]]);
	}

}

void grid::shuffle() {
	for (int i = 0; i < 200; ++i) {
		move(Random::get(1, 4));
	}
}

void grid::print() {
	for (int y = 1; y < m_gridMap.size() - 1; ++y) {
		for (int x = 1; x < m_gridMap[0].size() - 1; ++x){
			if (m_gridMap[y][x] == 0)
				std::cout << "  ";
			else 
				std::cout << m_gridMap[y][x] << ' ';
		}
		std::cout << '\n';
	}
}

bool grid::operator==(grid grid) {
	bool identical = true;

	for (int y = 0; y < m_gridMap.size(); ++y) {
		for (int x = 0; x < m_gridMap[0].size(); ++x) {
			if (m_gridMap[y][x] != grid.m_gridMap[y][x]) {
				identical = false;
				break;
			}
		}
	}

	return identical;
}

grid::grid() {
	consola.loadFromFile("consola.ttf");

	int addy = 0;
	int addx = 0;
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {

			// handling numbers text
			m_numText[y][x].setFont(consola);
			m_numText[y][x].setFillColor(sf::Color::Black);
			m_numText[y][x].setCharacterSize(70);
			m_numText[y][x].setPosition(180 + addx, 50 + addy);

			// handling rectangles for visuals
			m_gridVisual[y][x].setPosition(170 + addx, 50 + addy);
			m_gridVisual[y][x].setFillColor(sf::Color::White);
			m_gridVisual[y][x].setSize(sf::Vector2f(100, 100));
			addx += 120;
		}
		addx = 0;
		addy += 120;

	}
}

void grid::draw(sf::RenderWindow& window) {
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {

			// pre drawing
			// for rects
			if (m_gridMap[y + 1][x + 1] == 0)
				continue;
			m_gridVisual[y][x].setOutlineThickness(5);

			if (m_gridMap[y + 1][x + 1] == winGrid.m_gridMap[y + 1][x + 1])
				m_gridVisual[y][x].setOutlineColor(sf::Color(255, 127, 80));
			else
				m_gridVisual[y][x].setOutlineColor(sf::Color::Black);

			// for text
			m_numText[y][x].setString(std::to_string(m_gridMap[y + 1][x + 1]));


			window.draw(m_gridVisual[y][x]);
			window.draw(m_numText[y][x]);
		}
	}
}

void grid::shuffleToWin() {
	m_gridMap = {{ 
				{ -1, -1, -1, -1, -1, -1 },
				{ -1, 1, 2, 3, 4, -1 },
				{ -1, 5, 6, 7, 8, -1 },
				{ -1, 9, 10, 11, 0, -1 },
				{ -1, 13, 14, 15, 12, -1 },
				{ -1, -1, -1, -1, -1, -1 }
				 }};
}