#include "TextureManager.h"
#include "macros.h"
#include <SFML/Graphics.hpp>

TextureManager::TextureManager() :
	m_playerTexture				("player.png"),
	m_enemyTexture				("enemy.png"),
	m_coinTexture				("coin.png"),
	m_floorTexture				("floor.png"),
	m_brakableFloorTexture		("breakable_floor.png"),
	m_ladderTexture				("ladder.png"),
	m_railTexture				("rail.png"),
	m_saveBtnTexture			("save_button.png"),
	m_clearBtnTexture			("clear_button.png")
{ }

const sf::Texture* TextureManager::getTexture(const char id) const
{
	switch (id)
	{
	case PLAYER:
		return &m_playerTexture;

	case ENEMY:
		return &m_enemyTexture;

	case COIN:
		return &m_coinTexture;

	case FLOOR:
		return &m_floorTexture;

	case BREAKABLE_FLOOR:
		return &m_brakableFloorTexture;

	case LADDER:
		return &m_ladderTexture;

	case RAIL:
		return &m_railTexture;

	default: 
		return nullptr;
	}
}

const sf::Texture* TextureManager::getSaveBtnTexture() const
{
	return &m_saveBtnTexture;
}

const sf::Texture* TextureManager::getClearBtnTexture() const
{
	return &m_clearBtnTexture;
}