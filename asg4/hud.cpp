#include "hud.h"
#include <sstream>

void HUD::draw()const{
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255/2);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	std::stringstream avstrm;
  	std::stringstream fpstrm;
  	std::stringstream elstrm;
  	std::stringstream infostrm;
  	std::stringstream info2strm;
  	std::stringstream info3strm;
  	fpstrm<< "Current FPS:"<< c.getFps(); 
 	avstrm<< "Average FPS:"<<c.getAvgFps();
 	elstrm<< "Elapsed Sec:"<<c.getSeconds();
 	infostrm<<"To move Trump:";
 	info2strm<<"A(left), D(right)";
 	info3strm<<"SPACE(jump), F1(show HUD)";
  	io.writeText(fpstrm.str(), 10, 10);
  	io.writeText(avstrm.str(), 10, 30);
  	io.writeText(elstrm.str(), 10, 50);
  	io.writeText(infostrm.str(), 10, 80);
  	io.writeText(info2strm.str(), 10, 100);
  	io.writeText(info3strm.str(), 10, 120);
}
