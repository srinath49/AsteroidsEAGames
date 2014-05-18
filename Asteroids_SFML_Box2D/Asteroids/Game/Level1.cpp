
#include "Level1.h"

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

	rock = new GameObject("Character2", gameEngine, true, true, Vector2(5.0f , 0.0f), "battle_ship.png", true, 2, 10);
	rock->SetGravity(0.0f);
	rock->SetVelocity(0.0f,0.0f);
	rock->SetTag("Rock");
}

void Level1::AddObjectsToLayers()
{
	
	//Adding Objects to Layers
	gameEngine->GetLayer(playerLayer)->AddObjectToLayer(player);
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(rock);
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(new GameObject("Character3", gameEngine, true, true, Vector2(3.0f , 3.0f), "battle_ship.png", true, 2, 10));
	gameEngine->GetLayer(rocksLayer)->AddObjectToLayer(new GameObject("Character4", gameEngine, true, true, Vector2(5.0f , -5.0f), "battle_ship.png", true, 2, 10));
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
	Vector2 tempPos;
	switch(key)
	{
		case sf::Keyboard::Right:
			player->AddForce(1.0f, 0.0f, Coordinate::Global);
			//printf("Right Pressed\n");
			break;
		case sf::Keyboard::Left:
			player->AddForce(-1.0f, 0.0f, Coordinate::Global);
			//printf("Left Pressed\n");
			break;
		case sf::Keyboard::Up:
			player->AddForce(0.0f, 1.0f, Coordinate::Global);
			//printf("Up Pressed\n");
			break;
		case sf::Keyboard::Down:
			player->AddForce(0.0f, -1.0f, Coordinate::Global);
			//printf("Down Pressed\n");
			break;
		case sf::Keyboard::A:
			player->Rotate(0.05f);
			//printf("Down Pressed\n");
			break;
		case sf::Keyboard::S:
			player->Rotate(-0.05f);
			//printf("Down Pressed\n");
			break;
	}
}

void Level1::OnKeyReleased(sf::Keyboard::Key key)
{

}