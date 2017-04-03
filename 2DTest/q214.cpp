//q2 2014
#include <iostream>

class B{
	public:
		B():number(0){}
	private:
		int number;
};

class A{
	public:
		A(): m(17), n(1), b(new B){}
		int getM() const{return m;}
		~A(){delete b;}
	private:
		int m,n;
		B *b;
		A(const A&);
		A& operator=(const A&);
};

	int main(){
		A* a = new A;
		std::cout<<a->getM()<<std::endl;
		delete a;
}
