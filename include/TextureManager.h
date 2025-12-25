#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    TextureManager();
    const sf::Texture* getTexture(const char id) const;
    const sf::Texture* getButtonTexture() const;
    const sf::Texture* getClearButtonTexture() const;
    const sf::Texture* getSaveButtonTexture() const;

private:
    sf::Texture load(const std::string& filename);

    std::map<char, sf::Texture> m_textures;

	sf::Texture m_buttonTexture;
	sf::Texture m_saveButtonTexture;
	sf::Texture m_clearButtonTexture;
};