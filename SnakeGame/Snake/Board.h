#pragma once
#include <IActor.h>
#include <DrawEngine.h>
#include <Vector2.h>

class Board : public IActor
{
	Vector2 size;
	enum boardParts
	{
		I_Horizontal = 205,
		I_Vertical = 186,
		L_UpLeft = 201,
		L_UpRight = 187,
		L_DownLeft = 200,
		L_DownRight = 188,
		T_Up = 202,
		T_Down = 203,
		T_Left = 185,
		T_Right = 204,
		X = 206
	};

public:
	Board(Vector2 size) : size(size) {};
	~Board();

	// Inherited via IActor
	virtual void Update(float dt) override;

	virtual void Draw() override;

	void DrawFullLine(char first, char middle, char last, int line);

	void DrawMiddleLine(char c, int line);
};

