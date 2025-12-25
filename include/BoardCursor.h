#pragma once
#include <SFML/Graphics.hpp>

class Board;
class TextureManager;

class BoardCursor
{
public:
	BoardCursor() = default;
	void draw(sf::RenderWindow& window, const TextureManager& texture_manager) const;
	void updatePosition(const sf::Event::MouseMoved& event, const Board& board);

	const sf::Vector2i& getPosition() const;

private:
	sf::Vector2i m_position = sf::Vector2i(-1, -1);
};