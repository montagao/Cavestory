#include "input.h"

/* Input class
	Keeps track of keyboard state
*/


// this functions gets called at the beginning of each 
// frame to reset keys that are no longer relevant.
void Input::beginNewFrame()
{
	_pressedKeys.clear();
	_releasedKeys.clear();
}

// this gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event)
{
	_pressedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = true;
}

// this gets called when a key is released
void Input::keyUpEvent(const SDL_Event& event)
{
	_releasedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = false;
}

// check if a certain key was pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key) 
{
	return _pressedKeys[key];
}

// check if a certain key was released during the current frame
bool Input::wasKeyReleased(SDL_Scancode key) 
{
	return _releasedKeys[key];
}

// check if a certain key is still held during the current frame
bool Input::isKeyHeld(SDL_Scancode key) 
{
	return _heldKeys[key];
}