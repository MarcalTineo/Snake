#pragma once
#include <IActor.h>
#include <Vector2.h>
#include <Helpers.h>
#include <DrawEngine.h>
#include "Snake.h"

class Food : public IActor
{
	Vector2 position;
public:
	Food();
	Food(Vector2 pos) : position(pos) {};
	~Food();

	// Inherited via IActor
	virtual void Update(float dt) override;
	virtual void Draw() override;
	Vector2 GetPosition();
	bool IsColliding(Vector2 pos);
	void GoToRandomPosition(Vector2 pos, Vector2 size, Snake* snake);
};

