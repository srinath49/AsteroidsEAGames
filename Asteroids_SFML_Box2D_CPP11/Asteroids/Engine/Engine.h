#pragma once

#include <string>
#include "Box2D.h"
#include <SFML/Graphics.hpp>
#include "BasicMath.h"
#include "MyQueryCallback.h"

class b2World;

class GameObject;
class Layer;
class TextureManager;

using namespace std;

/**
 * The Engine class is the mid-level game loop that handles the creation of all the game elements like the layers, gameobjects, etc.
 * The users however will NOT be using the Engine class directly. Instead, they will be using the Subclass of the Engine class -> the Game class.
 * In the Game, the users can add their game specific member variables and member functions. The Engine class however is the background class that handles the creation 
 * and deletion of all the game elements based on the requirements, amongst other things like the integration of the Box2D physics engine, etc.
 */
class Engine
{

private:

	b2AABB tempBody;
	unsigned long frameNumber;		/** The current frame */

	MyQueryCallback queryCallback;

protected:
	sf::RenderWindow* renderer;
	
	b2Body*			 phyxBody;
	b2Fixture*		 phyxFix;

	int layerCount;	/** Total number of layers */
	Layer* layers[20];/** Layers Array */

	bool frameChanged;
	unsigned long int prevFrame;
	unsigned long int currentFrame;

public:

	/**********************************VIRTUAL FUNCTIONS*************************************/
	/****************************************************************************************/
	/* The Following are virtual function to be implemented by the sub-class -> "Game"
	/****************************************************************************************/

	/**
	 * It is called by the Engine on the Game object, when it is created
	 */
	virtual void Start(){};

	/**
	 * This it the game loop class. It is called once every frame by the Engine.
	 */
	virtual void Update(unsigned long frameNumber){}

	/**
	 * This is called by the Controller class when it receives a PointerPress event.
	 * A pointer press event is fired when either a Tap or click occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	virtual void OnPointerPressed(Vector2 point){}

	/**
	 * This is called by the Controller class when it receives a PointerMoved event.
	 * A pointer moved event is fired when either a 'Tap and drag' or 'Click and Drag' takes place.
	 *
	 * @param		_Point			The current pointer position while in the pointer moved event
	 */
	virtual void OnPointerMoved(Vector2 point){}

	/**
	 * This is called by the Controller class when it receives a PointerReleased event.
	 * A pointer released event is fired when either an UnTap or click-released occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	virtual void OnPointerReleased(Vector2 point){}

	/**
	 * This is called by the Controller class when it receives a PointerPress event.
	 * A pointer press event is fired when either a Tap or click occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	virtual void OnKeyPressed(sf::Keyboard::Key key){}

	/**
	 * This is called by the Controller class when it receives a PointerReleased event.
	 * A pointer released event is fired when either an UnTap or click-released occurs in the game.
	 *
	 * @param		_Point			The point in the game world where the event took place
	 */
	virtual void OnKeyReleased(sf::Keyboard::Key key){}

	/*******************************END OF VIRTUAL FUNCTIONS**********************************/
	

	/*****************************Box2D Physics World Declarations********************************/
	//b2World* phyxWorld;
	//b2Fixture* fix;
	//b2Vec2 gravity;
	//b2World* myWorld;
	/***************************End of Box2D Physics World Declarations****************************/

	/**
	 * Holds and manages all the textures in the game. Adding, deleting texturues and freeing memory is handled by the texture manager class.
	 */
	TextureManager * textureManager;

	/**
	 * Initializes the Engine class. Sets references to the SFML RenderWindow, TextureManager, Physics world etc.
	 */
	void Initialize();	

	/**
	 * Renders all the existing GameObjects to the screen
	 */
	void Render();

	//Default Constructor
	Engine();

	/**
	 * Returns a reference to the render window
	 * 
	 * @return	renderer	The SFML RenderWindow object reference
	 */
	sf::RenderWindow* GetRenderer(){return renderer;}

	/**
	 * Adds a New Layer to the game and gives the current count of the layers
	 *
	 * @return		The total number of Layers in the game
	 */
	int AddLayer();

	/**
	 * Deletes a Layer from the game
	 *
	 * @param			layerId			The ID of the layer to delete from the world
	 */
	void DeleteLayer(int layerId);

	/**
	 * Gets the layer with the specified ID
	 *
	 * @return		The Layer with ID =  layerId
	 */
	Layer * GetLayer(int layerId);

	/**
	 * Gets the total layers in the game
	 *
	 * @return		The Layers Count 
	 */
	int GetLayersCount();

	/**
	 * Gets the dynamic gameobject at the specified point
	 *
	 * @param		point		The point to check for dynamic body
	 * @return		A GameObject at the given point if it is a dynamic body. If no dynamic GameObject is found at point, then it returns nullptr
	 */
	GameObject* GetDynamicObjectAtPoint(Vector2 point);

	/**
	 * Gets the gameobject at the specified point
	 *
	 * @param		point		The point to check for game object
	 * @return		A GameObject at the given point if it is a dynamic physics body. If no dynamic GameObject is found at point, then it returns nullptr
	 */
	GameObject* GetObjectAtPoint(Vector2 point);

	/**
	 * Gets the static gameobject at the specified point
	 *
	 * @param		point		The point to check for static body
	 * @return		A GameObject at the given point if it is a non-dynamic/static physics body. If no static GameObject is found at point, then it returns nullptr
	 */
	GameObject* GetStaticObjectAtPoint(Vector2 point);


	/**
	 * Converts a Directional Vector into an Angle
	 *
	 * @return		Angle of the specified Directional Vector
	 */
	float ConvertDirectionVectorToAngle(Vector2* _Direction);

	/**
	 * Converts an Angle to a Directional vector
	 *
	 * @return		Directional Vector of the specified Angle
	 */
	Vector2 ConvertDirectionAngleToVector(float _Angle);

	/**
	 * Finds the distance between 2 Vector2 points
	 *
	 * @param	point1		The first point
	 * @param	point2		The second point
	 */
	float GetDistance(Vector2 point1, Vector2 point2);
};

