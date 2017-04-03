#ifndef HUD__H
#define HUD__H
#include "drawable.h"
#include "renderContext.h"
#include <string>
#include "ioMod.h"
#include "clock.h"
class HUD{
public:
	HUD(const std::string& n):
		name(n),
		renderer(RenderContext::getInstance()->getRenderer()),
		rect({Gamedata::getInstance().getXmlInt(n+"/rectX"),
			Gamedata::getInstance().getXmlInt(n+"/rectY"),
			Gamedata::getInstance().getXmlInt(n+"/rectW"),
			Gamedata::getInstance().getXmlInt(n+"/rectH")}),
		io(IOmod::getInstance()),
		c(Clock::getInstance())

	{}
	HUD(const HUD& h):
		name(h.name),
		renderer(RenderContext::getInstance()->getRenderer()),
		rect({Gamedata::getInstance().getXmlInt(h.name+"/rectX"),
			Gamedata::getInstance().getXmlInt(h.name+"/rectY"),
			Gamedata::getInstance().getXmlInt(h.name+"/rectW"),
			Gamedata::getInstance().getXmlInt(h.name+"/rectH")}),
		io(IOmod::getInstance()),
		c(Clock::getInstance())
	{}
	virtual void draw() const;
	~HUD(){}
private:
	string name;
	SDL_Renderer * const renderer;
	SDL_Rect rect;
	IOmod &io;
	Clock &c;

	HUD(const HUD&);
  	HUD& operator=(const HUD&);
};

#endif