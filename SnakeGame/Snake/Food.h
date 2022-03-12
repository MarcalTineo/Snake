#pragma once
#include <IActor.h>
class Food : public IActor
{
	public:
	Food();
	~Food();

	// Inherited via IActor
	virtual void Update(float dt) override;
	virtual void Draw() override;
};

