#pragma once

#include "Game/Game.h"
#include "GameObject.h"
#include <string>


using namespace std;

class Game;

enum LevelState
{
	LevelLoading,
	LevelLoaded,
	LevelInstruction,
	LevelRunning,
	LevelDone,
	LevelWin,
	LevelLose,
};

class Level
{
public:

	Level(){}
	Level(Game* gameLoop, int levelNumber);

	virtual void CreateLayers(){}
	virtual void CreateGameObjects(){}
	virtual void AddObjectsToLayers(){}
	virtual void DeleteAllGameObjects();
	virtual void LevelWon(){}
	virtual void LevelLost(){}
	virtual void Update(unsigned long frameNumber){}
	
	virtual void SetLevelState(LevelState newState);
	virtual LevelState GetLevelState();

	virtual void AddObjectToLayer(GameObject* gObj, int layer);
	virtual void Initialize();
	virtual void ReleaseAllResources();
	virtual void SetLevelTimer();

	int levelNumber;
	Game* gameLoop;

	sf::Time timer;
	sf::Clock clock;

	LevelState currentState;
	LevelState previousState;

	bool layersAdded;
};
