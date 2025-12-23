#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>


class Button
{
public:
	Button(sf::Vector2f top_left);

	bool clicked(sf::Event::MouseButtonReleased mouse_pos) const;
	void draw(sf::RenderWindow& window) const;
	sf::Vector2f getTopLeft() const;

private:
	const sf::Vector2f m_top_left;
	const sf::Vector2f m_bottom_right;
};