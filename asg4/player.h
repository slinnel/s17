#ifndef PLAYER__H
#define PLAYER__H

#include "twowaymultisprite.h"
#include "gamedata.h"

class Player : public TwoWayMultiSprite{
	public:
  		Player(const std::string& name): 
  			TwoWayMultiSprite(name), initialVel(velocity), ground(position[1]), 
  				jumpSpeed(Gamedata::getInstance().getXmlFloat(name+"/jumpSpeed")), keyPressedX(false), keyPressedSPACE(false){}
		Player(const MultiSprite& ms): 
			TwoWayMultiSprite(ms), initialVel(velocity), ground(position[1]),
  				jumpSpeed(Gamedata::getInstance().getXmlFloat(name+"/jumpSpeed")), keyPressedX(false), keyPressedSPACE(false){}

  		Player(const Player& t): 
			TwoWayMultiSprite(t.name), initialVel(t.initialVel), ground(t.ground),
  				jumpSpeed(Gamedata::getInstance().getXmlFloat(name+"/jumpSpeed")), keyPressedX(false), keyPressedSPACE(false){}
  		virtual void update(Uint32 ticks);
  		void stop();
  		void left();
  		void right();
  		void jump();
  		
  	private:
  		void advanceFrame(Uint32 ticks);
  		Vector2f initialVel;
  		float ground;
  		float jumpSpeed;


      Player& operator=(const Player&);

  	protected:
  		bool keyPressedX;
  		bool keyPressedSPACE;
};
#endif
