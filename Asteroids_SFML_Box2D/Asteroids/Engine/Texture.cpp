#include "Texture.h"

/*

Ex -> Texture Sprite work

		   Colums
		  0|  1|   2|   3|
	  0| F0| F1|  F2|  F3|
Rows  1| F4| F5|  F6|  F7|
	  2| F8| F9| F10| F11|

FX <- Frames 
Total Frames = 12

*/

Texture::Texture()
{
	timer = sf::seconds(1.0f/60);
	currentFrame = 0;
	currentColumn = 0;
	currentRow = 0;
	nextFrame = true;
	pause = false;
}

void Texture::SetSize(float width, float height)
{
	if(isSprite)
	{
		width = width/columns;
		height = height/rows;
	}
	else
	{
		width = width;
		height = height;
	}

	numOfFrames = rows*columns;
}

void Texture::PlaySprite()
{
	if(!pause)
	{
		float timeForSingleRow = (1/frameSpeed)/rows;
		float timeForSingleColum = (1/frameSpeed)/columns;

		if(isSprite && (frameSpeed>0) )
		{
		
			#pragma region Single Frame
				
				sprite->setTextureRect(sf::IntRect(currentColumn*32,currentRow*32,width,height));

				frameLeft = width  * currentColumn;	
				frameRight = width + (width  * currentColumn);

				frameTop = height * currentRow;
				frameBotom = height + ( height  * currentRow);

				sf::Clock clock;
				if(nextFrame)
				{
					frameStartTime = clock.getElapsedTime().asSeconds()/60;
					nextFrame = false;
				}

				if((clock.getElapsedTime().asSeconds()/60 - frameStartTime) >= timeForSingleRow)
				{
					currentColumn++;
					nextFrame = true;
				
					currentFrame++;
				}
				clock.restart();

				if(currentColumn >= columns )
				{
					currentColumn = 0;
					currentRow++;
				}

				if(currentRow >= rows)
				{
					currentRow = 0;
					currentFrame = 0;
				}
			#pragma endregion
				
		}
		else
		{
			sprite->setTexture(*image, true);
			frameLeft = 0;
			frameRight = width;

			frameTop = 0;
			frameBotom = height;
		}
	}

}

void Texture::PauseSprite()
{
	pause = true;
}

void Texture::ResumeSprite()
{
	pause = false;
}

// Set the frame according to given frame number
void Texture::SetTextureFrame(int frameNumber)
{
	int frameRow, frameColumn; 
	
	if(frameNumber > numOfFrames)
	{
		frameNumber = numOfFrames-1;
	}
	currentFrame = frameNumber;
	if(rows>=columns)
	{
		frameRow  = frameNumber/rows;
		frameColumn  = frameNumber/rows;
	}
	else
	{
		frameRow  = frameNumber/columns;
		frameColumn  = frameNumber/columns;
	}

	currentColumn = frameColumn;
	currentRow = frameRow;

	frameLeft = width  * currentColumn;	
	frameRight = width + (width  * currentColumn);

	frameTop = height * currentRow;
	frameBotom = height + ( height  * currentRow);
}

bool Texture::IsPlaying()
{
	return pause;
}

void Texture::SetFrameSpeed(float speed)
{
	frameSpeed = speed;
}	