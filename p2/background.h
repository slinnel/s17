// Background.h
#include <string>
#include <SDL.h>

class Background{
	public:
		Background(SDL_Renderer*, const std::string&);
		SDL_Texture *getBG () const {return backgroundTexture;}
		~Background()
			{SDL_DestroyTexture(backgroundTexture);}
	private:
		Background();
		SDL_Texture *backgroundTexture;
		void getTexture(SDL_Renderer*, const std::string&);
};
