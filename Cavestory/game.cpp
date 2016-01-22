#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

#include <algorithm>

/*
	Game class
	This class holds all information for our main game loop.
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::draw(Graphics &graphics) {
	graphics.clear();

	_player.draw(graphics, 100, 100);

	graphics.flip();

}

void Game::update(float elapsedtime) {
	_player.update(elapsedtime);

}

void Game::gameLoop(){
	Graphics graphics;
	Input input;
	SDL_Event event;

	_player = AnimatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16,100,100, 100 );
	_player.setupAnimations();
	_player.playAnimation("runLeft");


	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}		
			else if (event.type = SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT){
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		// ensures movement across slower computers is the same
		// and limits fps properly

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics);
	}
}

