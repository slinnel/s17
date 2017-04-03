#include "coin.h"
#include "gamedata.h"

void Coin::randomizeV(){
  setVelocityY(getVelocityY()+Gamedata::getInstance().getRandInRange(-10, 50));
  setVelocityX((getVelocityX()+Gamedata::getInstance().getRandInRange(-10, 50))*Gamedata::getInstance().getRandInRange(-1, 1));
  float newx = Gamedata::getInstance().getRandInRange(0, Gamedata::getInstance().getXmlInt("world/width"));
  startingPos[0] = newx;
  setX(newx);
}

void Coin::update(Uint32 ticks) { 
  advanceFrame(ticks);

  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( getY() < 0) {
    setPosition(startingPos);
  }
  if ( getY() > worldHeight-frameHeight) {
    setPosition(startingPos);
  }
  if ( getX() < 0) {
    setPosition(startingPos);
  }
  if ( getX() > worldWidth-frameWidth) {
    setPosition(startingPos);
  }  

}
void Coin::scaleVelocity(const float scale){
  setVelocityX(getVelocityX()*scale);
  setVelocityY(getVelocityY()*scale);
}


void Coin::advanceFrame(Uint32 ticks) {
	
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