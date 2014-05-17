#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

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

	sf::Time timer;

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
	sf::Sprite* sprite;
	string textureName;

	void SetSize(float width, float height);
	void PlaySprite();
	void PauseSprite();
	void ResumeSprite();
	bool IsPlaying();
	void SetFrameSpeed(float speed);
	void SetTextureFrame(int frameNumber);
	void SetCurrentSprite();
	Texture();
};

