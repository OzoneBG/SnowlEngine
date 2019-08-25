#include "TextureManager.h"
#include <iterator>
#include <stdio.h>

TextureManager::TextureManager() {}

bool TextureManager::LoadTexture(std::string key, std::string path)
{
    sf::Texture* texture = new sf::Texture();
    bool success = texture->loadFromFile("Content/" + path);
    if (!success) return false;

    texture->setSmooth(true);

    textures.insert(std::pair<std::string, sf::Texture*>(key, texture));

    return true;
}

sf::Texture* TextureManager::GetTexture(const std::string key)
{
    return textures.find(key)->second;
}

void TextureManager::UnloadTextures()
{
    std::map<std::string, sf::Texture*>::iterator itr;
    for (itr = textures.begin(); itr != textures.end(); ++itr)
    {
        delete itr->second;
        itr->second = nullptr;
    }

    textures.clear();
}