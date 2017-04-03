#include <iostream>
class Bird{
public:
	Bird(int w): wingSpan(w), speed(2*wingSpan){
		std::cout<<"Speed: "<<speed<<std::endl;
		std::cout<<"Wingspan: "<<wingSpan<<std::endl;
	}
private:
	int wingSpan;
		int speed;

};

int main(){
	Bird robin(27);
}