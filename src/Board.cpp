#include <Board.h>
#include <fstream>
#include "macros.h"

#include <iostream>

Board::Board(sf::Vector2f position) : 
	m_position(position){ }

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
		char input = (char)fileInput.get();
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
}

void Board::createEmptyBoard()
{
	float height, width;
	std::cout << "Enter board height: ";
	std::cin >> height;
	std::cout << "Enter board width: ";
	std::cin >> width;

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
			if (m_boardData[m_playerLocation.y][m_playerLocation.x] == PLAYER)
				m_boardData[m_playerLocation.y][m_playerLocation.x] = EMPTY;
			m_playerLocation = pos;
		}
	}
}

sf::Vector2i Board::mouseToGridLocation(const sf::Event::MouseMoved& event) const
{
	auto pos = sf::Vector2i(
		(event.position.x - (int)m_position.x) / CELL_SIZE,
		(event.position.y - (int)m_position.y) / CELL_SIZE
	);

	if (inBounds(pos) && !(event.position.x < (int)m_position.x || event.position.y < (int)m_position.y))
		return pos;
	return sf::Vector2i(-1, -1);
}

void Board::draw(sf::RenderWindow& window, const TextureManager& texture_manager)
{
	sf::RectangleShape rect;

	rect.setPosition(m_position);
	rect.setSize({ m_width * CELL_SIZE , m_height * CELL_SIZE });
	rect.setFillColor(sf::Color(50,50,50));
	
	window.draw(rect);

	rect.setFillColor(sf::Color::White);
	rect.setSize({ CELL_SIZE, CELL_SIZE });

	for (int x = 0; x < m_width; x++)
	{
		for (int y = 0; y < m_height; y++)
		{
			if (m_boardData[y][x] == EMPTY)
				continue;

			rect.setTexture(texture_manager.getTexture(m_boardData[y][x]));
			rect.setPosition(m_position + sf::Vector2f((float) x * CELL_SIZE, (float) y * CELL_SIZE));
			window.draw(rect);
		}
	}
}

bool Board::inBounds(const sf::Vector2i& pos) const
{
	return pos.x >= 0 && pos.x < m_width && pos.y >= 0 && pos.y < m_height;
}
