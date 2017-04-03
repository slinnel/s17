#include <iostream>
//#GOF
class Number{
	public:
		static Number *getInstance(){
			if(!instance){instance = new Number();}
			return instance;
		}
		void updateNumber(int n){
			number = n;
		}
		int getNumber(){
			return number;
		}
	private:
		static Number *instance;
		int number;
}; 
Number *Number::instance = NULL;

int main(){
	Number *n = Number::getInstance();
	n->updateNumber(5);
	std::cout<<n->getNumber()<<std::endl;
	Number::getInstance()->updateNumber(69);
	std::cout<<n->getNumber()<<std::endl;
}
