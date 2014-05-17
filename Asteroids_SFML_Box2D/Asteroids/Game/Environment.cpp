
#include "Environment.h"
#include "Game.h"

void Environment::BeginContact(GameObject*)
{
}

void Environment::EndContact(GameObject*)
{
}

void Environment::Start()
{
	SetGravity(0.0f);
	SetVelocity(0.0f, 0.0f);
	SetCollisionScale(0.8f, 0.8f);
	if(IsDynamic())
	{
		SetDynamicBody(false);
	}
	IsTrigger(true);
}

void Environment::Update(unsigned long frameNumber)
{
}

string Environment::GetType()
{
	return "Environment";
}

void Environment::OnPointerPressed(Vector2 _Point)
{
	/*if(playerRef)
	{
		Vector2 nearestPoint1, nearestPoint2;
		((Game*)engineRef)->GetNearestWayPoint(_Point, nearestPoint1, nearestPoint2);
		playerRef->MoveToPoint(((playerRef->GetDistance(_Point, nearestPoint1) < playerRef->GetDistance(_Point, nearestPoint2))?nearestPoint1:nearestPoint2), 1.0f);
	}*/
}

void Environment::OnPointerMoved(Vector2 _Point)
{
}

void Environment::OnPointerReleased(Vector2 _Point)
{
}