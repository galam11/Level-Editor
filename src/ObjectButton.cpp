#include "ObjectButton.h"
#include <SFML/Graphics.hpp>

ObjectButton::ObjectButton(char type, sf::Vector2f bottom_left, sf::Vector2f top_right)
    : m_type(type), m_bottom_left(bottom_left), m_top_right(top_right), m_active(false) {}

