#include "BigRock.h"
#include "MediumRock.h"
#include <math.h>

void BigRock::BeginContact(GameObject* _Object)
{
	if(_Object->CompareTag("Player"))
	{
		
	}
	else if(_Object->CompareTag("Bullet"))
	{   
   		SetState(BlastState);
	}
	
}

void BigRock::EndContact(GameObject*)
{

}

void BigRock::Start()
{
	SetGravity(0.0f);
	SetTag("Rock");
	float xVel = RandFloatInRange(-0.5f, 0.5f);
	float yVel = RandFloatInRange(-0.5f, 0.5f);
	SetVelocity(xVel, yVel);
	//this->collisionBox->ApplyTorque(RandFloatInRange(0.5f, 1.5f), true);
	SetState(NormalState);
}

void BigRock::Update(unsigned long frameNumber)
{

}

string BigRock::GetType()
{
	return "BigRock";
}

void BigRock::BlastRock()
{
}