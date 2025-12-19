#include <Board.h>
#include <fstream>
#include "macros.h"

#include <iostream>

void Board::save()
{
	std::ofstream fileOutput(FILE_PATH);

	if (!fileOutput.is_open())
		return;

	fileOutput << m_height << '\n';
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
			fileOutput << m_boardData[i][j];
		fileOutput << '\n';
	}

	fileOutput.close();
}

bool Board::load()
{
	std::ifstream fileInput(FILE_PATH);

	if (!fileInput.is_open())
		return false;
	
	fileInput >> m_height;
	fileInput.get();

	m_boardData.resize(m_height);
	for (int i = 0; i < m_height; i++)
	{
		std::cout << i << ": ";

		char input = fileInput.get();
		while (input != '\n' && !fileInput.eof())
		{
			m_boardData[i].push_back(input);
			input = fileInput.get();
		}
		std::cout << std::endl;
	}
	m_width = m_boardData[0].size();
	fileInput.close();
	return true;
}

void Board::clear()
{
	m_boardData = std::vector<std::vector<char>>(m_height, std::vector<char>(m_width, EMPTY));
}

void Board::createEmptyBoard(int width, int height)
{
	m_width = width;
	m_height = height;
	clear();
}

void Board::setCell(sf::Vector2i pos, char value)
{
	if (pos.x >= 0 && pos.x < m_width && pos.y >= 0 && pos.y < m_height)
		m_boardData[pos.y][pos.x] = value;
}

void Board::draw(sf::RenderWindow& window)
{

	sf::RectangleShape rect;

	rect.setFillColor(sf::Color::Green);
	rect.setSize({ CELL_SIZE - 1, CELL_SIZE - 1 });

	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			switch (m_boardData[y][x])
			{
				case PLAYER:
					rect.setFillColor(sf::Color::Blue);
					break;
				case ENEMY:
					rect.setFillColor(sf::Color::Red);
					break;
				case COIN:
					rect.setFillColor(sf::Color::Yellow);
					break;
				case FLOOR:
					rect.setFillColor(sf::Color{ 210, 210, 210 });
					break;
				case BREAKABLE_FLOOR:
					rect.setFillColor(sf::Color{ 210, 210, 240 });
					break;
				case LADDER:
					rect.setFillColor(sf::Color{ 150 , 75 , 0 });
					break;
				case RAIL:
					rect.setFillColor(sf::Color{ 0 , 75 , 150 });
					break;
			default:
				break;
			}

			if (m_boardData[y][x] == EMPTY)
				continue;

			rect.setPosition({(float) x * CELL_SIZE, (float) y * CELL_SIZE});
			window.draw(rect);
		}
	}
}