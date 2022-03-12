#pragma once
#include <IGame.h>
#include <iostream>
#include <DrawEngine.h>
#include "Board.h"
#include "Snake.h"
#include "Food.h"

class SnakeGame : public IGame
{
	Board* board;
	Snake* snake;
	Food* food;

	public:
	SnakeGame();
	~SnakeGame();

	// Inherited via IGame
	virtual void Start() override;
	virtual void Update(float dt) override;
	virtual void Draw() override;
};

