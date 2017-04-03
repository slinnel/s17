#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "sprite.h"
#include "multisprite.h"
#include "twowaymultisprite.h"
#include "gamedata.h"
#include "engine.h"
#include "frameGenerator.h"
#include "coin.h"

Engine::~Engine() { 
  std::cout << "Terminating program" << std::endl;
  for(auto &s: sprites){
    delete s;
  }
  for(auto &s: smallCoins)
  {
    delete s;
  }
  for(auto &s: medCoins)
  {
    delete s;
  }
  for(auto &s: largeCoins)
  {
    delete s;
  }

}

Engine::Engine() :
  rc( RenderContext::getInstance() ),
  io( IOmod::getInstance() ),
  clock( Clock::getInstance() ),
  renderer( rc->getRenderer() ),
  skyB("skyB", Gamedata::getInstance().getXmlInt("skyB/factor") ),
  grassB("grassB", Gamedata::getInstance().getXmlInt("grassB/factor") ),
  mtB("mtB", Gamedata::getInstance().getXmlInt("mtB/factor") ),
  viewport( Viewport::getInstance() ),
  sprites(),
  smallCoins(),
  medCoins(),
  largeCoins(),
  currentSprite(-1),
  makeVideo( false ),
  h("hud"),
  showHud(true),
  hudCounter(0),
  player( new Player("trump"))
{
  sprites.push_back(player);
  sprites.push_back( new TwoWayMultiSprite("runningcat"));
  for(int i = 0; i < 30; i++){
    auto *s = new Coin("coin");
    s->setScale(.35);
    s->scaleVelocity(.1);
    smallCoins.push_back(s);
  }
  for(int i = 0; i < 10; i++){
    auto *s = new Coin("coin");
    s->setScale(.75);
    s->scaleVelocity(.75);
    medCoins.push_back(s);
  }
  for(int i = 0; i < 10; i++){
    auto *s = new Coin("coin");
    s->setScale(1);
    s->scaleVelocity(1);
    largeCoins.push_back(s);
  }
  switchSprite();
  std::cout << "Loading complete" << std::endl;
}

void Engine::draw() const {
  skyB.draw();
  for(auto* s : smallCoins) s->draw();
  mtB.draw();
  for(auto* s : medCoins) s->draw();
  grassB.draw();
  for(auto* s : largeCoins) s->draw();
  std::stringstream strm;
  std::stringstream nstrm;
  nstrm << Gamedata::getInstance().getXmlStr("myName");
  strm << Gamedata::getInstance().getXmlStr("title");
  io.writeText(nstrm.str(),{255,0,0,0}, 5, 450);
  io.writeText(strm.str(), 5, 430);
  
  for(auto* s : sprites) s->draw();
  if(showHud)
    h.draw();
  viewport.draw();
  SDL_RenderPresent(renderer);
}

void Engine::update(Uint32 ticks) {
  for(auto* s : sprites) s->update(ticks);
  for(auto* s : smallCoins) s->update(ticks);
  for(auto* s : medCoins) s->update(ticks);
  for(auto* s : largeCoins) s->update(ticks);
  skyB.update();
  mtB.update();
  grassB.update();
  viewport.update(); // always update viewport last
}

void Engine::switchSprite(){
  ++currentSprite;
  currentSprite = currentSprite % sprites.size();
  Viewport::getInstance().setObjectToTrack(sprites[currentSprite]);
}

void Engine::play() {
  SDL_Event event;
  const Uint8* keystate;
  bool done = false;
  Uint32 ticks = clock.getElapsedTicks();
  FrameGenerator frameGen;

  while ( !done ) {
    while ( SDL_PollEvent(&event) ) {
      keystate = SDL_GetKeyboardState(NULL);
      if (event.type ==  SDL_QUIT) { done = true; break; }
      if(event.type == SDL_KEYDOWN) {
        if (keystate[SDL_SCANCODE_ESCAPE] || keystate[SDL_SCANCODE_Q]) {
          done = true;
          break;
        }
        if ( keystate[SDL_SCANCODE_P] ) {
          if ( clock.isPaused() ) clock.unpause();
          else clock.pause();
        }
        if(keystate[SDL_SCANCODE_F1]){
          showHud=true;
          hudCounter=0;
        }

        if ( keystate[SDL_SCANCODE_T] ) {
          switchSprite();
        }
        if (keystate[SDL_SCANCODE_F4] && !makeVideo) {
          std::cout << "Initiating frame capture" << std::endl;
          makeVideo = true;
        }
        else if (keystate[SDL_SCANCODE_F4] && makeVideo) {
          std::cout << "Terminating frame capture" << std::endl;
          makeVideo = false;
        }
      }
    }

    if(keystate[SDL_SCANCODE_A] && keystate[SDL_SCANCODE_D]){
        player->stop();
    }
    else if(keystate[SDL_SCANCODE_A]){
        player->left();
    }
    else if(keystate[SDL_SCANCODE_D]){
        player->right();
    }
    if(keystate[SDL_SCANCODE_SPACE]){
      player->jump();
    }

    ticks = clock.getElapsedTicks();
    if ( ticks > 0 ) {
      clock.incrFrame();
      hudCounter++;
      if(hudCounter == 300)
        showHud=false;
      draw();

      update(ticks);
      if ( makeVideo ) {
        frameGen.makeFrame();
      }
    }
  }
}
