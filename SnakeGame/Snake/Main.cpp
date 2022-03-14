#include <Engine.h>
#include "SnakeGame.h"


int main()
{
	Engine* engine = new Engine(new SnakeGame(), 60);
}
