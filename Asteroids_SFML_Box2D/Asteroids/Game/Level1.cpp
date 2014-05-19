
#include "Level1.h"

BigRock* bigRock2;
BigRock* bigRock3;

void Level1::CreateLayers()
{
	backgroundLayer = gameEngine->AddLayer();
	rocksLayer = gameEngine->AddLayer();
	enemyLayer = gameEngine->AddLayer();
	playerLayer = gameEngine->AddLayer();
}

void Level1::CreateGameObjects()
{
	player = new Player("Character", gameEngine, true, true, Vector2(-5.0f , 0.0f), "spaceShip.png", true, 2, 2);
	player->SetTag("PlayerShip");

	bigRock1 = new BigRock("Character2", gameEngine, true, true, Vector2(5.0f , 0.0f), "battle_ship.png", true, 2, 10);
	//bigRock1->SetGravity(0.0f);
	//bigRock1->SetVelocity(0.0f,0.0f);
	bigRock1->SetTag("Rock");
	
	bigRock2 = new BigRock("Character3", gameEngine, true, true, Vector2(3.0f , 3.0f), "battle_ship.png", true, 2, 10);
	bigRock2->SetTag("Rock");

	bigRock3 = new BigRock("Character4", gameEngine, true, true, Vector2(5.0f , -5.0f), "battle_ship.png", true, 2, 10);
	bigRock3->SetTag("Rock");
}

void Level1::AddObjectsToLayers()
{
	
	//Adding Objects to Layers
	gameEngine->GetLayer(playerLayer)->AddObjectToLayer(player);
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(bigRock1);
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(bigRock2);
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(bigRock3);
	levelDone = false;
	
}

void Level1::LevelWon()
{
	levelDone = true;
	gameEngine->RequestLevelLoad(2);
}

void Level1::LevelLost()
{
	levelDone = true;
	gameEngine->RequestNextLevelLoad();
}

void Level1::Update(unsigned long frameNumber)
{	
	if(levelDone)
	{
		return;
	}
}


void Level1::OnPointerPressed(Vector2 point)
{
	GameObject* obj = gameEngine->GetDynamicObjectAtPoint(point);
	if(obj != nullptr)
	{
		obj->OnPointerPressed(point);
	}
}

void Level1::OnPointerMoved(Vector2 point)
{
	GameObject* obj = gameEngine->GetDynamicObjectAtPoint(point);
	if(obj != nullptr)
	{
		obj->OnPointerMoved(point);
	}
}

void Level1::OnPointerReleased(Vector2 point)
{
	GameObject* obj = gameEngine->GetDynamicObjectAtPoint(point);
	if(obj != nullptr)
	{
		obj->OnPointerReleased(point);
	}
}

void Level1::OnKeyPressed(sf::Keyboard::Key key)
{
	if(player == nullptr)
	{
		return;
	}
	player->OnKeyPressed(key);
}

void Level1::OnKeyReleased(sf::Keyboard::Key key)
{
	if(player == nullptr)
	{
		return;
	}
	player->OnKeyReleased(key);
}