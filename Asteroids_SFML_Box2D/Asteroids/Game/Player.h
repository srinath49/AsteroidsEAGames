#pragma once
#include "Engine\GameObject.h"
#include "Game\CharacterObject.h"

class Enemy;

class Player : public CharacterObject
{
	public:
	enum  PlayerState
	{
		IdleState,
		WalkingState,
		RunningState,
		Attack1,
		Attack2,
		PlayerDied,
		PlayerWon,
		PlayerLost,
		CollidedWithTemp,
		WaitingState
	};

	Player() : CharacterObject(){}
	Player(string objectName, Engine* _Main, bool dynamic, bool physicsBody, Vector2 &_Position, string _TextureName, bool _IsSprite, int _Rows, int _Columns) : CharacterObject(objectName, _Main, dynamic, physicsBody, _Position, _TextureName, _IsSprite, _Rows, _Columns) {}

	void OnPointerPressed(Vector2 _Point);
	void OnPointerReleased(Vector2 _Point);
	void OnPointerMoved(Vector2 _Point);
	void SetState(PlayerState);
	PlayerState GetState(){return currentState;}
	void SetStateTextureWithOrientation();

	void EnemyEscaped(){EnemiesEscaped++;}
	void AddScore(int _ScoreToAdd){Score+=_ScoreToAdd;}

	string IntString(int intToConvert);

	GameObject* CurrentTarget;
	int EnemiesEscaped;
	int Score;

private:

	void BeginContact(GameObject* object);
	void EndContact(GameObject* object);
	void Start();
	void Update(unsigned long frameNumber);

	string GetType();

	PlayerState currentState;
	PlayerState previousState;

	//unsigned long tempframe;
	bool isTempframe;
	bool movedLastFrame;

	GameObject* ScoreObject;
	GameObject* EnemiesEscapedObject;
	GameObject* ScoreImage;
	GameObject* EscapedImage;

	int clickcount;
};

