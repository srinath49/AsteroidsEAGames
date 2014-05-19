#pragma once

#include "Engine\gameobject.h"
#include "AsteroidRock.h"

class BigRock :
	public AsteroidRock
{	
public:

	string medRock1Texture;
	string medRock2Texture;

	BigRock() : AsteroidRock(){}
	BigRock(string objectName, Engine* gameEngine, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : AsteroidRock(objectName, gameEngine, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) {}

	void BlastRock();

	string GetType();

private:
	void BeginContact(GameObject* object);
	void EndContact(GameObject* object);
	void Start();
	void Update(unsigned long frameNumber);

};

