#include "Player.h"


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



string Player::IntString(int intToConvert)
{
	//string ret; 
	//_itow_s(intToConvert, ret, 10);
	return "";
}


void Player::OnKeyPressed(sf::Keyboard::Key pressedKey)
{
	switch(pressedKey)
	{
		case sf::Keyboard::Up:
			MovePlayer(MoveDirection::Up);
			//player->AddForce(0.0f, 1.0f, Coordinate::Global);
			//printf("Up Pressed\n");
			break;
		case sf::Keyboard::Down:
			MovePlayer(MoveDirection::Down);
			//player->AddForce(0.0f, -1.0f, Coordinate::Global);
			//printf("Down Pressed\n");
			break;
		case sf::Keyboard::Right:
			RotatePlayer(RotationAngle::Right);
			//AddForce(1.0f, 0.0f, Coordinate::Global);
			//printf("Right Pressed\n");
			break;
		case sf::Keyboard::Left:
			RotatePlayer(RotationAngle::Left);
			//player->AddForce(-1.0f, 0.0f, Coordinate::Global);
			//printf("Left Pressed\n");
			break;
	}
}

void Player::OnKeyReleased(sf::Keyboard::Key releasedKey)
{
	switch(releasedKey)
	{
		case sf::Keyboard::Right:
			//player->AddForce(1.0f, 0.0f, Coordinate::Global);
			//printf("Right Pressed\n");
			break;
		case sf::Keyboard::Left:
			//player->AddForce(-1.0f, 0.0f, Coordinate::Global);
			//printf("Left Pressed\n");
			break;
		case sf::Keyboard::Up:
			//player->AddForce(0.0f, 1.0f, Coordinate::Global);
			//printf("Up Pressed\n");
			break;
		case sf::Keyboard::Down:
			//player->AddForce(0.0f, -1.0f, Coordinate::Global);
			//printf("Down Pressed\n");
			break;
		case sf::Keyboard::A:
			//player->collisionBox->SetAngularVelocity(0.05f);
			//printf("Down Pressed\n");
			break;
		case sf::Keyboard::S:
			//player->collisionBox->SetAngularVelocity(-0.05f);
			//printf("Down Pressed\n");
			break;
	}
}

void Player::MovePlayer(MoveDirection direction)
{
	//if()
}

void Player::RotatePlayer(RotationAngle angle)
{

}
