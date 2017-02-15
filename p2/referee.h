//Referee.h
#include <string>
#include <SDL.h>

class Referee{
	public:
		Referee(SDL_Renderer* rend, const std::string& filename, float x, float y);
		SDL_Texture *getRef () const {return refTexture;}
		SDL_Rect getRect() const {return refRect;}
		~Referee()
			{SDL_DestroyTexture(refTexture);}

	private:
		SDL_Rect refRect;
		Referee(){}
		SDL_Texture *refTexture;
		void getTexture(SDL_Renderer*, const std::string&);
		Referee(const Referee&);
  		Referee& operator=(const Referee&);
};
