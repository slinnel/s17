//Background.cpp 

#include <iostream>
#include <string>
#include "background.h"
#include <SDL_image.h>
/*
Background::Background(SDL_Renderer* rend, const std::string& filename){
  getTexture(rend, filename);
}
*/
SDL_Texture *Background::getTexture(SDL_Renderer* rend, const std::string& filename) {
  try {
    SDL_Texture *bTexture = IMG_LoadTexture(rend, filename.c_str());
    if ( backgroundTexture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
    return bTexture;
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
