#include <stdio.h>
#include "Engine/Engine.h"
#include "Game/Game.h"

int main(int argc, char** argv)
{
	Game* gameEngine = new Game();

	sf::RenderWindow* rWin = gameEngine->GetRenderer();

	//Initialise Game Window
	rWin = new sf::RenderWindow();
	//Initialise Game Engine
	gameEngine->Initialize();

	//Create Game Window
	rWin->create(sf::VideoMode(800, 600), "Game Window");
	rWin->setFramerateLimit(30);

	//Start Game Engine
	gameEngine->Start();

	// Game Loop
	while(rWin->isOpen())
	{
		sf::Event event;
        while (rWin->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
				rWin->close();
				return 0;
			}

			//Clear the window with black color
			rWin->clear(sf::Color::Black);
			//Render all Game Objects
			gameEngine->Render();
			//Display to Screen
			rWin->display();

			sf::Clock clock;
			sf::Time elapsed = clock.getElapsedTime();
			while( ( (elapsed.asSeconds()) <= 1.0f/30) )
			{
				elapsed = clock.getElapsedTime();
				//printf("%f\n", elapsed.asSeconds());
				//DoNothing
			}
			clock.restart();
        }
	}

	return 0;
}
