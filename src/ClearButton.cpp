#include <SFML/Graphics.hpp>
#include "macros.h"
#include "ClearButton.h"
#include "Board.h"
#include <iostream>

ClearButton::ClearButton(sf::Vector2f top_left)
    : m_button(top_left) {}


void ClearButton::clicked(sf::Event::MouseButtonReleased mouse_event, Board& board) const
{
	if (m_button.clicked(mouse_event))
	{
		board.createEmptyBoard();
	}
}

void ClearButton::draw(sf::RenderWindow& window, const TextureManager& texture_manager) const
{
	sf::RectangleShape rect;

	rect.setPosition(m_button.getTopLeft());
	rect.setFillColor(sf::Color::White);

	rect.setSize(BUTTON_SIZE);

	rect.setTexture(texture_manager.getClearButtonTexture());

	window.draw(rect);
}