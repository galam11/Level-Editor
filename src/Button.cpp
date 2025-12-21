#include "Button.h"
#include <SFML/Graphics.hpp>
#include "macros.h"

Button::Button(sf::Vector2f top_left) : 
	m_top_left(top_left), m_bottom_right(top_left + BUTTON_SIZE) { }	

bool Button::clicked(sf::Vector2i mouse_pos) const
{
	return (mouse_pos.x >= m_top_left.x && mouse_pos.x <= m_bottom_right.x &&
		mouse_pos.y >= m_top_left.y && mouse_pos.y <= m_bottom_right.y);
}

sf::Vector2f Button::getTopLeft() const
{
	return m_top_left;
}

void Button::draw(sf::RenderWindow& window) const
{
	sf::RectangleShape buttonShape;
	buttonShape.setPosition(m_top_left);
	buttonShape.setSize({ BUTTON_WIDTH, BUTTON_HEIGHT });
	buttonShape.setFillColor(sf::Color::Green);
	window.draw(buttonShape);
}