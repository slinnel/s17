//Football.cpps
#include "football.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <SDL_image.h>
#include <vector>
#include <SDL.h>

inline float clamp(const float val, const float lo, const float hi){
  return val <= lo ? lo : ( val >= hi ? hi : val);
}
//updates the position of the football on the window
void Football::updateFootball(SDL_Renderer *rend, Clock &gameClock,
       std::pair<int, int> windowSize){

  int WIDTH = windowSize.first;
  int HEIGHT = windowSize.second;
  unsigned int DT = gameClock.getDT();

  float dx = xVEL * DT * 0.001;
  fakeXPos+= dx;

  if(fakeXPos < 550){
    float prevY = yPos;
    float dy = sqrt((350*350)-((fakeXPos-350)*(fakeXPos-350)));
    yPos = dy;
    yPos = HEIGHT - yPos;
    if(yPos-prevY < 0)
      xPos+=.3;
    else
      xPos-=.5;
  }
  else
    stillFlipping = false;

  xPos = clamp(xPos,0.f,WIDTH-dstrect.w);
  yPos = clamp(yPos,0.f,HEIGHT-dstrect.h);
  dstrect.x = xPos;
  dstrect.y = yPos;

  if(stillFlipping){  //continues to flip the sprite.
    if(flipCounter % 30 < 10)
       getTexture(rend, fileNames[0]);
     else if(flipCounter % 30 < 20)
       getTexture(rend, fileNames[1]);
     else
       getTexture(rend, fileNames[2]);
       
     flipCounter++;
     if(flipCounter % 7 == 0)
     {
      dstrect.h --;
      dstrect.w --;
     }
  }
}
//Constructor
Football::Football(std::vector<std::string> &fNs, SDL_Renderer *rend, float startX,
   float startY, int vel): xPos(startX), yPos(startY), xVEL(vel), flipCounter(0),
      fakeXPos(0), fileNames(fNs), stillFlipping(true){
      getTexture(rend, fileNames.front());
      dstrect.x = xPos;
      dstrect.y = yPos;
      dstrect.h = 35;
      dstrect.w = 35; 
}
//returns the SDL_Texture of the football
void Football::getTexture(SDL_Renderer* rend, const std::string& filename) {
  SDL_DestroyTexture(fbTexture);
  try {
    fbTexture = IMG_LoadTexture(rend, filename.c_str());
    if ( fbTexture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
