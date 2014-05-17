
#include "Player.h"
//#include "Enemy.h"
//#include "Truck.h"

void Player::BeginContact(GameObject* _Object)
{
	/*
	if(_Object->CompareTag("WayPoint"))
	{
		if(_Object->position.x == CurrentDestination.x && _Object->position.y == CurrentDestination.y)
		{
			if(hasAnotherLocation)
			{
				CurrentDestination = NextLocation;
				hasAnotherLocation = false;
			}
			SetState(IdleState);
		}
	}
	else if(_Object == moveIndicator)
	{
		SetVelocity(0.0f,0.0f);
		if(GetState() == WalkingState)
		{
			if(left || right)
			{
				if(position.y == moveIndicator->position.y && position.x != moveIndicator->position.x)
				{
					CurrentDestination = Vector2(position.x, CurrentDestination.y);
				}

				SetState(CollidedWithTemp);
			}
			else if(up || down)
			{
				if(position.x == moveIndicator->position.x && position.y != moveIndicator->position.y)
				{
					CurrentDestination = Vector2(CurrentDestination.x, position.y);

					SetState(IdleState);
				}
			}
			else
			{
			
				SetState(IdleState);	
			}
		}
	}
	else if(_Object->GetType().compare(L"Truck") == 0 && ((Truck*)_Object)->GetState() == Truck::TruckState::AttackedState)
	{
		SetVelocity(0.0f,0.0f);
		SetState(Attack1);
		CurrentTarget = _Object;
		((Truck*)CurrentTarget)->SetState(Truck::TruckState::AttackedState);
	}	
	else if(_Object->GetType().compare(L"Enemy") == 0 && ((Enemy*)_Object)->GetState() == Enemy::EnemyState::FreezeState)
	{
		SetVelocity(0.0f,0.0f);
		CurrentTarget = _Object;
		SetState(Attack1);
		((Enemy*)CurrentTarget)->SetState(Enemy::EnemyState::HitState);
		((Enemy*)CurrentTarget)->player = this;
	}
	*/
}

void Player::EndContact(GameObject*)
{
}

void Player::Start()
{
	/*
	SetGravity(0.0f);
	SetVelocity(0.0f,0.0f);
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
	/*
	ScoreObject->SetText(IntString(Score));
	EnemiesEscapedObject->SetText(IntString(EnemiesEscaped));
	SetStateTextureWithOrientation();
	switch(currentState)
	{
		case IdleState:
			if(!m_CurrentTexture->IsPlaying())
			{
				PlaySpriteTexture();
			}
			SetVelocity(0.0f, 0.0f);
			break;

		case WalkingState:
			SetOrientation(CurrentDestination);
			if(movedLastFrame)
			{
				movedLastFrame = false;
			}
			else
			{
				MoveToPoint(CurrentDestination, 1.8f);
				movedLastFrame = true;
			}
			break;

		case CollidedWithTemp:
			SetVelocity(0.0f, 0.0f);
			//moveIndicator->SetPosition(position);
			movedLastFrame = true;
			if(isTempframe)
			{
				SetState(WalkingState);
				isTempframe = false;
			}
			else
			{
				isTempframe = true;
				//tempframe = frameNumber;
			}
			break;
		case Attack1:
			if(!m_CurrentTexture->IsPlaying())
			{
				PlaySpriteTexture();
			}
			if(m_CurrentTexture->CurrentFrame == 15)
			{
				PauseSpriteTexture();
				if(CurrentTarget && CurrentTarget->GetType().compare(L"Enemy") == 0)
				{
					SetState(WaitingState);
				}
				else if(CurrentTarget && CurrentTarget->GetType().compare(L"Truck") == 0)
				{
					SetState(Attack2);
				}
				else
				{
					SetState(IdleState);
				}
			}
			break;

		case Attack2:
			if(!m_CurrentTexture->IsPlaying())
			{
				PlaySpriteTexture();
				break;
			}
			if(m_CurrentTexture->CurrentFrame == 15)
			{
				PauseSpriteTexture();
				SetState(IdleState);
				if(CurrentTarget && CurrentTarget->GetType().compare(L"Truck") == 0)
				{
					((Truck*)CurrentTarget)->SetState(Truck::TruckState::UnloadState);
					Score += 150;
				}
			}
			break;
			
		case WaitingState:
			break;

		default:
			break;

	}
	*/
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
	/*
	switch(currentState)
	{
		case WalkingState :
			
			if(left)
			{
				
				if(GetTextureName().compare("Textures/BatmanWalk.png") != 0)
				{
					SetTexture("Textures/BatmanWalk.png");
				}
				
			}

			else if(right)
			{
				if(GetTextureName().compare("Textures/BatmanWalkRight.png") != 0)
				{
					SetTexture("Textures/BatmanWalkRight.png");
				}
			}
			
			else if(up)
			{
				if(GetTextureName().compare("Textures/BatmanWalkUp.png") != 0)
				{
					SetTexture("Textures/BatmanWalkUp.png");
				}
			}
			
			else if(down)
			{
				if(GetTextureName().compare("Textures/BatmanWalkDown.png") != 0)
				{
					SetTexture("Textures/BatmanWalkDown.png");
				}
			}
			
			break;

		case Player::Attack1 :
			
			if(left)
			{
				if(GetTextureName().compare("Textures/BatmanAttack.png") != 0)
				{
					SetTexture("Textures/BatmanAttack.png");
				}
			}

			else if(right)
			{
				if(GetTextureName().compare("Textures/BatmanAttackRight.png") != 0)
				{
					SetTexture("Textures/BatmanAttackRight.png");
				}
			}
			
			else if(up)
			{
				if(GetTextureName().compare("Textures/BatmanAttackUp.png") != 0)
				{
					SetTexture("Textures/BatmanAttackUp.png");
				}
			}
			
			else if(down)
			{
				if(GetTextureName().compare("Textures/BatmanAttackDown.png") != 0)
				{
					SetTexture("Textures/BatmanAttackDown.png");
				}
			}
			
			break;

		case Player::Attack2 :
			
			if(left)
			{
				if(GetTextureName().compare("Textures/BatmanAttack.png") != 0)
				{
					SetTexture("Textures/BatmanAttack.png");
				}
			}

			else if(right)
			{
				if(GetTextureName().compare("Textures/BatmanAttackRight.png") != 0)
				{
					SetTexture("Textures/BatmanAttackRight.png");
				}
			}
			
			else if(up)
			{
				if(GetTextureName().compare("Textures/BatmanAttackUp.png") != 0)
				{
					SetTexture("Textures/BatmanAttackUp.png");
				}
			}
			
			else if(down)
			{
				if(GetTextureName().compare("Textures/BatmanAttackDown.png") != 0)
				{
					SetTexture("Textures/BatmanAttackDown.png");
				}
			}
			
			break;

		case Player::IdleState :
			
			if(left)
			{
				
				if(GetTextureName().compare("Textures/BatmanIdle.png") != 0)
				{
					SetTexture("Textures/BatmanIdle.png");
				}
				
			}

			else if(right)
			{
				if(GetTextureName().compare("Textures/BatmanIdleRight.png") != 0)
				{
					SetTexture("Textures/BatmanIdleRight.png");
				}
			}
			
			else if(up)
			{
				if(GetTextureName().compare("Textures/BatmanIdleUp.png") != 0)
				{
					SetTexture("Textures/BatmanIdleUp.png");
				}
			}
			
			else if(down)
			{
				if(GetTextureName().compare("Textures/BatmanIdleDown.png") != 0)
				{
					SetTexture("Textures/BatmanIdleDown.png");
				}
			}
			
			break;
	}
	*/
}

string Player::IntString(int intToConvert)
{
	//string ret; 
	//_itow_s(intToConvert, ret, 10);
	return "";
}
