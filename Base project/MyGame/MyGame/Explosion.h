#pragma once

#include "Engine/GameEngine.h"

class Explosion : public AnimatedSprite
{
public:
	//Creates our explostion
	Explosion(sf::Vector2f pos);

	//Functions overidden from GameObject:
	void update(sf::Time& elapsed);

private:
	void SetUpExplosionAnimation();
};
typedef std::shared_ptr<Explosion> Explosionptr;