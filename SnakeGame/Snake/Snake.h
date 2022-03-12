#pragma once
#include <IActor.h>
#include <Vector2.h>
#include <vector>
#include <Input.h>
#include <DrawEngine.h>


class Snake : public IActor
{
public:
	enum State
	{
		ALIVE, DEAD
	};
private:
	State state;
	Vector2 headPosition;
	int length;
	Vector2 forward;
	std::vector<Vector2> positions;
	float timer;
	float speed;

public:
	

	Snake();
	Snake(Vector2 _position, 
		  int _length, 
		  Vector2 _forward, 
		  float _speed);
	~Snake();

	// Inherited via IActor
	virtual void Update(float dt) override;
	virtual void Draw() override;

	State GetState();
	void SetState(State newState);

	void AddOneLength();


private:
	void ProcessInputs();
	void MoveForward();
	void CheckCollisions();
	void CheckCollisionsBody();
};

