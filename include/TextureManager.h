#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:	
	TextureManager();

	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;

	const sf::Texture* getTexture(const char id) const;
	const sf::Texture* getSaveBtnTexture() const;
	const sf::Texture* getClearBtnTexture() const;

private:
	const sf::Texture m_playerTexture;
	const sf::Texture m_enemyTexture;
	const sf::Texture m_coinTexture;
	const sf::Texture m_floorTexture;
	const sf::Texture m_brakableFloorTexture;
	const sf::Texture m_ladderTexture;
	const sf::Texture m_railTexture;
	const sf::Texture m_emptyTexture;
	const sf::Texture m_saveBtnTexture;
	const sf::Texture m_clearBtnTexture;
};