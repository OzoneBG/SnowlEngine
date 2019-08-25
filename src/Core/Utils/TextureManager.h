#pragma once

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
    TextureManager();

public:
    bool LoadTexture(std::string key, std::string path);
    
    sf::Texture* GetTexture(const std::string key);

    void UnloadTextures();

private:
    std::map<std::string, sf::Texture*> textures;
};