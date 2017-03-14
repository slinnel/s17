//randomGOF
#include <cstdlib>
#include <iostream>

// class Random{
// 	public:
// 		static Random *getInstance(){
// 			if(!instance)
// 				instance = new Random();
// 			return instance;
// 		}
// 		int operator()(int a, int b){
// 			return (rand() %b)+a;
// 		}
// 	private:
// 		static Random *instance;
// 		Random(){
// 			int seed = time(0);
// 			srand(seed);
// 		}
// 		Random(const Random&);
// 		Random& operator=(const Random&);
// };
// Random * Random::instance = NULL;

// int main(){
// 	Random * random = Random::getInstance();
// 	std::cout<<(*random)(1,100)<<std::endl;
// }
class Random{
	public:
		static Random &getInstance();
		int operator()(int a, int b){
			return (rand() %b)+a;
		}
	private:
		Random(){
			int seed = time(0);
			srand(seed);
		}
		Random(const Random&);
		Random& operator=(const Random&);
};
Random &Random::getInstance(){
	static Random instance;
	return instance;
}

int main(){
	Random & random = Random::getInstance();
	std::cout<<random(1,100)<<std::endl;
}