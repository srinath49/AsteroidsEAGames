#pragma once
#include "Engine\gameobject.h"


class MediumRock :
	public GameObject
{	
public:

	string smallRock1Texture;
	string smallRock2Texture;
	string smallRock3Texture;

	/**
	 * The default Constructor. It always forwards the call to its super class GameObject 's Default Constructor
	 * Note: Make Sure that it always forwards the call to the GameObject's constructor using the  : GameObject(){} syntax
	 */
	MediumRock() : GameObject(){}

	/**
	 * The Complete Object Constructor. This object is created with an initial texture, physics body if stated, etc. This is your typical GameObject constructor that creates your regular object.
	 * It always forwards the call its equivalent super class constructor using the  : GameObject(...){} syntax
	 * Note: Make Sure that it always forwards the call to the GameObject's constructor using the  : GameObject(...){} syntax
	 */
	MediumRock(string objectName, Engine* _Main, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : GameObject(objectName, _Main, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) {}


private:
	void BeginContact(GameObject* object);
	void EndContact(GameObject* object);
	void Start();
	void Update(unsigned long frameNumber);

	string GetType();

};

