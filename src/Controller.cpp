#include "Controller.h"
#include "ObjectButton.h"
#include "macros.h"

Controller::Controller() : 
	m_window(sf::VideoMode(WINDOW_SIZE), "Level Editor"), 
	m_toolBar(TOOL_BAR_POS),
	m_board(BOARD_POS)
{
	if (!m_board.load()) 
		m_board.createEmptyBoard();
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		while (const auto event = m_window.pollEvent())
			event->visit([this](const auto& e) { handleEvent(e); });

		m_window.clear();

		m_board.draw(m_window);
		m_toolBar.draw(m_window);
		m_currser.draw(m_window);

		m_window.display();
	}
}

void Controller::handleEvent(const sf::Event::Closed& event)
{
	m_window.close();
}

void Controller::draw()
{
	auto pos = m_currser.getPosition();
	if (pos != sf::Vector2i(-1, -1))
		m_board.setCell(pos, m_toolBar.getActiveButtonID());
}

void Controller::handleEvent(const sf::Event::MouseButtonReleased& event)
{
	m_toolBar.clicked(event, m_board);
	
	if (event.button == sf::Mouse::Button::Left)
		m_mouseHeld = false;
}

void Controller::handleEvent(const sf::Event::MouseMoved& event)
{
	m_currser.updatePosition(event, m_board);

	if (m_mouseHeld)
		draw();
}

void Controller::handleEvent(const sf::Event::MouseButtonPressed& event)
{
	if (event.button == sf::Mouse::Button::Left)
	{
		m_mouseHeld = true;
		draw();
	}
}

void Controller::handleEvent(const auto&) { }