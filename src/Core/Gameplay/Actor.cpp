#include "Actor.h"

Actor::Actor(std::string textureKey, TextureManager* textureManager)
{
    this->textureKey = textureKey;
    this->textureManager = textureManager;
}

void Actor::BeginPlay()
{
    sf::Texture* texture = textureManager->GetTexture(textureKey);

    sprite = new sf::Sprite(*texture);
}

void Actor::Tick(float DeltaTime)
{

}

void Actor::Destroy()
{
    delete sprite;
    sprite = nullptr;
}

sf::Sprite* Actor::GetSprite()
{
    return sprite;
}

void Actor::HandleEvents(sf::Event event)
{

}