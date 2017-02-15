//Background.cpp 

#include <iostream>
#include <string>
#include "background.h"
#include <SDL_image.h>

Background::Background(SDL_Renderer* rend, const std::string& filename){
  getTexture(rend, filename);
}

void Background::getTexture(SDL_Renderer* rend, const std::string& filename) {
  SDL_DestroyTexture(backgroundTexture);
  try {
     backgroundTexture = IMG_LoadTexture(rend, filename.c_str());
    if ( backgroundTexture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
