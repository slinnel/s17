#include <SDL.h>

class Clock{
	public:
		Clock():rem(0u), prevTicks(SDL_GetTicks())
			,currentTicks(SDL_GetTicks()), elapsedTicks(currentTicks - prevTicks + rem){}

		bool updateClock();
		unsigned int getDT() const{return DT;}
		//updates clock and returns true if time elapsed > DT
	private:
		
		 unsigned int rem;
		 unsigned int prevTicks;
         unsigned int currentTicks;
         unsigned int elapsedTicks;
         const static unsigned int DT = 17u; 
};
