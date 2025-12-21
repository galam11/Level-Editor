#include <SFML/Graphics.hpp>
#include "macros.h"
#include "SaveButton.h"
#include "Board.h"

SaveButton::SaveButton(sf::Vector2f top_left)
    : m_button(top_left) {}

void SaveButton::clicked(sf::Vector2i mouse_pos, const Board& board) const
{
	if (m_button.clicked(mouse_pos))
	{
		board.save();
	}
}

void SaveButton::draw(sf::RenderWindow& window) const
{
	m_button.draw(window);
	// todo unique draw logic for SaveButton
}