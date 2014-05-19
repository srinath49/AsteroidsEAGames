#pragma once
#include "Engine/Level.h"
#include "Background.h"

class MenuScreenLevel :
	public Level
{
public:
	MenuScreenLevel(void){}
	MenuScreenLevel(Game* _Main, int _LevelNumber) : Level (_Main, _LevelNumber){}

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


private:
	// Layer numbers
	int backgroundLayer;

	Background* screenBackground;
};

