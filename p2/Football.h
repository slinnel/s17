//Football.h
#ifndef FOOTBALL_H
#define FOOTBALL_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "clock.h"

class Football{
	public:
		Football(std::vector<std::string>&, SDL_Renderer*, float, float, int);
		void updateFootball(SDL_Renderer *, Clock &, std::pair<int, int>);
		SDL_Texture *getFB () const {return fbTexture;}
		SDL_Rect getRect() const {return dstrect;}
		~Football()
			{SDL_DestroyTexture(fbTexture);}
		bool isMoving() const {return stillFlipping;}
		
	private:
		float xPos;	//xPosition on the window
		float yPos;	//yPosition on the window
		int xVEL;	//defined velocity
		int flipCounter;	//counting how many times the ball turns
		float fakeXPos;		//"fake" position if the ball was traveling more on x
		SDL_Rect dstrect;	
		std::vector<std::string> fileNames;	//vector of the file names for sprites
		bool stillFlipping;	//TRUE, if ball is still turning, false if ball is not moving
		SDL_Texture* fbTexture;
		void getTexture(SDL_Renderer*, const std::string&);
		Football(const Football&);
  		Football& operator=(const Football&);
};
#endif
