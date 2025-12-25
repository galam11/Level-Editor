#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const std::string BOARD_FILE_PATH		= "Board.txt";
const std::string TOOL_BAR_FILE_PATH	= "ToolBar.txt";

const char PLAYER						= '@';
const char ENEMY						= '%';
const char COIN							= '*';
const char FLOOR						= '#';
const char BREAKABLE_FLOOR				= '^';
const char LADDER						= 'H';
const char RAIL							= '-';
const char EMPTY						= ' ';

const float CELL_SIZE					= 32;

const float TOOL_BAR_OFFSET				= 5;

const float BUTTON_WIDTH				= 65;
const float BUTTON_HEIGHT				= 65;

const sf::Vector2f BUTTON_SIZE			= sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT);

const sf::Vector2f TOOL_BAR_POS			= sf::Vector2f(10.f, 10.f);
const sf::Vector2f BOARD_POS			= TOOL_BAR_POS + sf::Vector2f(BUTTON_WIDTH + TOOL_BAR_OFFSET * 2,0.f);
const sf::Vector2u WINDOW_SIZE			= sf::Vector2u(1600, 900);