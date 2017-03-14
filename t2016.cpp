// #include <iostream> 
// #include <vector> 
// const int MAX = 2;

// class Number { 
// public:
// 	Number() : number(69) { std::cout << "default" <<std::endl; } 
// 	explicit Number( int n) : number(n) { std::cout << "convert: " << n << std::endl; }
// 	Number(const Number& a) : number(a.number) { std::cout << "copy: " << a.number << std::endl;}
// 	Number& operator=(const Number& rhs ) {
// 		number = rhs.number;
// 		std::cout << "assign" << std::endl; 
// 		return *this ;
// 	}
// 	~Number(){
// 		std::cout<<"destroy"<<number<<std::endl;
// 	}
// 	int getNumber() const { return number; } 
// private:
// 	int number; 
// };
	
// void print(const std::vector<Number> & vec) {
// 	for (unsigned int i = 0; i < vec.size(); ++i) {
// 		std::cout << vec[i].getNumber() << ", "; 
// 	}
// 		std::cout << std::endl; 
// }

// void init(std::vector<Number> & vec) {
// 	for (unsigned int i = 0; i <MAX; ++i) {
// 		vec.emplace_back(i+1); 
// 	}
// }

// int main() {
// 	std::vector<Number> vec(3);
// 	vec.reserve(MAX);
// 	init(vec);
// 	vec.push_back( Number(99) );
// 	std::cout << "SIZE: " << vec.size() << std::endl; std::cout << "CAP: " << vec.capacity() << std::endl; print(vec);
// }

// #include <iostream>
// class Number {
// public:
// 	Number(int n) : number(n){}
// 	int getNumber() const {return number;}
	
// private:
// 	int number;
// 	Number& operator=(const Number&);
// 	Number(const Number&);
// };
// 	std::ostream& operator<<(std::ostream &out,const Number &n){
// 		return out << n.getNumber();
// 	}
// int main(){
// 	Number number(17);
// 	std::cout<<number;
// 	// number.operator<<(std::cout);
// }
#include <iostream>
#include <cstring>
#include <string>
class A{
public:
	A(const std::string &n):name(n){}
	virtual ~A(){std::cout<<"base"<<std::endl;}
	void test(){std::cout<<"im in the base class"<<std::endl;}
	virtual void f() {std::cout <<"A::f()"<<std::endl;}
	void g() {std::cout<<"A::g()"<<std::endl;}
private:
	std::string name;
};
class B : public A { 
public:
	B( const std::string& n, const char* t) : A(n),
	title(new char[strlen(t)+1]) { strcpy(title , t);}
 	~B() { delete [] title; std::cout << "derived" << std::endl; } 
 	void test(){std::cout<<"im in the derived class"<<std::endl;}
 	void f() { std::cout << "B::f()" << std::endl; }
	void g() { std::cout << "B::g()" << std::endl; }
private:
	char* title;
};
int main() {
	B* x = new B("Thane", "Whiterun"); 
	x->test();
	x->f();
	x->g();
	delete x; 
}
// #include <iostream>
// #include <cstring>
// #include <vector>

// class Student : public Person{
// public:
// 	Student() : Person(), major(new char[1]){major[0] = '\0';}
// 	Student(const char *n, const char *m):
// 		Person(n), major(new char[strlen(m)+1])
// 		{strcpy(major,m);}
// 	virtual ~Student() {delete [] major;}
// 	void setMajor(const char* s)const{
// 		delete [] major;
// 		major = new char[strlen(s)+1];
// 		strcpy(major,s);
// 	}

// private:
// 	char *major;

// };

// Student &operator=(const &Student s){
// 	if(&s == this){
// 		return *this;
// 	}
// 	Person::operator=(s);
// 	delete [] major;
// 	major = new char[strlen(s.major)+1];
// 	strcpy(major, s.major);
// 	return *this;
// }
























