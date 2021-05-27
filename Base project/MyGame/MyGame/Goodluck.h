#pragma once

#include "Engine/GameEngine.h"

class Goodluck : public GameObject
{
	public:
		//Creates the goodluck instance.
		Goodluck(sf::Vector2f pos);

		//Functions overriden from GameObject:
		void draw();
		void update(sf::Time& elapsed);
private:
	sf::Text text_;
};

typedef std::shared_ptr<Goodluck> GoodluckPtr;
