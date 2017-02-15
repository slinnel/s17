//Clock.cpp
#include "clock.h"
#include <SDL.h>
//Updates the gameclock
//RETURNS TRUE: If time elapsed is > DT
//FALSE OTHERWISE
bool Clock::updateClock(){
	currentTicks = SDL_GetTicks();
	elapsedTicks = currentTicks - prevTicks + rem;

	if(elapsedTicks < DT)
		return false;
	prevTicks = currentTicks;
  	rem = elapsedTicks - DT; 
  	return true;
}
