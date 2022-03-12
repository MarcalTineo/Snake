#include "SnakeGame.h"



SnakeGame::SnakeGame()
{
	SizeX = 100;
	SizeY = 28;
	defaultColor = 15;
	Start();
}


SnakeGame::~SnakeGame()
{
	delete board;
	delete snake;
	delete food;
}

void SnakeGame::Start()
{
	board = new Board(Vector2(SizeX, SizeY));
	snake = new Snake(Vector2(50, 10), 3, Vector2(1, 0), 3);
	food = new Food();
}

void SnakeGame::Update(float dt)
{
	snake->Update(dt);
}

void SnakeGame::Draw()
{
	DrawEngine::GetInstance().InitViewport();
	board->Draw();
	snake->Draw();
	DrawEngine::GetInstance().Flush();
}
