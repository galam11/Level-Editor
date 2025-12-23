#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "macros.h"
#include "ObjectButton.h"
#include "ClearButton.h"
#include "SaveButton.h"

class Board;

class ToolBar
{
public:
	ToolBar(sf::Vector2f topLeft);
	
	void clicked(sf::Event::MouseButtonReleased mouseEvent, Board& board);
	void draw(sf::RenderWindow& window) const;
	char getActiveButton() const;
private:
	std::vector<ObjectButton> m_objectButtons;
	ClearButton m_clearButton;
	SaveButton m_saveButton;
	sf::Vector2f m_topLeft;

	char m_activeButton = EMPTY;

	void createButtonsFromFile();
};