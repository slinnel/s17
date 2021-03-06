// Background.h
#include <string>
#include <SDL.h>

class Background{
	public:
		Background(SDL_Renderer* rend, const std::string& name);
		SDL_Texture *getBG () const {return backgroundTexture;}
		~Background()
			{SDL_DestroyTexture(backgroundTexture);}
	private:
		Background();
		Background(const Background&);
		Background &operator=(const Background&);
		SDL_Texture *backgroundTexture;
		void getTexture(SDL_Renderer*, const std::string&);
};
