#include "MediumRock.h"
#include "SmallRock.h"

void MediumRock::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Player"))
	{
		
	}
	else if(_Object->CompareTag("Bullet"))
	{
		
	}
	
}

void MediumRock::EndContact(GameObject*)
{

}

void MediumRock::Start()
{
	SetGravity(0.0f);
	SetVelocity(0.0f,0.0f);
}

void MediumRock::Update(unsigned long frameNumber)
{

}

string MediumRock::GetType()
{
	return "BigRock";
}
