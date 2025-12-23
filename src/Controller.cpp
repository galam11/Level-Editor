#include "Controller.h"
#include "ObjectButton.h"
#include "macros.h"

Controller::Controller() : 
	m_window(sf::VideoMode(WINDOW_SIZE), "Level Editor"), 
	m_toolBar(TOOL_BAR_POS),
	m_board(BOARD_POS)
{
	if (!m_board.load()) 
		exit(EXIT_FAILURE);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		if (const auto event = m_window.pollEvent())
			event->visit([this](const auto& e) { handleEvent(e); });

		m_window.clear();

		m_board.draw(m_window);
		m_toolBar.draw(m_window);

		m_window.display();
	}
}

void Controller::handleEvent(const sf::Event::Closed& event)
{
	m_window.close();
}

void Controller::handleEvent(const sf::Event::MouseButtonReleased& event)
{
	if (event.button == sf::Mouse::Button::Left)
		m_toolBar.clicked(event.position, m_board);
}

void Controller::handleEvent(const auto&) {}