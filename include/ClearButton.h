#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class ClearButton
{
public:
    ClearButton(sf::Vector2f top_left);

    void draw(sf::RenderWindow& window) const;
    void clicked(sf::Vector2i mouse_pos) const;

private:
    const Button m_button;
};