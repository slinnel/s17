#ifndef SPRITE__H
#define SPRITE__H
#include <string>
#include "drawable.h"

class Sprite : public Drawable {
public:
  Sprite(const std::string&);
  Sprite(const Sprite&);
  virtual ~Sprite() { } 
  Sprite& operator=(const Sprite&);

  virtual const Frame* getFrame() const { return frame; }
  virtual void draw() const;
  virtual void update(Uint32 ticks);
  void  setScale(float s){ scale = s; }
  inline float getScale()const{ return scale; }
  
private:
  const Frame * frame;
  int worldWidth;
  int worldHeight;
  float scale;
  int frameWidth;
  int frameHeight;
  int getDistance(const Sprite*) const;
};
#endif
