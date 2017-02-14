#include "clock.h"
#include <SDL.h>

bool Clock::updateClock(){
	currentTicks = SDL_GetTicks();
	elapsedTicks = currentTicks - prevTicks + rem;

	if(elapsedTicks < DT)
		return false;
	prevTicks = currentTicks;
  	remainder = elapsedTicks - DT; 

  	return true;
}
