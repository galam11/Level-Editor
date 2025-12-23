#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class Board;

class SaveButton
{
public:
	SaveButton(sf::Vector2f top_left);

	void draw(sf::RenderWindow& window) const;
	void clicked(sf::Event::MouseButtonReleased mouse_event, const Board& board) const;

private:
	const Button m_button;
};