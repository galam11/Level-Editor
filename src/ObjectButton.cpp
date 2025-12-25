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

void ObjectButton::draw(sf::RenderWindow& window, const TextureManager& texture_manager) const
{
	sf::RectangleShape rect;

	rect.setTexture(texture_manager.getButtonTexture(), true);
	rect.setPosition(m_button.getTopLeft() + BUTTON_SIZE / 2.f);
	rect.setOrigin(BUTTON_SIZE / 2.f);
	
	rect.setSize(BUTTON_SIZE);

	
    if (m_active)
        rect.setFillColor(sf::Color::Blue);
	else 
		rect.setFillColor(sf::Color::White);


	window.draw(rect);

	rect.setTexture(texture_manager.getTexture(m_type), true);
	rect.scale(sf::Vector2f(0.7f, 0.7f));
	rect.setFillColor(sf::Color::White);

	window.draw(rect);
}