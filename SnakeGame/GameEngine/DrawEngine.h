#pragma once
#include <iostream>
#include "windows.h"
#include "Helpers.h"

class DrawEngine
{
protected:
	int sizeX;
	int sizeY;

	HANDLE hConsole;

	int defaultColor;
	char* viewport;
	char* viewportColors;

public:
	static DrawEngine& GetInstance()
	{
		static DrawEngine instance;
		return instance;
	}
	

	DrawEngine() {};
	~DrawEngine();

	void SetDrawEngine(int x, int y, int defaultColor);
private:
	void ShowConsoleCursor(bool showFlag);
public:
	void DrawAtPos(char c, int x, int y);
	void DrawAtPos(char c, int x, int y, int color);

	void Write(char* text, int lenght, int x, int y);
	void Write(char* text, int lenght, int x, int y, int color);

	void Flush();

	void InitViewport();

	void SetCursorPosition(int x, int y);

	void Clear();

};

