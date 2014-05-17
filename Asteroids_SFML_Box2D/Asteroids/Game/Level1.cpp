
#include "Level1.h"

void Level1::CreateLayers()
{
	BackgroundLayer = gameLoop->AddLayer();
}

void Level1::CreateGameObjects()
{
	Bgrd = new Background("ScreenBackground" , gameLoop , false , false , Vector2(0 , 0) , "ScreenBackground.png" , false , 1 , 1);
}

void Level1::AddObjectsToLayers()
{
	
	//Adding Background
	gameLoop->GetLayer(BackgroundLayer)->AddObjectToLayer(Bgrd);
	levelDone = false;

	/*
	//Giving Player reference to the Background to avoid nullptr exception
	levelBackground->batman = batman;

	gameLoop->GetLayer(CharactersLayer)->AddObjectToLayer(batman);

	gameLoop->GetLayer(CharactersLayer)->AddObjectToLayer(leftTruck);
	leftTruck->player = batman;
	gameLoop->GetLayer(CharactersLayer)->AddObjectToLayer(rightTruck);
	rightTruck->player = batman;

	//Adding Sheds
	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed1[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed1[1]);

	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed2[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed2[1]);

	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed3[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed3[1]);

	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed6[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed6[1]);

	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed7[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed7[1]);

	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(shed8[0]);
	gameLoop->GetLayer(EnvLayBelPlr)->AddObjectToLayer(shed8[1]);

	//Setting Tags as Shed so that the Raycast communicates with the waypoints and tells them that this path is not available for player or enemies
	shed1[0]->SetTag(L"Shed");
	shed1[1]->SetTag(L"Shed");

	shed2[0]->SetTag(L"Shed");
	shed2[1]->SetTag(L"Shed");

	shed3[0]->SetTag(L"Shed");
	shed3[1]->SetTag(L"Shed");

	shed6[0]->SetTag(L"Shed");
	shed6[1]->SetTag(L"Shed");

	shed7[0]->SetTag(L"Shed");
	shed7[1]->SetTag(L"Shed");

	shed8[0]->SetTag(L"Shed");
	shed8[1]->SetTag(L"Shed");

	//Adding Waypoints to the Waypoints Layer
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint1);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint2);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint3);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint4);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint5);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint6);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint7);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint8);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint9);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint10);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint11);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint12);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint13);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint14);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint15);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint16);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint17);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint18);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint19);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint20);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint21);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint22);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint23);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint24);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint25);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint26);
	gameLoop->GetLayer(WayPointsLayer)->AddObjectToLayer(wayPoint27);

	gameLoop->AddWayPoint(wayPoint1);
	gameLoop->AddWayPoint(wayPoint2);
	gameLoop->AddWayPoint(wayPoint3);
	gameLoop->AddWayPoint(wayPoint4);
	gameLoop->AddWayPoint(wayPoint5);
	gameLoop->AddWayPoint(wayPoint6);
	gameLoop->AddWayPoint(wayPoint7);
	gameLoop->AddWayPoint(wayPoint8);
	gameLoop->AddWayPoint(wayPoint9);
	gameLoop->AddWayPoint(wayPoint10);
	gameLoop->AddWayPoint(wayPoint11);
	gameLoop->AddWayPoint(wayPoint12);
	gameLoop->AddWayPoint(wayPoint13);
	gameLoop->AddWayPoint(wayPoint14);
	gameLoop->AddWayPoint(wayPoint15);
	gameLoop->AddWayPoint(wayPoint16);
	gameLoop->AddWayPoint(wayPoint17);
	gameLoop->AddWayPoint(wayPoint18);
	gameLoop->AddWayPoint(wayPoint19);
	gameLoop->AddWayPoint(wayPoint20);
	gameLoop->AddWayPoint(wayPoint21);
	gameLoop->AddWayPoint(wayPoint22);
	gameLoop->AddWayPoint(wayPoint23);
	gameLoop->AddWayPoint(wayPoint24);
	gameLoop->AddWayPoint(wayPoint25);
	gameLoop->AddWayPoint(wayPoint26);
	gameLoop->AddWayPoint(wayPoint27);

	//Adding Background Music
	//gameLoop->SetBackgroundMusic(L"TheDarkKnight.wav");


	// Add the Indicator to any layer and set it to the player
	gameLoop->GetLayer(IndicatorLayer)->AddObjectToLayer(indicator);
	batman->SetMoveIndicator(indicator);

	// Creating and Adding The Timer
	gameLoop->GetLayer(CharactersLayer)->AddObjectToLayer(TimeImage);
	gameLoop->GetLayer(EnvLayAbvPlr)->AddObjectToLayer(TimeObject);
	TimeRemaining = 120.f;
	SetLevelTimer();
	m_Timer->Reset();
	previousTime = m_Timer->Total;

	BuildAIPrototypes();
	SpawnUnit(1, 2);
	*/
	
}

void Level1::LevelWon()
{
	levelDone = true;
	gameLoop->RequestLevelLoad(2);
}

void Level1::LevelLost()
{
	levelDone = true;
	gameLoop->RequestNextLevelLoad();
}

void Level1::Update(unsigned long frameNumber)
{	
	if(levelDone)
	{
		return;
	}
}
