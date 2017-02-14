#include <string>
#include <SDL.h>
#include "Clock.h"

class Football{
	public:
		Football(string[] fileName, SDL_Renderer *rend): fileNames(new string[3]);
		~Football();
		
