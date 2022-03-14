#include "Snake.h"



Snake::Snake()
{
	headPosition = { 0, 0 };
	length = 0;
	forward = { 0, 0 };
	speed = 0;
	state = State::DEAD;
	timer = 0;
}

Snake::Snake(Vector2 _position, int _length, Vector2 _forward, float _speed)
{
	headPosition = _position;
	length = _length + 1;
	forward = _forward;
	speed = _speed;
	positions = {};
	for (int i = 0; i < length; i++)
		positions.push_back(headPosition - (forward * i));
	state = State::ALIVE;
	timer = 0;
}

Snake::~Snake()
{
}

void Snake::Update(float dt)
{
	timer += dt;
	ProcessInputs ();
	if (timer > (1 / speed) && state == State::ALIVE)
	{
		lastMoveForward = forward;
		timer -= 1 / speed;
		MoveForward();
		CheckCollisionsHimself();
	}
}

void Snake::Draw()
{
	//DRAW HEAD
	DrawEngine::GetInstance().DrawAtPos('O', headPosition.x, headPosition.y, 2);

	//DRAW TAIL
	for (int i = 1; i < length - 1; i++)
	{
		//HORIZONTAL
		if ((positions[i - 1] == positions[i] + Vector2::Right() && 
			 positions[i + 1] == positions[i] - Vector2::Right()) || 
			(positions[i + 1] == positions[i] + Vector2::Right() &&
			 positions[i - 1] == positions[i] - Vector2::Right()))
		{
			DrawEngine::GetInstance().DrawAtPos(205, positions[i].x, positions[i].y, 2);
		}
		//VERTICAL
		else if ((positions[i - 1] == positions[i] + Vector2::Up() &&
				  positions[i + 1] == positions[i] - Vector2::Up()) ||
				 (positions[i + 1] == positions[i] + Vector2::Up() &&
				  positions[i - 1] == positions[i] - Vector2::Up()))
		{
			DrawEngine::GetInstance().DrawAtPos(186, positions[i].x, positions[i].y, 2);
		}
		//CORNERS UP LEFT
		else if ((positions[i - 1] == positions[i] + Vector2::Up() &&
				  positions[i + 1] == positions[i] + Vector2::Right()) ||
				 (positions[i + 1] == positions[i] + Vector2::Up() &&
				  positions[i - 1] == positions[i] + Vector2::Right()))
		{
			DrawEngine::GetInstance().DrawAtPos(201, positions[i].x, positions[i].y, 2);
		}
		//CORNERS UP Right
		else if ((positions[i - 1] == positions[i] + Vector2::Up() &&
				  positions[i + 1] == positions[i] - Vector2::Right()) ||
				 (positions[i + 1] == positions[i] + Vector2::Up() &&
				  positions[i - 1] == positions[i] - Vector2::Right()))
		{
			DrawEngine::GetInstance().DrawAtPos(187, positions[i].x, positions[i].y, 2);
		}
		//CORNERS DOWN LEFT
		else if ((positions[i - 1] == positions[i] - Vector2::Up() &&
				  positions[i + 1] == positions[i] + Vector2::Right()) ||
				 (positions[i + 1] == positions[i] - Vector2::Up() &&
				  positions[i - 1] == positions[i] + Vector2::Right()))
		{
			DrawEngine::GetInstance().DrawAtPos(200, positions[i].x, positions[i].y, 2);
		}
		//CORNERS DOWN Right
		else if ((positions[i - 1] == positions[i] - Vector2::Up() &&
				  positions[i + 1] == positions[i] - Vector2::Right()) ||
				 (positions[i + 1] == positions[i] - Vector2::Up() &&
				  positions[i - 1] == positions[i] - Vector2::Right()))
		{
			DrawEngine::GetInstance().DrawAtPos(188, positions[i].x, positions[i].y, 2);
		}
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

Vector2 Snake::GetHeadPosition()
{
	return headPosition;
}

vector<Vector2> Snake::GetPositions()
{
	return positions;
}

int Snake::GetLength()
{
	return length - 1;
}

void Snake::ProcessInputs()
{
	if (Input::GetInstance().GetKeyDown(VK_UP) && lastMoveForward != Vector2::Up())
		forward = -Vector2::Up();
	else if (Input::GetInstance().GetKeyDown(VK_DOWN) && lastMoveForward != -Vector2::Up())
		forward = Vector2::Up();
	else if (Input::GetInstance().GetKeyDown(VK_RIGHT) && lastMoveForward != -Vector2::Right())
		forward = Vector2::Right();
	else if (Input::GetInstance().GetKeyDown(VK_LEFT) && lastMoveForward != Vector2::Right())
		forward = -Vector2::Right();
}

void Snake::MoveForward()
{
	headPosition += forward;
	for (int i = length - 1; i > 0; i--)
		positions[i] = positions[i - 1];
	positions[0] = headPosition;
}

void Snake::CheckCollisionsHimself()
{
	for (int i = 1; i < length - 1; i++)
	{
		if (positions[i] == headPosition)
			state = State::DEAD;
	}
}
