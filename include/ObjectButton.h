#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class ObjectButton
{
public:
	ObjectButton(char type, sf::Vector2f top_left);

	void draw(sf::RenderWindow& window) const;
	bool clicked(sf::Vector2i mouse_pos);
	void turnOff();
	char getType() const;

private:
	const char m_type;
	const Button m_button;
	bool m_active = false;
};