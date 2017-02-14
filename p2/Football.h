#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "frameGenerator.h"
#include "clock.h"

class Football{
	public:
		Football(std::vector<std::string>&, SDL_Renderer*, float, float, std::pair<int, int>);
		void updateFootball(Clock &, bool, FrameGenerator &, std::pair<int, int>){
		~Football(){SDL_DestroyTexture(fbTexture);}
		
	private:
		int startingX;
		int startingY;
		float xPos;
		float yPos;
		float fakeXPos;
		SDL_Rect dstrect;
		std::vector<std::string> fileNames;
		SDL_Texture* fbTexture;
		SDL_Texture* getTexture(SDL_Renderer*, const std::string&);
};

