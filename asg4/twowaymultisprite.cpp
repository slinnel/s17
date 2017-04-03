#include "twowaymultisprite.h"

void TwoWayMultiSprite::update(Uint32 ticks) { 
  advanceFrame(ticks);

  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( getY() < 0) {
    setVelocityY( fabs( getVelocityY() ) );
  }
  if ( getY() > worldHeight-frameHeight) {
    setVelocityY( -fabs( getVelocityY() ) );
  }

  if ( getX() < 200) {
    setVelocityX( fabs( getVelocityX() ) );
    isFlipped = false;
  }
  if ( getX() > worldWidth-frameWidth) {
    setVelocityX( -fabs( getVelocityX() ) );
    isFlipped = true;
  }  

}

void TwoWayMultiSprite::advanceFrame(Uint32 ticks) {
	
	timeSinceLastFrame += ticks;
	if (timeSinceLastFrame > frameInterval) {
		
		if(isFlipped){
			currentFrame = ((currentFrame - 1) % (numberOfFrames/2)) + (numberOfFrames/2); 
		}
		else	
    		currentFrame = (currentFrame+1) % (numberOfFrames/2);

			timeSinceLastFrame = 0;
	}
}