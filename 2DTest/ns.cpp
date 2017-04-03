#include <iostream>

class Nikki{
public:
	static Nikki &getInstance();
	int getAge()const{return age;}
private:
	int age;
	Nikki():age(22){}
	Nikki(const Nikki&);
	Nikki& operator=(const Nikki&);
};
Nikki &Nikki::getInstance(){
	static Nikki instance;
	return instance;
}

int main(){
	Nikki &n = Nikki::getInstance();
	std::cout<<n.getAge()<<std::endl;
	std::cout<<Nikki::getInstance().getAge()<<std::endl;
}