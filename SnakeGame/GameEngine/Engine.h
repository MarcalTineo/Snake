#pragma once
#include "IGame.h"
#include <iostream>
#include <chrono>
#include "Windows.h"
#include "Input.h"
#include "DrawEngine.h"


class Engine
{

	public:
	IGame* currentGame;

	int FPS;
	float deltaSeconds;

	long long initTime;
	float dt;

	long long nextTime;

	Engine(IGame* game, int fps);
	~Engine();
	void RunGame();
	long long GetTime();
};

