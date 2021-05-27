#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "score.h"
#include "Goodluck.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared < MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

	GoodluckPtr goodluck = std::make_shared<Goodluck>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(goodluck);

}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	++score_;
}

