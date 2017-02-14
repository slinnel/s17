#include <string>
#include <SDL.h>
#include "Clock.h"

class Football{
	public:
		Football(string[] fileName, SDL_Renderer *rend, float startX, float startY): 
			fileNames(new string[3]), rend(), startingX(startX), startingY(startY), 
			xPos(startX), yPos(startY), fakeXPos(startX);

		~Football();
		
	private:
		float startingX;
		float startingY
		float xPos;
		float yPos;
		float fakeXPos;

		SDL_Texture* fbTexture;
		SDL_Rect dstrect = {X_POS, Y_POS, 32, 32};
		SDL_Texture* getTexture(SDL_Renderer*, const std::string&);
};

