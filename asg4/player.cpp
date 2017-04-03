#include "player.h"

void Player::update(Uint32 ticks) { 
  advanceFrame(ticks);
  setVelocityY(getVelocityY()+10);

  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( getX() <= 0) {
    setVelocityX(0);
    setX(0);
  }

  if ( getX() >= worldWidth - frameWidth) {
    setVelocityX(0);
    setX(worldWidth - frameWidth);
  }  
  if(getY()>=ground){
    setVelocityY(0);
    setY(ground);
  }
  if(getVelocityX() > 0 ) isFlipped = false;
  if(getVelocityX() < 0 ) isFlipped = true;  
  if(!keyPressedSPACE) stop();
  if(!keyPressedX) stop();
  keyPressedX = false;
  keyPressedSPACE = false;
}
void Player::advanceFrame(Uint32 ticks) {
  if(fabs(getVelocityX()) > 0){
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
}

void Player::stop(){
  setVelocityX(0);
}

void Player::right(){
  keyPressedX = true;
  if(keyPressedX){
    setVelocityX(-initialVel[0]);
  }
}
void Player::left(){
  keyPressedX = true;
  if(keyPressedX){
      setVelocityX(initialVel[0]);
    
  }
}
void Player::jump(){
  keyPressedSPACE = true;
  if(keyPressedSPACE){
    if(getY() >= ground){
      setVelocityY(-jumpSpeed);
    }
  }
}

