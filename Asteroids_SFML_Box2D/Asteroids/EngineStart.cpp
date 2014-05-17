#include <stdio.h>
#include "Game/Game.h"

int main(int argc, char** argv)
{
	Game* asteroids;
	asteroids->Initialize();
	asteroids->Start();

	return 0;
}
