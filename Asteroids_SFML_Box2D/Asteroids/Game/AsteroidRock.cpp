#include "AsteroidRock.h"

void AsteroidRock::SetState(AsteroidState newState)
{
	previousState = currentState;
	currentState = newState;
}