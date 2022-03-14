#include "SnakeGame.h"



SnakeGame::SnakeGame()
{
	SizeX = 60;
	SizeY = 28;
	defaultColor = 15;
	state = State::TITLE_SCREEN;
	startLenght = 3;
	
	Start();
}


SnakeGame::~SnakeGame()
{
	delete board;
	delete snake;
	delete food;
	delete hud;
}

void SnakeGame::Start()
{
	board = new Board(Vector2(SizeX, SizeY));
	snake = new Snake(Vector2(SizeX, SizeY) / 2, startLenght, Vector2(1, 0), 3);
	food = new Food(Vector2(SizeX, SizeY) / 2 + Vector2::Right() * 10);
	hud = new HUD();
}

void SnakeGame::Update(float dt)
{
	switch (state)
	{
	case SnakeGame::TITLE_SCREEN:
		UpdateTitleScreen();
		break;
	case SnakeGame::PLAYING:
		UpdatePlaying(dt);
		break;
	case SnakeGame::GAME_OVER:
		UpdateGameOver();
		break;
	default:
		break;
	}
}

void SnakeGame::UpdateTitleScreen()
{
	if (Input::GetInstance().AnyKey())
	{
		state = State::PLAYING;
		DrawEngine::GetInstance().Clear();
	}
}

void SnakeGame::UpdatePlaying(float dt)
{
	snake->Update(dt);
	if (food->IsColliding(snake->GetHeadPosition()))
	{
		food->GoToRandomPosition(Vector2(1, 4), Vector2(SizeX - 3, SizeY - 6), snake);
		snake->AddOneLength();
		hud->AddScore(1);
	}
	if (!board->InsideBorders(snake->GetHeadPosition()))
		snake->SetState(Snake::State::DEAD);
	if (snake->GetState() == Snake::State::DEAD)
	{
		state = State::GAME_OVER;
		DrawEngine::GetInstance().Clear();
		if (hud->GetScore() > hud->GetHighScore())
			hud->SetHighScore();
	}
}

void SnakeGame::UpdateGameOver()
{
	if (Input::GetInstance().GetKeyDown('E'))
		Kill();
	if (Input::GetInstance().GetKeyDown('R'))
	{
		ResetGame();
		state = State::PLAYING;
		DrawEngine::GetInstance().Clear();
	}
}

void SnakeGame::Draw()
{
	switch (state)
	{
	case SnakeGame::TITLE_SCREEN:
		DrawTitleScreen();
		break;
	case SnakeGame::PLAYING:
		DrawPlaying();
		break;
	case SnakeGame::GAME_OVER:
		DrawGameOver();
		break;
	default:
		break;
	}
}

void SnakeGame::DrawTitleScreen()
{
	DrawEngine::GetInstance().SetCursorPosition(0, 3);
	std::cout << title;
	DrawEngine::GetInstance().SetCursorPosition(30, 18);
	std::cout << "Press any key to start" << std::endl;
}

void SnakeGame::DrawPlaying()
{
	DrawEngine::GetInstance().InitViewport();
	board->Draw();
	food->Draw();
	snake->Draw();
	hud->Draw();
	DrawEngine::GetInstance().Flush();
}

void SnakeGame::DrawGameOver()
{
	DrawEngine::GetInstance().SetCursorPosition(0, 1);
	std::cout << gameOver << std::endl;
	DrawEngine::GetInstance().SetCursorPosition(13, 15);
	std::cout << "Restart [R]    Exit [E]";
}

SnakeGame::State SnakeGame::GetState()
{
	return state;
}

void SnakeGame::SetState(State newState)
{
	state = newState;
}

void SnakeGame::ResetGame()
{
	delete snake;
	snake = new Snake(Vector2(SizeX, SizeY) / 2, startLenght, Vector2(1, 0), 3);
	delete food;
	food = new Food(Vector2(SizeX, SizeY) / 2 + Vector2::Right() * 10);
	hud->SetScore(0);
}
