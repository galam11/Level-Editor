#include <Board.h>
#include <fstream>
#include "macros.h"

#include <iostream>

Board::Board(sf::Vector2f top_left) : m_topLeft(top_left){}

void Board::save() const
{
	std::ofstream fileOutput(BOARD_FILE_PATH);

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
	std::ifstream fileInput(BOARD_FILE_PATH);

	if (!fileInput.is_open())
		return false;
	
	fileInput >> m_height;
	fileInput.get();

	if (m_height < 0)
		return false;
	

	m_boardData.resize(m_height);
	for (int i = 0; i < m_height; i++)
	{
		char input = fileInput.get();
		while (input != '\n' && !fileInput.eof())
		{
			m_boardData[i].push_back(input);
			input = fileInput.get();

			if (input == PLAYER) 
				m_playerLocation = sf::Vector2i(m_boardData[i].size() - 1, i);
		}
	}
	m_width = m_boardData[0].size();
	fileInput.close();


	if (m_width < 0)
		return false;
	
	return true;
}

void Board::clear()
{
	m_boardData = std::vector<std::vector<char>>(m_height, std::vector<char>(m_width, EMPTY));
	sf::RectangleShape rect;
	
}

void Board::createEmptyBoard(int width, int height)
{
	if (width > 0 && height > 0)
	{
		m_width = width;
		m_height = height;
		clear();
	}
}

void Board::setCell(sf::Vector2i pos, char value)
{
	if (inBounds(pos) && m_boardData[pos.y][pos.x] != value)
	{
		m_boardData[pos.y][pos.x] = value;

		if (value == PLAYER)
		{
			m_boardData[m_playerLocation.y][m_playerLocation.x] = EMPTY;
			m_playerLocation = pos;
		}
	}
}

sf::Vector2i Board::mouseToGridLocation(const sf::Event::MouseMoved& event) const
{
	auto pos = sf::Vector2i(
		(event.position.x - (int)m_topLeft.x) / CELL_SIZE,
		(event.position.y - (int)m_topLeft.y) / CELL_SIZE
	);

	if (inBounds(pos))
		return pos;
	return sf::Vector2i(-1, -1);
}

void Board::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rect;

	rect.setPosition(m_topLeft);
	rect.setSize({ m_width * CELL_SIZE , m_height * CELL_SIZE });
	rect.setFillColor(sf::Color(50,50,50));
	
	window.draw(rect);


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

			rect.setPosition(m_topLeft + sf::Vector2f((float) x * CELL_SIZE, (float) y * CELL_SIZE));
			window.draw(rect);
		}
	}
}

bool Board::inBounds(const sf::Vector2i& pos) const
{
	return pos.x >= 0 && pos.x < m_width && pos.y >= 0 && pos.y < m_height;
}
