#pragma once

#include "Engine/Level.h"
#include "Engine/GameObject.h"
#include "Player.h"
#include "BigRock.h"

class Level1 : public Level
{
public:
	Level1(void) : Level(){levelDone = false;}
	Level1(Game* gameEngine, int levelNumber) : Level (gameEngine, levelNumber){levelDone = false;}

	void CreateLayers();
	void CreateGameObjects();
	void AddObjectsToLayers();
	void LevelWon();
	void LevelLost();
	void Update(unsigned long frameNumber);

	/**
	 * This is called by the Controller class when it receives a PointerPress event.
	 * A pointer press event is fired when either a Tap or click occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	void OnPointerPressed(Vector2 point);

	/**
	 * This is called by the Controller class when it receives a PointerMoved event.
	 * A pointer moved event is fired when either a 'Tap and drag' or 'Click and Drag' takes place.
	 *
	 * @param		_Point			The current pointer position while in the pointer moved event
	 */
	void OnPointerMoved(Vector2 point);

	/**
	 * This is called by the Controller class when it receives a PointerReleased event.
	 * A pointer released event is fired when either an UnTap or click-released occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	void OnPointerReleased(Vector2 point);

	/**
	 * This is called by the Controller class when it receives a PointerPress event.
	 * A pointer press event is fired when either a Tap or click occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	void OnKeyPressed(sf::Keyboard::Key key);

	/**
	 * This is called by the Controller class when it receives a PointerReleased event.
	 * A pointer released event is fired when either an UnTap or click-released occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	void OnKeyReleased(sf::Keyboard::Key key);

	bool levelDone;

private:
	// Layer numbers
	int backgroundLayer;
	int rocksLayer;
	int enemyLayer;
	int playerLayer;

	Player* player;

	BigRock* bigRock1;
	/*
	GameObject* bigRock2;
	GameObject* bigRock3;
	
	GameObject* mediumRock1;
	GameObject* mediumRock2;
	GameObject* mediumRock3;
	GameObject* mediumRock4;
	GameObject* mediumRock5;
	GameObject* mediumRock6;

	GameObject* smallRock1;
	GameObject* smallRock2;
	GameObject* smallRock3;
	GameObject* smallRock4;
	GameObject* smallRock5;
	GameObject* smallRock6;
	GameObject* smallRock7;
	GameObject* smallRock8;
	GameObject* smallRock9;
	GameObject* smallRock10;
	GameObject* smallRock11;
	GameObject* smallRock12;
	GameObject* smallRock13;
	GameObject* smallRock14;
	GameObject* smallRock15;
	GameObject* smallRock16;
	GameObject* smallRock17;
	GameObject* smallRock18;
	*/
};
