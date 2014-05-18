#include "BigRock.h"

void BigRock::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Rock"))
	{
		SetState(DyingState);
	}
	
}

void BigRock::EndContact(GameObject*)
{

}

void BigRock::Start()
{
	
	SetGravity(0.0f);
	SetVelocity(0.0f,0.0f);
}

void BigRock::Update(unsigned long frameNumber)
{
	
	switch(currentState)
	{
		case DyingState:
			Destroy();
			break;
	}
	
}

string BigRock::GetType()
{
	return "BigRock";
}
