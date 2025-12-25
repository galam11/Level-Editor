#include "TextureManager.h"
#include "macros.h"
#include <iostream>

TextureManager::TextureManager() {
    m_textures[PLAYER] = load("player.png");
    m_textures[ENEMY] = load("enemy.png");
    m_textures[COIN] = load("coin.png");
    m_textures[FLOOR] = load("floor.png");
    m_textures[BREAKABLE_FLOOR] = load("breakable_floor.png");
    m_textures[LADDER] = load("ladder.png");
    m_textures[RAIL] = load("rail.png");
    m_textures[ENEMY] = load("empty.png");
}

sf::Texture TextureManager::load(const std::string& filename) {
    sf::Texture temp;
    if (!temp.loadFromFile(filename)) {
        std::cerr << "Error loading :" << filename << std::endl;
    }

    return temp;
}

const sf::Texture* TextureManager::getTexture(const char id) const {
    auto it = m_textures.find(id);
    if (it != m_textures.end()) {
        return &(it->second);
    }
    return nullptr;
}

const sf::Texture* TextureManager::getButtonTexture() const
{
    return &m_buttonTexture;
}

const sf::Texture* TextureManager::getClearButtonTexture() const
{
    return &m_clearButtonTexture;
}

const sf::Texture* TextureManager::getSaveButtonTexture() const
{
    return &m_saveButtonTexture;
}
