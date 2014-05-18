
#include "Level1.h"

void Level1::CreateLayers()
{
	BackgroundLayer = gameLoop->AddLayer();
}

void Level1::CreateGameObjects()
{
	Bgrd = new CharacterObject("Character", gameLoop, true, true , Vector2(0 , 0) , "BatmanAttackDown.png" , true , 4 , 4);
	Bgrd2 = new CharacterObject("Character2", gameLoop, true, true , Vector2(10 , 0) , "BatmanAttackDown.png" , true , 4 , 4);
}

void Level1::AddObjectsToLayers()
{
	
	//Adding Background
	gameLoop->GetLayer(BackgroundLayer)->AddObjectToLayer(Bgrd);
	gameLoop->GetLayer(BackgroundLayer)->AddObjectToLayer(Bgrd2);
	levelDone = false;
	
}

void Level1::LevelWon()
{
	levelDone = true;
	gameLoop->RequestLevelLoad(2);
}

void Level1::LevelLost()
{
	levelDone = true;
	gameLoop->RequestNextLevelLoad();
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

}

void Level1::OnPointerMoved(Vector2 point)
{

}

void Level1::OnPointerReleased(Vector2 point)
{

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
			break;
		case sf::Keyboard::Left:
			Bgrd->AddForce(-2.0f, 0.0f, Coordinate::Global);
			break;
		case sf::Keyboard::Up:
			Bgrd->AddForce(0.0f, 2.0f, Coordinate::Global);
			break;
		case sf::Keyboard::Down:
			Bgrd->AddForce(0.0f, -2.0f, Coordinate::Global);
			break;
	}
}

void Level1::OnKeyReleased(sf::Keyboard::Key key)
{

}