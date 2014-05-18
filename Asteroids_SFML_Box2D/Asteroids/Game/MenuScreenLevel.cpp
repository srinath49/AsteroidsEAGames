#include "MenuScreenLevel.h"

void MenuScreenLevel::CreateLayers()
{
	backgroundLayer	= gameEngine->AddLayer();
}

void MenuScreenLevel::CreateGameObjects()
{
	//BackgroundLayer GameObjects
	screenBackground = new Background("ScreenBackground" , gameEngine , false , false , Vector2(0 , 0) , "BatmanAttackDown.png" , false , 1 , 1);
}

void MenuScreenLevel::AddObjectsToLayers()
{
	//BackgroundLayer GameObjects
	gameEngine->GetLayer(backgroundLayer)->AddObjectToLayer(screenBackground);
}

void MenuScreenLevel::LevelWon()
{
	//gameEngine->RequestNextLevelLoad();
}

void MenuScreenLevel::LevelLost()
{
	//gameEngine->RequestLevelReload();
}

void MenuScreenLevel::Update(unsigned long frameNumber)
{
	
}

void MenuScreenLevel::OnPointerPressed(Vector2 point)
{

}

void MenuScreenLevel::OnPointerMoved(Vector2 point)
{

}

void MenuScreenLevel::OnPointerReleased(Vector2 point)
{

}

void MenuScreenLevel::OnKeyPressed(sf::Keyboard::Key key)
{
	switch(key)
	{
		case sf::Keyboard::Return:
			gameEngine->RequestNextLevelLoad();
			//player->AddForce(1.0f, 0.0f, Coordinate::Global);
			//printf("Right Pressed\n");
			break;
		case sf::Keyboard::Escape:
			//gameEngine->renderer->close();
			break;
	}
}

void MenuScreenLevel::OnKeyReleased(sf::Keyboard::Key key)
{
	screenBackground->Destroy();
}
