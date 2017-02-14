#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "background.h"
#include <SDL_image.h>

Background::Background(SDL_Renderer* rend, const std::string& filename){
  backgroundTexture=getTexture(rend, filename);
}

SDL_Texture* Background::getTexture(SDL_Renderer* rend, const std::string& filename) {
  try {
    SDL_Texture *texture = IMG_LoadTexture(rend, filename.c_str());
    if ( texture == NULL ) {
      throw std::string("Couldn't load ") + filename;
    }
    return texture;
  }
  catch( const std::string& msg ) { 
    std::cout << msg << std::endl; 
    std::terminate();
  }
}
