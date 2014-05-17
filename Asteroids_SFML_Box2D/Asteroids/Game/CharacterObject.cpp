
#include "CharacterObject.h"
#include "Game.h"

#define OFFSET 0.8f

void CharacterObject::BeginContact(GameObject*){}

void CharacterObject::EndContact(GameObject*){}

void CharacterObject::Start()
{
	Animation anim;
	anim.setSpriteSheet(*currentTexture->image);
    anim.addFrame(sf::IntRect(0, 0, 64, 64));
    anim.addFrame(sf::IntRect(32, 0, 64, 64));
    anim.addFrame(sf::IntRect(64, 0, 64, 64));
    anim.addFrame(sf::IntRect(96, 0, 64, 64));

	AddAnimation("anim", anim);
	currentAnim = anim;
	currentTexture->ResumeSprite();
	pointerPressed = false;
}

void CharacterObject::Update(unsigned long frameNumber){}

string CharacterObject::GetType()
{
	return "CharacterObject";
}

void CharacterObject::OnPointerPressed(Vector2 _Point)
{
	int i = 0;
}

void CharacterObject::OnPointerMoved(Vector2 _Point)
{
}

void CharacterObject::OnPointerReleased(Vector2 _Point)
{
}

void CharacterObject::MoveToPoint(Vector2 _MovePoint, float SpeedLimit)
{
	//if(RayCast(_MovePoint, L"Shed"))
	//{
	//	Vector2 NearestPoint[2];
	//	GetNearestWayPoint(position, NearestPoint[0], NearestPoint[1]);
	//	CurrentDestination = GetDistance(position, NearestPoint[0]) <= GetDistance(position, NearestPoint[1])? NearestPoint[0] : NearestPoint[1];

	//	if(!hasAnotherLocation)
	//	{
	//		hasAnotherLocation = true;
	//		NextLocation = _MovePoint;
	//		FinalDestination = _MovePoint;
	//	}
	//	else
	//	{
	//		//NextLocation = _MovePoint;
	//		return;
	//	}
	//	return;
	//}
	
	if(GetVelocitySize() < SpeedLimit)
	{
		AddForce(2.0f*x_MoveOffset, 2.0f*y_MoveOffset, Coordinate::Global);
	}
}

void CharacterObject::SetOrientation(Vector2 _MovePoint)
{
	/*
	if(position.x > _MovePoint.x)
	{
		if(!left)
		{
			SetVelocity(0.0f,0.0f);
			left = true;
			x_MoveOffset = -1;
			y_MoveOffset = 0;

			//left = false;
			right = false;
			up = false;
			down = false;
			upleft = false;
			upright = false;
			downleft = false;
			downright = false;
		}
		if(IsPlayer)
		{
			if( moveIndicator)
			{
				moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
			}
		}
		else
		{
			if( moveIndicator)
			{
				if((left || right) && CurrentDestination.y != position.y)
				{
					moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
				}
				else if((up || down) && CurrentDestination.x != position.x)
				{
					moveIndicator->SetPosition(Vector2(position.x, _MovePoint.y));
				}
				else
				{
					moveIndicator->SetPosition(Vector2(200.f,200.f));
				}
			}
		}
	}
	else if(position.x < _MovePoint.x)
	{
		if(!right)
		{
			SetVelocity(0.0f,0.0f);
			right = true;
			x_MoveOffset = 1;
			y_MoveOffset = 0;

			left = false;
			//right = false;
			up = false;
			down = false;
			upleft = false;
			upright = false;
			downleft = false;
			downright = false;
		}
		if(IsPlayer)
		{
			if( moveIndicator)
			{
				//SetVelocity(0.0f,0.0f);
				moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
			}
		}
		else
		{
			if( moveIndicator)
			{
				if(CurrentDestination.x != position.x && CurrentDestination.y != position.y)
				{
					moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
				}
				else
				{
					moveIndicator->SetPosition(Vector2(200.f,200.f));
				}
			}
		}
	}
	else if(position.y < _MovePoint.y)
	{
		if(!up)
		{
			SetVelocity(0.0f,0.0f);
			up = true;
			x_MoveOffset = 0;
			y_MoveOffset = 1;

			left = false;
			right = false;
			//up = false;
			down = false;
			upleft = false;
			upright = false;
			downleft = false;
			downright = false;
		}
		if(IsPlayer)
		{
			if( moveIndicator)
			{
				if(CurrentDestination.x != position.x && CurrentDestination.y != position.y)
				{
					moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
				}
				else
				{
					moveIndicator->SetPosition(Vector2(200.f,200.f));
				}
			}
		}
		else
		{
			if( moveIndicator)
			{
				if(CurrentDestination.x != position.x && CurrentDestination.y != position.y)
				{
					moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
				}
				else
				{
					moveIndicator->SetPosition(Vector2(200.f,200.f));
				}
			}
		}
	}
	else if(position.y > _MovePoint.y)
	{
		if(!down)
		{
			SetVelocity(0.0f,0.0f);
			down = true;
			x_MoveOffset = 0;
			y_MoveOffset = -1;

			left = false;
			right = false;
			up = false;
			//down = false;
			upleft = false;
			upright = false;
			downleft = false;
			downright = false;
		}
		if(IsPlayer)
		{
			if( moveIndicator)
			{
				//SetVelocity(0.0f,0.0f);
				moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
			}
		}
		else
		{
			if( moveIndicator)
			{
				if(CurrentDestination.x != position.x && CurrentDestination.y != position.y)
				{
					moveIndicator->SetPosition(Vector2(_MovePoint.x, position.y));
				}
				else
				{
					moveIndicator->SetPosition(Vector2(200.f,200.f));
				}
			}
			else
			{
				moveIndicator = new MoveIndicator("MyIndicator", engineRef,true, true, Vector2(200.0f,200.0f), "Textures/WayPoint.png", false, 1,1);
				engineRef->GetLayer(0)->AddObjectToLayer(moveIndicator);
			}
		}
	}
	*/
}

void CharacterObject::SetStateTextureWithOrientation()
{
}

void CharacterObject::GetNearestWayPoint(Vector2 _FromPoint, Vector2 &point1, Vector2 &point2)
{
	//((Game*)engineRef)->GetNearestWayPoint(_FromPoint, point1, point2);
}

float CharacterObject::GetDistance(Vector2 Point1, Vector2 Point2)
{
	float p1 = (Point2.x-Point1.x);
	p1*=p1;
	float p2 = (Point2.y-Point1.y);
	p2*=p2;
	return sqrtf((p1)+(p2));
}

extern b2World* world; 
// RayCasting from game object position to a point in the world
bool CharacterObject::RayCast(Vector2 _PointToCast, string Tag)
{
	float angle = (_PointToCast.y-position.y)/(_PointToCast.x-position.x);
	float length = GetDistance(_PointToCast, this->position);;
	return GameObject::RayCast(position, angle, length, Tag);
}