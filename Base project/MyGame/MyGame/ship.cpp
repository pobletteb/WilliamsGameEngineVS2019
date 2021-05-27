#include "Ship.h"
#include "Laser.h"

float xvelocity = 0;
float yvelocity = 0;
const float terminalvelocity = 10;
const float acceleration = 0.2;
const float drag = 0.05;
int window_length = 0;
int window_height = 0;
sf::FloatRect bounds;
const int FIRE_DELAY = 200;


Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	window_length = GAME.getRenderWindow().getSize().x;
	window_height = GAME.getRenderWindow().getSize().y;
	bounds = sprite_.getGlobalBounds();
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}


void Ship::update(sf::Time& elapsed)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) yvelocity -= acceleration ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) yvelocity +=  acceleration ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) xvelocity -=  acceleration ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) xvelocity +=  acceleration ;

	if (xvelocity < -terminalvelocity)
	{
		xvelocity = -terminalvelocity;
	}
	if (xvelocity > terminalvelocity)
	{
		xvelocity = terminalvelocity;
	}
	if (yvelocity < -terminalvelocity)
	{
		yvelocity = -terminalvelocity;
	}
	if (yvelocity > terminalvelocity)
	{
		yvelocity = terminalvelocity;
	}
	
	x += xvelocity ;
	y += yvelocity ;
	if (xvelocity < -drag) 
	{
		xvelocity += drag;
	}
	else if (xvelocity > drag)
	{
		xvelocity -= drag;
	}
	else
	{
		xvelocity = 0;
	}
	if (yvelocity < -drag)
	{
		yvelocity += drag;
	}
	else if (yvelocity > drag)
	{
		yvelocity -= drag;
	}
	else 
	{
		yvelocity = 0;
	}

	if(x > window_length)
	{
		x = -bounds.width;
	}
	else if(x < -bounds.width)
	{
		x = window_length;
	}
	if (y > window_height)
	{
		y = -bounds.height;
	}
	else if (y < -bounds.height)
	{
		y = window_height;
	}

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;
		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}
}

