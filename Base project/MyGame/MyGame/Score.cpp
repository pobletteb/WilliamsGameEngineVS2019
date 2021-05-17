#include "Score.h"
#include "GameScene.h"
#include <sstream>
//#pragma warning(disable : 4996)

Score::Score(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	text_.setFillColor(sf::Color::White);
	assignTag("score");
}

void Score::draw()
{
	GAME.getRenderWindow().draw(text_);
}

void Score::update(sf::Time& elapsed)
{
	GameScene& scene = (GameScene&)GAME.getCurrentScene();

	std::stringstream stream;
	stream << "Score: " << scene.getScore();

	text_.setString(stream.str());
}