#include "BoardCursor.h"
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "macros.h"


void BoardCursor::draw(sf::RenderWindow& window, const TextureManager& texture_manager) const
{
	if (m_position == sf::Vector2i(-1, -1)) return;

	sf::RectangleShape shape;
	shape.setFillColor(sf::Color::Transparent);

	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1.f);

	shape.setPosition(BOARD_POS + sf::Vector2f(
		m_position.x * CELL_SIZE,
		m_position.y * CELL_SIZE
		));
	shape.setSize({ CELL_SIZE , CELL_SIZE });
	window.draw(shape);	
}

void BoardCursor::updatePosition(const sf::Event::MouseMoved& event, const Board& board)
{
	m_position = board.mouseToGridLocation(event);
}

const sf::Vector2i& BoardCursor::getPosition() const
{
	return m_position;
}

