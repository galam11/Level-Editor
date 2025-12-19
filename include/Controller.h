#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Controller
{
public:
	Controller();

	void run();
private:

	void handleEvent(const auto) {};
	void handleEvent(const sf::Event::Closed event);

	sf::RenderWindow m_window;
	Board m_board;
};