#include <stdio.h>
#include "Engine/Engine.h"
#include "Game/Game.h"

int main(int argc, char** argv)
{
	Game* gameEngine = new Game();

	//Initialise Game Engine
	gameEngine->Initialize();

	sf::RenderWindow* rWin = gameEngine->GetRenderer();

	//Create Game Window
	rWin->create(sf::VideoMode(800, 600), "Game Window");
	rWin->setFramerateLimit(30);

	//Start Game Engine
	gameEngine->Start();
	
	sf::Clock clock;
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

			clock.restart();
			sf::Time elapsed = clock.getElapsedTime();
			while( ( (elapsed.asSeconds()) <= 1.0f/45) )
			{
				elapsed = clock.getElapsedTime();
			}
        }
	}

	return 0;
}
