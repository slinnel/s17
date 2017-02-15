//Banner.h
#ifndef BANNER_H
#define BANNER_H 
#include <string>
#include <SDL.h>
#include <iostream>
#include "clock.h"

class Banner{
	public:
		Banner(SDL_Renderer* rend, const std::string& filename, float x, float y, int vel);
		SDL_Texture *getBan () const {return bannerTexture;}
		SDL_Rect getRect() const {return bannerRect;}
		void updateBanner(Clock &);
		~Banner(){SDL_DestroyTexture(bannerTexture);}

	private:
		float xPos;	//x position on the screen
		int xVel;	//defined speed it travels
		SDL_Rect bannerRect;	
		Banner(){}	//disallow compiler generated
		SDL_Texture *bannerTexture;
		void getTexture(SDL_Renderer*, const std::string&);
		Banner(const Banner&);
  		Banner& operator=(const Banner&);
};
#endif
