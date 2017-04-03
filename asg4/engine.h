#include <vector>
#include <SDL.h>
#include "ioMod.h"
#include "renderContext.h"
#include "clock.h"
#include "world.h"
#include "viewport.h"
#include "player.h"
#include "hud.h"
class Engine {
public:
  Engine ();
  ~Engine ();
  void play();
  void switchSprite();

  Engine(const Engine&)=delete;
  Engine& operator=(const Engine&)=delete;
private:
  const RenderContext* rc;
  const IOmod& io;
  Clock& clock;

  SDL_Renderer * const renderer;
  World skyB;
  World grassB;
  World mtB;
  Viewport& viewport;

  std::vector<Drawable*> sprites;
  std::vector<Drawable*> smallCoins;
  std::vector<Drawable*> medCoins;
  std::vector<Drawable*> largeCoins;


  int currentSprite;
  bool makeVideo;
  HUD h;
  bool showHud;
  int hudCounter;
  Player *player;

  void draw() const;
  void update(Uint32);

  
};
