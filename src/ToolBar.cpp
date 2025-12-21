#include "ToolBar.h"
#include "macros.h"
#include "ObjectButton.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>

ToolBar::ToolBar(sf::Vector2f topLeft) : 
	m_topLeft(topLeft),
	m_clearButton(topLeft + sf::Vector2f(0, BUTTON_HEIGHT + TOOL_BAR_OFFSET)),
	m_saveButton(topLeft + sf::Vector2f(BUTTON_WIDTH + TOOL_BAR_OFFSET, BUTTON_HEIGHT + TOOL_BAR_OFFSET))
{
	createButtonsFromFile();
}

void ToolBar::clicked(sf::Vector2i mouse_pos, Board& board)
{
	int last_clicked_index = -1;

	for (int i = 0; i < m_objectButtons.size(); i++)
		if (m_objectButtons[i].clicked(mouse_pos))
		{
			last_clicked_index = i;
			m_activeButton = m_objectButtons[i].getType();
			break;
		}
	
	if (last_clicked_index != -1)
		for (int i = 0; i < m_objectButtons.size(); i++)
			if (i != last_clicked_index)
				m_objectButtons[i].turnOff();

	m_clearButton.clicked(mouse_pos, board);
	m_saveButton.clicked(mouse_pos, board);

}

void ToolBar::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_objectButtons.size(); i++)
		m_objectButtons[i].draw(window);

	m_clearButton.draw(window);
	m_saveButton.draw(window);
}

void ToolBar::createButtonsFromFile()
{
	std::ifstream fileInput(TOOL_BAR_FILE_PATH);

	if (!fileInput.is_open())
		return;

	for (int i = 0; !fileInput.eof(); i++)
	{
		char type;
		if ((type = fileInput.get()) == -1)
			break;

		m_objectButtons.emplace_back(type, sf::Vector2f(m_topLeft.x + i * (BUTTON_WIDTH + TOOL_BAR_OFFSET), m_topLeft.y));
	}
}