#include "ObjectButton.h"
#include <SFML/Graphics.hpp>
#include "macros.h"

ObjectButton::ObjectButton(char type, sf::Vector2f top_left)
    : m_type(type), m_button(top_left) {}


bool ObjectButton::clicked(sf::Event::MouseButtonReleased mouseEvent)
{
    if (m_button.clicked(mouseEvent))
    {
        m_active = true;
        //todo
		return true;
    }
    return false;
}

void ObjectButton::turnOff()
{
	m_active = false;
}

char ObjectButton::getType() const
{
	return m_type;
}

void ObjectButton::draw(sf::RenderWindow& window) const
{
    if (m_active)
    {
        sf::RectangleShape activeShape;
        activeShape.setPosition(m_button.getTopLeft());
        activeShape.setSize({ BUTTON_WIDTH, BUTTON_HEIGHT });
        activeShape.setFillColor(sf::Color::Yellow);
        window.draw(activeShape);
	}
    else m_button.draw(window);
}