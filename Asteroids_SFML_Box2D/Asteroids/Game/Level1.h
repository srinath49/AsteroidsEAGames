#pragma once

#include "Engine/Level.h"
#include "Engine/GameObject.h"
#include "CharacterObject.h"

class Level1 : public Level
{
public:
	Level1(void) : Level(){levelDone = false;}
	Level1(Game* gameLoop, int levelNumber) : Level (gameLoop, levelNumber){levelDone = false;}

	void CreateLayers();
	void CreateGameObjects();
	void AddObjectsToLayers();
	void LevelWon();
	void LevelLost();
	void Update(unsigned long frameNumber);

	bool levelDone;

private:
	// Layer numbers
	int BackgroundLayer;

	CharacterObject* Bgrd;
};
