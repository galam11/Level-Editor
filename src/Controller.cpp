#include "Controller.h"
#include "ObjectButton.h"
#include "macros.h"

Controller::Controller()
	: m_window(sf::VideoMode({ 1200, 800 }), "Level Editor"), m_toolBar({ 50.f, 50.f })
{
	if (!m_board.load()) 
		exit(EXIT_FAILURE);
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		while (const auto event = m_window.pollEvent())
			event->visit([this](const auto& e) { handleEvent(e); });

		m_window.clear();

		//m_board.draw(m_window);
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
	m_toolBar.clicked(event.position);
}

void Controller::handleEvent(const auto&) {}