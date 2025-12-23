#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board(sf::Vector2f top_left);

	void save() const;
	void clear();
	bool load();

	void createEmptyBoard();
	void setCell(sf::Vector2i pos, char value);
	sf::Vector2i mouseToGridLocation(const sf::Event::MouseMoved& event) const;

	void draw(sf::RenderWindow& window);
private:
	bool inBounds(const sf::Vector2i& pos) const;

	std::vector<std::vector<char>> m_boardData;
	sf::Vector2f m_topLeft;
	sf::Vector2i m_playerLocation;
	int m_width = 1;
	int m_height = 1;
};
