#ifndef TWOWAYMULTISPRITE__H
#define TWOWAYMULTISPRITE__H

#include <string>
#include <vector>
#include <cmath>
#include "multisprite.h"
#include "gamedata.h"

class TwoWayMultiSprite : public MultiSprite {
public:
  TwoWayMultiSprite(const std::string& name): MultiSprite(name), isFlipped(false){}
  TwoWayMultiSprite(const MultiSprite& ms): MultiSprite(ms), isFlipped(false){}

  virtual void update(Uint32 ticks);
protected:
  bool isFlipped;
  void advanceFrame(Uint32 ticks);
};
#endif