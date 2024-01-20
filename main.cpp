#include "game.h"

#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	bool initial = true;

	SDL_Surface* boardSurface = NULL;

	std::unique_ptr<Game> game = std::make_unique<Game>();

	game->init("Mateusz Wieczorek -> Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		// Only if user did something, update() and then render()
		if (game->handleEvents() || initial)
		{
			game->update();
			game->render();
			initial = false;
		}

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	// After 3 seconds close the game
	std::this_thread::sleep_for(std::chrono::seconds(3));
	game->clean();
	return 0;
}