#include "Goodluck.h"
#include "GameScene.h"
#include <sstream>
//#pragma warning(disable : 4996)

int timer = 10000;

Goodluck::Goodluck(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::Red);
	assignTag("Goodluck");
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "Goodluck!";

	text_.setString(stream.str());
}


void Goodluck::draw()
{
	GAME.getRenderWindow().draw(text_);
}

void Goodluck::update(sf::Time& elapsed)
{
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "Goodluck: " << scene.getScore();

	text_.setString(stream.str());
}