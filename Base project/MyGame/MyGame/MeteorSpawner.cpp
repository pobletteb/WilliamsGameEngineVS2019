#include "MeteorSpawner.h"

//the number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 1000;

void MeteorSpawner::update(sf::Time& elapsed)
{
	//determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	//if our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//Spawn the meteor off the right side of the screen.
		//were assuming the meteor isnt more than 100 pixels wide.
		float meteorX = (float)(size.x + 100);

		//spawn the meteor somewhere along the height of window, randomly
		float meteorY = (float)(rand() % size.y);

		//create a meteor and add it to the scene
		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(meteor);
	}
}