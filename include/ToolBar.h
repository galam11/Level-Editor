#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "macros.h"
#include "ObjectButton.h"

class ToolBar
{
public:
	ToolBar(sf::Vector2f topLeft);
	
	void clicked(sf::Vector2i mouse_pos);
	void draw(sf::RenderWindow& window) const;
private:
	std::vector<ObjectButton> m_buttons;
	sf::Vector2f m_topLeft;

	char active_button = EMPTY;

	void createButtonsFromFile();
};