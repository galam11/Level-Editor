#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board() = default;

	void save() const;
	void clear();
	bool load();

	void createEmptyBoard(int width, int height);
	void setCell(sf::Vector2i pos, char value);

	void draw(sf::RenderWindow& window);
private:
	std::vector<std::vector<char>> m_boardData;
	int m_width = 0;
	int m_height = 0;
};
