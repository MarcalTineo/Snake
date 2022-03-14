#pragma once
#include <IGame.h>
#include <iostream>
#include <DrawEngine.h>
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "HUD.h"

class SnakeGame : public IGame
{
public:
	enum State
	{
		TITLE_SCREEN, 
		PLAYING, 
		GAME_OVER
	};
	std::string title =
		"\t      ___           ___           ___           ___           ___              \n"
		"\t     /\\  \\         /\\__\\         /\\  \\         /\\__\\         /\\  \\             \n"
		"\t    /::\\  \\       /::|  |       /::\\  \\       /:/  /        /::\\  \\            \n"
		"\t   /:/\\ \\  \\     /:|:|  |      /:/\\:\\  \\     /:/__/        /:/\\:\\  \\           \n"
		"\t  _\\:\\~\\ \\  \\   /:/|:|  |__   /::\\~\\:\\  \\   /::\\__\\____   /::\\~\\:\\  \\          \n"
		"\t /\\ \\:\\ \\ \\__\\ /:/ |:| /\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:::::\\__\\ /:/\\:\\ \\:\\__\\         \n"
		"\t \\:\\ \\:\\ \\/__/ \\/__|:|/:/  / \\/__\\:\\/:/  / \\/_|:|~~|~    \\:\\~\\:\\ \\/__/         \n"
		"\t  \\:\\ \\:\\__\\       |:/:/  /       \\::/  /     |:|  |      \\:\\ \\:\\__\\           \n"
		"\t   \\:\\/:/  /       |::/  /        /:/  /      |:|  |       \\:\\ \\/__/           \n"
		"\t    \\::/  /        /:/  /        /:/  /       |:|  |        \\:\\__\\             \n"
		"\t     \\/__/         \\/__/         \\/__/         \\|__|         \\/__/             \n";

	std::string gameOver = 
		"\t   _____          __  __ ______ \n"
		"\t  / ____|   /\\   |  \\/  |  ____|\n"
		"\t | |  __   /  \\  | \\  / | |__   \n"
		"\t | | |_ | / /\\ \\ | |\\/| |  __|  \n"
		"\t | |__| |/ ____ \\| |  | | |____ \n"
		"\t  \\_____/_/    \\_\\_|__|_|______|\n"
		"\t  / __ \\\\ \\    / /  ____|  __ \\  \n"
		"\t | |  | |\\ \\  / /| |__  | |__) | \n"
		"\t | |  | | \\ \\/ / |  __| |  _  /  \n"
		"\t | |__| |  \\  /  | |____| | \\ \\  \n"
		"\t  \\____/    \\/   |______|_|  \\_\\ \n";
private:
	Board* board;
	Snake* snake;
	Food* food;
	HUD* hud;

	State state;
	int startLenght;

public:
	SnakeGame();
	~SnakeGame();

	// Inherited via IGame
	virtual void Start() override;

	virtual void Update(float dt) override;
	void UpdateTitleScreen();
	void UpdatePlaying(float dt);
	void UpdateGameOver();

	virtual void Draw() override;
	void DrawTitleScreen();
	void DrawPlaying();
	void DrawGameOver();


	State GetState();
	void SetState(State newState);

	void ResetGame();
};

