#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Board
{
public:
	Board(sf::Vector2f position);

	void save() const;
	void clear();
	bool load();

	void createEmptyBoard();
	void setCell(sf::Vector2i pos, char value);
	sf::Vector2i mouseToGridLocation(const sf::Event::MouseMoved& event) const;

	void draw(sf::RenderWindow& window, const TextureManager& texture_manager);
private:
	bool inBounds(const sf::Vector2i& pos) const;

	std::vector<std::vector<char>> m_boardData;
	sf::Vector2f m_position;

	int m_width = 1;
	int m_height = 1;

	sf::Vector2i m_playerLocation = sf::Vector2i(-1, -1);
};
