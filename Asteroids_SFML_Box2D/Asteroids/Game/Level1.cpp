
#include "Level1.h"

void Level1::CreateLayers()
{
	BackgroundLayer = gameEngine->AddLayer();
}

void Level1::CreateGameObjects()
{
	Bgrd = new CharacterObject("Character", gameEngine, true, true, Vector2(-5.0f , 0.0f), "spaceShip.png", true, 2, 2);
	//Bgrd2 = new CharacterObject("Character2", gameEngine, true, true, Vector2(5.0f , 0.0f), "spaceShip.png", true, 2, 10);
	//Bgrd2 = new CharacterObject("Character2", gameEngine, true, true, Vector2(2.0f , -2.0f), "BatmanAttackDown.png", true, 2, 10);
}

void Level1::AddObjectsToLayers()
{
	
	//Adding Background
	gameEngine->GetLayer(BackgroundLayer)->AddObjectToLayer(Bgrd);
	//gameEngine->GetLayer(BackgroundLayer)->AddObjectToLayer(Bgrd2);
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
	if(!Bgrd)
	{
		return;
	}
	switch(key)
	{
		case sf::Keyboard::Right:
			Bgrd->AddForce(2.0f, 0.0f, Coordinate::Global);
			printf("Right Pressed\n");
			break;
		case sf::Keyboard::Left:
			Bgrd->AddForce(-2.0f, 0.0f, Coordinate::Global);
			printf("Left Pressed\n");
			break;
		case sf::Keyboard::Up:
			Bgrd->AddForce(0.0f, 2.0f, Coordinate::Global);
			printf("Up Pressed\n");
			break;
		case sf::Keyboard::Down:
			Bgrd->AddForce(0.0f, -2.0f, Coordinate::Global);
			printf("Down Pressed\n");
			break;
	}
}

void Level1::OnKeyReleased(sf::Keyboard::Key key)
{

}