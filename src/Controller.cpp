#include "Controller.h"


Controller::Controller()
	: m_window(sf::VideoMode({ 800, 600 }), "Level Editor")
{
	m_board.createEmptyBoard(10, 10);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		if (const auto event = m_window.pollEvent())
			event->visit([this](const auto& e) { handleEvent(e); });
		

		m_window.clear();

		m_board.draw(m_window);

		m_window.display();
	}
}

void Controller::handleEvent(const sf::Event::Closed event)
{
	m_window.close();
}