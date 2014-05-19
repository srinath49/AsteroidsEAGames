#pragma once
#include "Engine\gameobject.h"


class AsteroidRock :
	public GameObject
{	
public:

	enum AsteroidState
	{
		NormalState,
		BlastState
	};

	AsteroidRock() : GameObject(){}

	AsteroidRock(string objectName, Engine* _Main, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : GameObject(objectName, _Main, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) {}

	virtual void BlastRock(){}
	int GetScoreValue(){return scoreValue;}
	string GetType(){return "Asteroid";}

	void SetState(AsteroidState newState);

	AsteroidState GetState(){return currentState;}
	float RandFloatInRange(float a, float b){return ((b-a)*((float)rand()/RAND_MAX))+a;}

private:
	int scoreValue;

	virtual void BeginContact(GameObject* object){}
	virtual void EndContact(GameObject* object){}
	virtual void Start(){}
	virtual void Update(unsigned long frameNumber){}

	AsteroidState currentState;
	AsteroidState previousState;
};

