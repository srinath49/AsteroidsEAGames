#include "BigRock.h"
#include "MediumRock.h"

void BigRock::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Player"))
	{
		
	}
	else if(_Object->CompareTag("Bullet"))
	{
		
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

}

string BigRock::GetType()
{
	return "BigRock";
}
