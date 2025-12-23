#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "ToolBar.h"
#include "BoardCursor.h"

class Controller
{
public:
	Controller();

	void run();
private:
	void handleEvent(const auto&);
	
	void handleEvent(const sf::Event::MouseButtonReleased& event);
	
	void handleEvent(const sf::Event::MouseButtonPressed& event);
	
	void handleEvent(const sf::Event::MouseMoved& event);
	
	void handleEvent(const sf::Event::Closed& event);

	sf::RenderWindow m_window;
	ToolBar m_toolBar;
	Board m_board;
	BoardCursor m_currser;
};
