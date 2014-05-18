#include <stdio.h>
#include "Engine/Engine.h"
#include "Game/Game.h"

sf::RenderWindow* rWin;
Game* gameEngine;

/*
sf::Keyboard::Key* key = new sf::Keyboard::Key();

void keyPressed(sf::Keyboard::Key* key)
{
	gameEngine->OnKeyPressed(key);
}

void keyReleased(sf::Keyboard::Key* key)
{
	gameEngine->OnKeyPressed(key);
}

void pointerMoved()
{
	//gameEngine->OnPointerMoved();
}

void pointerPressed()
{
	///gameEngine->OnKeyPressed(key);
}

void pointerReleased()
{
	//gameEngine->OnKeyPressed(key);
}
*/

int main(int argc, char** argv)
{
	/*
	// Create Input Handler Threads
	sf::Thread onKeyPressed(&keyPressed, key);
	sf::Thread onKeyReleased(&keyReleased, key);
	sf::Thread onPointerMoved(&pointerMoved);
	sf::Thread onPointerPressed(&pointerPressed);
	sf::Thread onPointerReleased(&pointerReleased);
	*/

	// Create Game Engine Instance
	gameEngine = new Game();

	//Initialise Game Engine
	gameEngine->Initialize();

	rWin = gameEngine->GetRenderer();

	//Create Game Window
	rWin->create(sf::VideoMode(800, 600), "Game Window");
	rWin->setFramerateLimit(60);

	//Start Game Engine
	gameEngine->Start();
	
	sf::Clock globalClock;
	sf::Time globalTime;
	globalTime = globalClock.restart();
	// Game Loop
	while(rWin->isOpen())
	{
		sf::Event event;
        while (rWin->pollEvent(event))
        {
			switch(event.type)
			{
				case sf::Event::KeyPressed:
					gameEngine->OnKeyPressed(event.key.code);
					//*key = event.key.code;
					//onKeyPressed.launch();
					break;
				
				case sf::Event::KeyReleased:
					gameEngine->OnKeyReleased(event.key.code);
					//*key = event.key.code;
					//onKeyReleased.launch();
					break;

				case sf::Event::MouseMoved:
					gameEngine->OnPointerReleased(Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
					break;

				case sf::Event::MouseButtonPressed:
					gameEngine->OnPointerReleased(Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
					break;

				case sf::Event::MouseButtonReleased:
					gameEngine->OnPointerReleased(Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
					break;
				case sf::Event::Closed:
				rWin->close();
				return 0;
			}
            if (event.type == sf::Event::Closed)
            {
				rWin->close();
				return 0;
			}
		}

		//Clear the window with black color
		rWin->clear(sf::Color::Black);
		//Render all Game Objects
		globalTime = globalClock.getElapsedTime();
		gameEngine->Render(/*globalTime*/);
		//Display to Screen
		rWin->display();
		float frames = globalTime.asSeconds();
		if(frames > 6.0f)
		{
			globalTime = globalClock.restart();
		}
		/*
		clock.restart();
		sf::Time elapsed = clock.getElapsedTime();
		while( ( (elapsed.asSeconds()) <= 1.0f/45) )
		{
			elapsed = clock.getElapsedTime();
		}
		*/
        
	}

	return 0;
}
