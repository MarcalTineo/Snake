#include "IGame.h"

int IGame::GetSizeX()
{
	return SizeX;
}

int IGame::GetSizeY()
{
	return SizeY;
}

int IGame::GetDefultColor()
{
	return defaultColor;
}

IGame::IGame()
{
	isAlive = true;
}

IGame::~IGame()
{
}

bool IGame::IsAlive()
{
	return isAlive;
}

void IGame::Kill()
{
	isAlive = false;
}
