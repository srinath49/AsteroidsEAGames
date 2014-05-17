
#include "Level.h"

Level::Level(Game* gameLoop, int levelNumber)
{
	layersAdded = false;
	levelNumber = levelNumber;
	gameLoop = gameLoop;
	SetLevelState(LevelLoading);
}

void Level::Initialize()
{
	CreateLayers();
	CreateGameObjects();
	AddObjectsToLayers();
}

void Level::ReleaseAllResources()
{
	//m_Timer = nullptr;
	DeleteAllGameObjects();
}

void Level::AddObjectToLayer(GameObject* gObj, int layer)
{
	gameLoop->GetLayer(layer)->AddObjectToLayer(gObj);
}

void Level::SetLevelTimer()
{
	//m_Timer = ((App^)Application::Current->Current)->GetAppTimer();
}

void Level::SetLevelState(LevelState newState)
{
	previousState = currentState;
	currentState = newState;
}

LevelState Level::GetLevelState()
{
	return currentState;
}

void Level::DeleteAllGameObjects()
{
	/*
	for(int i = 0; i < gameLoop->GetLayerCount(); i++)
	{
		if(gameLoop->LayerExists(i))
		{
			gameLoop->DeleteLayer(i);
		}
	}
	*/
}