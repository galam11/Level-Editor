#include <Board.h>
#include <fstream>
#include "macros.h"


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
	{
		return false;
	}
	
	fileInput >> m_height;
	for (int i = 0; i < m_height; i++)
	{
		while (fileInput.peek() != '\n')
			m_boardData[i].push_back(fileInput.get());
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
	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			sf::RectangleShape rect;

			rect.setFillColor(sf::Color::Green);
			rect.setOutlineThickness(5.f);
			rect.setOutlineColor(sf::Color::White);
			rect.setPosition({(float) x * CELL_SIZE, (float) y * CELL_SIZE});

			window.draw(rect);
		}
	}
}