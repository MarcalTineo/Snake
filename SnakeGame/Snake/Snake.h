#pragma once
#include <IActor.h>
#include <Vector2.h>
#include <vector>
#include <Input.h>
#include <DrawEngine.h>
#include <string>;

using namespace std;

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
	Vector2 lastMoveForward;
	vector<Vector2> positions; //last position is virtual, it only exist to let the actual last piece draw correctly
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
	Vector2 GetHeadPosition();

	vector<Vector2> GetPositions();
	int GetLength();

private:
	void ProcessInputs();
	void MoveForward();
	void CheckCollisionsHimself();
};


