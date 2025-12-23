#include <SFML/Graphics.hpp>
#include "macros.h"
#include "SaveButton.h"
#include "Board.h"

SaveButton::SaveButton(sf::Vector2f top_left)
    : m_button(top_left) {}

void SaveButton::clicked(sf::Event::MouseButtonReleased mouse_event, const Board& board) const
{
	if (m_button.clicked(mouse_event))
	{
		board.save();
	}
}

void SaveButton::draw(sf::RenderWindow& window) const
{
	m_button.draw(window);

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);

    shape.setPosition(m_button.getTopLeft());
    shape.setSize(sf::Vector2f(10.f, 10.f));

    window.draw(shape);
	// todo unique draw logic for SaveButton
}