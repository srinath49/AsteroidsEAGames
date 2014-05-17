#include "Game.h"
#include "Engine\Layer.h"
#include "Game\Level1.h"


void Game::Start()
{
	previousLevel = 0;
	currentLevel = 0;

	levelManager = new LevelManager(this, 1);
	levelManager->CreateLevel(new Level1(this, 0));
	LoadLevel(0);
}

void Game::Update(unsigned long frameNumber)
{
	switch(currentState)
	{
		case GameState::RequestForLevelLoad: 
			loadRequestedFrame = frameNumber;
			SetGameState(GameState::LoadTheLevel);
			UnLoadLevel(currentLevel);
			break;
		case GameState::LoadTheLevel: 
			if(frameNumber > loadRequestedFrame+10 && levelManager)
			{
				LoadLevel(levelToLoad);
				SetGameState(GameState::LoadingLevel);
			}
			break;
		case GameState::ReloadTheLevel: 
			RequestLevelReload();
			break;
		case GameState::LoadingLevel: 
			if(levelManager && levelManager->GetCurrentLevel()->GetLevelState() == LevelState::LevelLoaded)
			{
				SetGameState(GameState::RunningLevel);
			}
				break;
		case GameState::LoadTheNextLevel: 
			RequestNextLevelLoad();
			break;
		case GameState::RunningLevel: 
			if(levelManager)
			{
				levelManager->Update(frameNumber);
			} 
			break;
	}
}

void Game::OnPointerPressed(Vector2 _TouchPoint)
{
	/*
	if(CurrentLevel == 0 || !levelManager || !levelManager->Levels[CurrentLevel])
	{
		return;
	}
	if(CurrentLevel == 1)
	{
		if(((Level1*)levelManager->Levels[CurrentLevel])->batman && ((Level1*)levelManager->Levels[CurrentLevel])->batman->pointerPressed)
		{
			((Level1*)levelManager->Levels[CurrentLevel])->batman->pointerPressed = false;
			return;
		}
		if(levelManager && levelManager->Levels[CurrentLevel] && ((Level1*)levelManager->Levels[CurrentLevel])->batman) 
		{
			((Level1*)levelManager->Levels[CurrentLevel])->batman->CurrentDestination = _TouchPoint;
			((Level1*)levelManager->Levels[CurrentLevel])->batman->hasAnotherLocation = false;
			((Level1*)levelManager->Levels[CurrentLevel])->batman->SetVelocity(0.0f,0.0f);
			if(((Level1*)levelManager->Levels[CurrentLevel])->batman->GetState() != Player::PlayerState::WalkingState)
			{
				((Level1*)levelManager->Levels[CurrentLevel])->batman->SetState(Player::PlayerState::WalkingState);
			}
		}
	}
	*/
}

void Game::OnPointerMoved(Vector2 _TouchPoint)
{

}

void Game::OnPointerReleased(Vector2 _TouchPoint)
{
	
}

void Game::LoadLevel(int level)
{
	//ResetWayPoints();
	if(levelManager)
	{
		if(levelManager->LoadLevel(level))
		{
			previousLevel = currentLevel;
			currentLevel = level;
		}
	}
}

void Game::UnLoadLevel(int Level)
{
	/*
	if(m_audioManager)
	{
		m_audioManager->ResetAudioEngine();
	}
	*/
	if(levelManager)
	{
		levelManager->UnloadCurrentLevel();
	}
	//ResetWayPoints();
}

void Game::LoadNextLevel()
{
	LoadLevel(currentLevel + 1);
}

void Game::RestartLevel()
{
	
	if(levelManager)
	{
		/*
		if(m_audioManager)
		{
			m_audioManager->ResetAudioEngine();
		}
		*/
		levelManager->ReloadLevel();
	}
	
}

void Game::SetGameState(GameState newState)
{
	previousState = currentState;
	currentState = newState;
}

GameState Game::GetGameState()
{
	return currentState;
}


void Game::RequestLevelLoad(int levelToLoad)
{
	levelToLoad = levelToLoad;
	SetGameState(GameState::RequestForLevelLoad);
}

void Game::RequestLevelReload()
{
	RequestLevelLoad(currentLevel);
}

void Game::RequestNextLevelLoad()
{
	RequestLevelLoad(currentLevel+1);
}
