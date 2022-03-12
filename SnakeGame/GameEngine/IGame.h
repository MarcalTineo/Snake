#pragma once

class IGame
{
protected:
	bool isAlive;
	int SizeX;
	int SizeY;
	int defaultColor;
public:
	int GetSizeX();
	int GetSizeY();
	int GetDefultColor();
	IGame();
	~IGame();
	bool IsAlive();
	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	void Kill();
};

