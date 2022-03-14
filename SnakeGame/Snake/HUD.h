#pragma once
#include <IActor.h>
#include <DrawEngine.h>
#include <Helpers.h>

class HUD : public IActor
{
	int score;
	int highScore;
public:
	HUD();
	~HUD();

	virtual void Update(float dt) override;

	virtual void Draw() override;
	void DrawHighScore();
	void DrawScore();

	int GetScore();
	int GetHighScore();
	void SetScore(int n);
	void SetHighScore();

	void AddScore(int n);
};

