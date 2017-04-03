#include <iostream>
//#GOF
class Number{
	public:
		static Number &getInstance();
		void updateNumber(int n){
			number = n;
		}
		int getNumber(){
			return number;
		}
	private:
		Number(){}
		int number;
}; 
Number &Number::getInstance(){
	static Number instance;
	return instance;
}

int main(){
	Number &n = Number::getInstance();
	n.updateNumber(5);
	std::cout<<n.getNumber()<<std::endl;
	n.updateNumber(69);
	std::cout<<Number::getInstance().getNumber()<<std::endl;
}