#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>


class ObjectButton
{
public:
	ObjectButton(char type, sf::Vector2f bottom_left, sf::Vector2f top_right);

	void draw(sf::RenderWindow& window);
	void clicked();
	void turnOff();

private:
	const char m_type;
	const sf::Vector2f m_bottom_left;
	const sf::Vector2f m_top_right;
	bool m_active;
};