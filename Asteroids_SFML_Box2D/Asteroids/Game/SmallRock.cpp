#include "SmallRock.h"

void SmallRock::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Player"))
	{
		
	}
	else if(_Object->CompareTag("Bullet"))
	{
		
	}
	
}

void SmallRock::EndContact(GameObject*)
{

}

void SmallRock::Start()
{
	SetGravity(0.0f);
	SetVelocity(0.0f,0.0f);
}

void SmallRock::Update(unsigned long frameNumber)
{

}

string SmallRock::GetType()
{
	return "BigRock";
}
