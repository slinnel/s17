#include <iostream>

// class Chase{
// public:
// 	static Chase *getInstance(){
// 		if(!instance)
// 			instance = new Chase();
// 		return instance;
// 	}
// 	int getAge() const{return age;}
// private:
// 	Chase(){
// 		age = 22;
// 	}
// 	static Chase* instance;
// 	int age;
// };
// Chase * Chase::instance = NULL;

// int main(){
// 	std::cout<<"this is a gof singleton"<<std::endl;
// 	Chase *caconkl = Chase::getInstance();
// 	std::cout<<caconkl->getAge()<<std::endl;
// 	std::cout<<Chase::getInstance()->getAge()<<std::endl;

// 	return 0;
// }

class Chase{
public:
	static Chase &getInstance();
	int getAge() const{return age;}
private:
	Chase(){
		age = 22;
	}
	int age;
};
Chase &Chase::getInstance(){
	static Chase c;
	return c;
}

int main(){
	std::cout<<"this is a meyer's singleton"<<std::endl;
	Chase caconkl = Chase::getInstance();
	std::cout<<caconkl.getAge()<<std::endl;
	std::cout<<Chase::getInstance().getAge()<<std::endl;

	return 0;
}