#include "Food.h"

Food::Food()
{
	position = Vector2(5, 5);
}


Food::~Food()
{
}

void Food::Update(float dt)
{
}

void Food::Draw()
{
	DrawEngine::GetInstance().DrawAtPos('O', position.x, position.y, 12);
}

Vector2 Food::GetPosition()
{
	return position;
}

bool Food::IsColliding(Vector2 pos)
{
	return pos == position;
}

void Food::GoToRandomPosition(Vector2 pos, Vector2 size, Snake* snake)
{
	int x = 0;
	int y = 0;
	bool positionFound = true;
	do
	{
		positionFound = true;
		x = Helpers::GetRandomNumber(pos.x, pos.x + size.x);
		y = Helpers::GetRandomNumber(pos.y, pos.y + size.y);
		for (int i = 0; i < snake->GetLength(); i++)
		{
			if (snake->GetPositions()[i] == Vector2(x, y))
			{
				positionFound = false;
				break;
			}
		}
	}
	while (!positionFound);
	position = Vector2(x, y);
}
