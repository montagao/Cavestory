#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "global.h"

class Graphics;

/* AnimatedSprite class
Holds logic for animating sprites
*/

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string& filePath, int sourceX, int sourceY,
		int width, int height, float posX, float posY, float timeToUpdate);
	void playAnimation(std::string animation, bool once = false);

	/* void update
		Updates the animated sprite (timer	
	*/
	void update(int elapsedTime);

	/* void draw
		Draws the sprite to the screen
	*/
	void draw(Graphics &graphics, int x, int y);

	virtual void setupAnimations();

	/* void setupAnimations
		A required fucntion that sets up all animations for a sprite	
	*/
protected:
	double  _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void addAnimation
		Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height,Vector2 offset);

	/* void resetAnimations
		Resets all animations associated with this sprite
	*/
	void resetAnimations();

	/* void stopAnimation
		stops animation
	*/
	void stopAnimation();

	/* void setVisible
		Changes the visibility of the animated sprite
	*/
	void setVisibile(bool visibile);

	/* void animationDone
		Logic that happens when animation ends
	*/
	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;


};

#endif