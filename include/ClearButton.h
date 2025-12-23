#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class ClearButton
{
public:
    ClearButton(sf::Vector2f top_left);

    void draw(sf::RenderWindow& window) const;
    void clicked(sf::Event::MouseButtonReleased mouse_pos, Board& board) const;

private:
    const Button m_button;
};