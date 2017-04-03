#ifndef COIN__H
#define COIN__H

#include "twowaymultisprite.h"

class Coin : public TwoWayMultiSprite{
	public:
  		Coin(const std::string& name): TwoWayMultiSprite(name),
  		startingPos(Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"),
  			Gamedata::getInstance().getXmlInt(name+"/startLoc/y")))
  			{randomizeV();}
		Coin(const Coin& ms): TwoWayMultiSprite(ms),
		startingPos(Vector2f(Gamedata::getInstance().getXmlInt(name+"/startLoc/x"),
  			Gamedata::getInstance().getXmlInt(name+"/startLoc/y")))
  		{randomizeV();}
  	void scaleVelocity(const float scale);
    virtual void update(Uint32 ticks);
  	
    private:
  		void advanceFrame(Uint32 ticks);
  		void randomizeV();
		  Vector2f startingPos;
};
#endif
