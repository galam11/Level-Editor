#include <SFML/Graphics.hpp>
#include "macros.h"
#include "ClearButton.h"
#include "Board.h"
#include <iostream>

ClearButton::ClearButton(sf::Vector2f top_left)
    : m_button(top_left) {}


void ClearButton::clicked(sf::Vector2i mouse_pos, Board& board) const
{
	if (m_button.clicked(mouse_pos))
	{
		board.clear();
		float height, width;
		std::cout << "Enter board height: ";
		std::cin >> height;
		std::cout << "Enter board width: ";
		std::cin >> width;
		board.createEmptyBoard(width, height);
	}
}

void ClearButton::draw(sf::RenderWindow& window) const
{
	m_button.draw(window);

	sf::RectangleShape shape;
	shape.setFillColor(sf::Color::Red);

	shape.setPosition(m_button.getTopLeft());
	shape.setSize(sf::Vector2f(10.f,10.f));
	
	window.draw(shape);
	// todo unique draw logic for ClearButton
}