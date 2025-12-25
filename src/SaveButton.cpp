#include <SFML/Graphics.hpp>
#include "macros.h"
#include "SaveButton.h"
#include "Board.h"
#include "TextureManager.h"
SaveButton::SaveButton(sf::Vector2f top_left)
    : m_button(top_left) {}

void SaveButton::clicked(sf::Event::MouseButtonReleased mouse_event, const Board& board) const
{
	if (m_button.clicked(mouse_event))
	{
		board.save();
	}
}

void SaveButton::draw(sf::RenderWindow& window, const TextureManager& texture_manager) const
{
	sf::RectangleShape rect;

	rect.setPosition(m_button.getTopLeft());
	rect.setFillColor(sf::Color::White);

	rect.setSize(BUTTON_SIZE);

	rect.setTexture(texture_manager.getSaveButtonTexture());

	window.draw(rect);
}