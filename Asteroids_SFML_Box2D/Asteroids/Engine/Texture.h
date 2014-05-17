#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "AnimatedSprite.hpp"

using namespace std;

class Texture
{
private:
	int currentColumn;
	
	int currentRow;

	float frameStartTime;
	float nextFrameTime;

	bool nextFrame;
	bool pause;

public:
	int textureID;
	int rows;
	int columns;
	int currentFrame;
	int numOfFrames;

	float width;
	float height;
	float frameRight;
	float frameLeft;
	float frameTop;
	float frameBotom;
	float frameSpeed;
	bool isSprite;

	sf::Texture* image;
	AnimatedSprite* sprite;
	string textureName;

	sf::Time globalTime;

	void SetSize();
	void PlaySprite(Animation anim);
	void PauseSprite();
	void ResumeSprite();
	bool IsPlaying();
	void SetFrameSpeed(float speed);
	void SetTextureFrame(int frameNumber);
	Texture();
};

