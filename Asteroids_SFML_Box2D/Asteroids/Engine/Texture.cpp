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
	currentFrame = 0;
	currentColumn = 0;
	currentRow = 0;
	nextFrame = true;
	pause = true;
	image = new sf::Texture();
	sprite = new AnimatedSprite(sf::seconds(6.0f), true, true);	
}

void Texture::SetSize()
{
	float w = image->getSize().x;
	float h = image->getSize().y;

	if(isSprite)
	{
		width = w/columns;
		height = h/rows;
	}
	else
	{
		width = w;
		height = h;
	}

	numOfFrames = rows*columns;
}

void Texture::PlaySprite(Animation anim)
{
	if(!pause)
	{
		sprite->play(anim); 
		sprite->update(globalTime);
	}

}

void Texture::PauseSprite()
{
	pause = true;
	sprite->pause();
}

void Texture::ResumeSprite()
{
	pause = false;
	sprite->play();
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
