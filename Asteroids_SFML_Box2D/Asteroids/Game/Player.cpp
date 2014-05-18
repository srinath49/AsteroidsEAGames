
#include "Player.h"
//#include "Enemy.h"
//#include "Truck.h"

void Player::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Rock"))
	{
		SetState(DyingState);
	}
	
}

void Player::EndContact(GameObject*)
{
}

void Player::Start()
{
	
	SetGravity(0.0f);
	SetVelocity(0.0f,0.0f);
	/*
	SetCollisionScale(0.5f , 0.5f);
	isTempframe = false;
	movedLastFrame = false;
	Score = 0;
	EnemiesEscaped = 0;
	IsPlayer = true;
	clickcount = 0;
	FixRotation(true);
	IsTrigger(true);

	
	// UI Start
	int UILayer			=	engineRef->AddLayer();
	int UITextLayer		=	engineRef->AddLayer();

	ScoreImage = new GameObject("ScoreImage", engineRef, false, false, Vector2(-8.5f, 5.5f), "Textures/Scoreboard.png", false, 1,1); 
	engineRef->GetLayer(UILayer)->AddObjectToLayer(ScoreImage);
	EscapedImage = new GameObject("EscapedImage", engineRef, false, false, Vector2(8.5f, 5.5f), "Textures/EnemiesEscaped.png", false, 1,1);
	engineRef->GetLayer(UILayer)->AddObjectToLayer(EscapedImage);

	ScoreObject = new GameObject("Score", "Tahoma", 18.0f, "0", engineRef, ScoreImage->position); 
	ScoreObject->SetAlignmentTextBlock(1);
	engineRef->GetLayer(UITextLayer)->AddObjectToLayer(ScoreObject);
	EnemiesEscapedObject = new GameObject("Escaped", "Tahoma", 18.0f, "0", engineRef, EscapedImage->position);
	EnemiesEscapedObject->SetAlignmentTextBlock(1);
	engineRef->GetLayer(UITextLayer)->AddObjectToLayer(EnemiesEscapedObject);
	// UI End

	// Add Textures
	AddTexture("Textures/BatmanAttack.png" , true , 4 , 4);
	AddTexture("Textures/BatmanAttackRight.png" , true , 4 , 4);
	AddTexture("Textures/BatmanAttackUp.png" , true , 4 , 4);
	AddTexture("Textures/BatmanAttackDown.png" , true , 4 , 4);

	AddTexture("Textures/BatmanIdle.png" , true , 4 , 4);
	AddTexture("Textures/BatmanIdleRight.png" , true , 4 , 4);
	AddTexture("Textures/BatmanIdleUp.png" , true , 4 , 4);
	AddTexture("Textures/BatmanIdleDown.png" , true , 4 , 4);
	
	AddTexture("Textures/BatmanWalk.png" , true , 4 , 4);
	AddTexture("Textures/BatmanWalkRight.png" , true , 4 , 4);
	AddTexture("Textures/BatmanWalkUp.png" , true , 4 , 4);
	AddTexture("Textures/BatmanWalkDown.png" , true , 4 , 4);


	// Add Sounds
	//AddSound(L"IamBatman.wav", 0);
	//SetVolume(L"IamBatman.wav", 2.0f);
	//AddSound(L"BatmanDefinition.wav", 0);
	//SetVolume(L"BatmanDefinition.wav", 2.0f);
*/
}

void Player::Update(unsigned long frameNumber)
{
	
	switch(currentState)
	{
		case DyingState:
			Destroy();
			break;
	}
	
}

string Player::GetType()
{
	return "Player";
}

void Player::OnPointerPressed(Vector2 _Point)
{
	/*
	if(++clickcount%2 == 0)
	{
		PlaySound("IamBatman.wav");
	}
	else
	{
		PlaySound("BatmanDefinition.wav");
	}
	*/
}

void Player::OnPointerMoved(Vector2 _Point)
{
}

void Player::OnPointerReleased(Vector2 _Point)
{
}

void Player::SetState(PlayerState _NewState)
{
	previousState = currentState;
	currentState = _NewState;
}


void Player::SetStateTextureWithOrientation()
{
	
}

string Player::IntString(int intToConvert)
{
	//string ret; 
	//_itow_s(intToConvert, ret, 10);
	return "";
}
