#pragma once
class IActor
{
protected:
	bool active;
public:
	IActor();
	~IActor();
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	bool IsActive();
	void SetActive(bool _active);
};

