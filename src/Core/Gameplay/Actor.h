#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "../Utils/TextureManager.h"

class Actor
{
public:
    Actor(std::string textureKey, TextureManager* textureManager);

public:
    virtual void BeginPlay();

    virtual void Tick(float DeltaTime);

    virtual void Destroy();

    virtual void HandleEvents(sf::Event event);

    sf::Sprite* GetSprite();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

private:
    std::string textureKey;

    TextureManager* textureManager = nullptr;
};