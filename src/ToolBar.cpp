#include <ToolBar.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "macros.h"
#include "ObjectButton.h"
#include <fstream>
#include <iostream>
ToolBar::ToolBar(sf::Vector2f topLeft) : m_topLeft(topLeft)
{
	createButtonsFromFile();
}

void ToolBar::clicked(sf::Vector2i mouse_pos)
{
	int last_clicked_index = -1;

	for (int i = 0; i < m_buttons.size(); i++)
		if (m_buttons[i].clicked(mouse_pos))
		{
			last_clicked_index = i;
			active_button = m_buttons[i].getType();
			break;
		}
	
	if (last_clicked_index != -1)
		for (int i = 0; i < m_buttons.size(); i++)
			if (i != last_clicked_index)
				m_buttons[i].turnOff();

	if (last_clicked_index != -1)
		std::cout << "Active button type: " << active_button << '\n';
}

void ToolBar::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_buttons.size(); i++)
		m_buttons[i].draw(window);
}

void ToolBar::createButtonsFromFile()
{
	std::ifstream fileInput(TOOL_BAR_FILE_PATH);

	if (!fileInput.is_open())
		return;

	for (int i = 0; !fileInput.eof(); i++)
	{
		char type;
		fileInput >> type;
		m_buttons.emplace_back(type, sf::Vector2f(m_topLeft.x + i * (BUTTON_HEIGHT + TOOL_BAR_OFFSET), m_topLeft.y));
	}
}