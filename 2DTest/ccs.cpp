// //clock class singleton
// //GoF
// #include <iostream>
// class Clock{
// public:
// 	static Clock *getInstance(){
// 		if(!instance){instance =new Clock();}
// 		return instance;
// 	}
// 	int getTicks() const {return ticks;}
// 	void update() {++ticks;}
// private:
// 	Clock() : ticks(0){}
// 	static Clock *instance;
// 	int ticks;
// };
// Clock *Clock::instance = NULL;

// int main(){
// 	Clock *clock = Clock::getInstance();
// 	clock->update();
// 	clock->update();
// 	clock->update();
// 	clock->update();
// 	clock->update();
// 	std::cout<<Clock::getInstance()->getTicks()<<std::endl;
// }


// //clock class singleton
// #include <iostream>
// class Clock{
// public:
// 	static Clock &getInstance();
// 	int getTicks() const {return ticks;}
// 	void update() {++ticks;}
// private:
// 	int ticks;
// };
// Clock & Clock::getInstance(){
// 	static Clock instance;
// 	return instance;
// }

// int main(){
// 	Clock &clock = Clock::getInstance();
// 	clock.update();
// 	clock.update();
// 	clock.update();
// 	std::cout<<clock.getTicks()<<std::endl;
// }







