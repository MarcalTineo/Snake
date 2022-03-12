#include "Snake.h"



Snake::Snake()
{
	headPosition = { 0, 0 };
	length = 0;
	forward = { 0, 0 };
	speed = 0;
	state = State::DEAD;
}

Snake::Snake(Vector2 _position, int _length, Vector2 _forward, float _speed)
{
	headPosition = _position;
	length = _length;
	forward = _forward;
	speed = _speed;
	positions = {};
	for (int i = 0; i < length; i++)
		positions.push_back(headPosition - (forward * i));
	state = State::ALIVE;
}


Snake::~Snake()
{
}

void Snake::Update(float dt)
{
	timer += dt;
	ProcessInputs ();
	if (timer > (1 / speed))
	{
		timer -= 1 / speed;
		MoveForward();

	}
}

void Snake::Draw()
{
	DrawEngine::GetInstance().DrawAtPos('O', headPosition.x, headPosition.y);
	for (int i = 1; i < length; i++)
	{
		DrawEngine::GetInstance().DrawAtPos('*', positions[i].x, positions[i].y);
	}
}

Snake::State Snake::GetState()
{
	return state;
}

void Snake::SetState(State newState)
{
	state = newState;
}

void Snake::AddOneLength()
{
	length++;
	positions.push_back(positions[length - 2]);
}

void Snake::ProcessInputs()
{
	if (Input::GetInstance().GetKeyDown(VK_UP) && forward != Vector2::Up())
		forward = -Vector2::Up();
	else if (Input::GetInstance().GetKeyDown(VK_DOWN) && forward != -Vector2::Up())
		forward = Vector2::Up();
	else if (Input::GetInstance().GetKeyDown(VK_RIGHT) && forward != -Vector2::Right())
		forward = Vector2::Right();
	else if (Input::GetInstance().GetKeyDown(VK_LEFT) && forward != Vector2::Right())
		forward = -Vector2::Right();
}

void Snake::MoveForward()
{
	headPosition += forward;
	for (int i = length - 1; i > 0; i--)
	{
		positions[i] = positions[i - 1];
	}
	positions[0] = headPosition;
}

void Snake::CheckCollisions()
{
	CheckCollisionsBody();
}

void Snake::CheckCollisionsBody()
{
	for (int i = 1; i < length; i++)
	{
		if (positions[i] == headPosition)
			state = State::DEAD;
	}
}
