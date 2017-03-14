//GOF Singleton
/*
#include <cstdlib>
#include <iostream>
class Random { 
	public:
		static Random *getInstance(){ 
			if(!instance)
				instance = new Random();
			return instance;
		}
		int operator ()( int a, int b){
			return (rand() % b) + a;
		}
		private:
			static Random *instance;
			Random ( ) {
			int seed = time (0); 
			srand ( seed );
			}
			Random(const Random&);
			Random& operator =(const Random &);
};
Random * Random::instance = NULL;
int main() {
	Random *random  = Random::getInstance();
	std::cout << (*random)(1,100) << std::endl;
	std::cout << (*Random::getInstance())(1,100) << std::endl;
}
//#2
#include <cstring> 
#include <iostream>
class string { 
	public:
		string(const char *s) : buf(new char[strlen(s)+1]) { strcpy(buf, s); } 
		const char *getBuf () const { return buf; }
		string(const string &s): buf(new char[strlen(s.buf)+1]){
			strcpy(buf,s.buf);
		}
		void setBuf(const char* s) {
			delete [] buf;
			buf = new char[strlen(s)+1]; 
			strcpy(buf, s);
		}
	private:
		char *buf ;
};
int main() {
	string a("cat"), b = a;
	b.setBuf("dog");
	std::cout << a.getBuf() << std::endl;
	std::cout << b.getBuf() << std::endl;
}

//#3
*/
// #include <cstring> 
// #include <iostream>
// class Student { 
// public:
// 	Student(const char* n) : name(new char[strlen(n)+1]) { strcpy(name, n); } 
// 	const char* getName() const { return name; }
// 	void setName(const char* n) {
// 		delete [] name;
// 		name = new char [ strlen (n)+1];
// 		strcpy(name, n);
// 	}
// 	Student(const Student &s):name(new char[strlen(s.name)]){
// 		strcpy(name, s.name);
// 	}
// 	Student &operator =(const Student &s){
// 		if(&s == this)
// 			return *this;
// 		setName(s.name);
// 		return *this;
// 	}
// private:
// 	char *name;
// };
// int main() {
// 	Student a("John"), b = a;
// 	std::cout << a.getName() << std::endl;
// 	std::cout << b.getName() << std::endl;
// 	//b=a;
// 	b.setName("Sam") ;
// 	std::cout << a.getName() << std::endl;
// 	std::cout << b.getName() << std::endl;

// }


// #include <iostream>
// #include <vector>
// class A { 
// public:
// 	A() {}
// 	virtual void foo ()const { std::cout << "I’m foo in A" << std::endl;}
// 	void bar () const { std::cout << "I’m bar in A" << std::endl;}
// };
// class B : public A{ 
// public:
// 	B() : A() {}
// 	virtual void foo () const { std::cout << "I’m foo in B" << std::endl;}
// 	void bar () const { std::cout << "I’m bar in B" <<std::endl;}
// };
// int main() 
// { 
// 	std::vector<A*> vec; 
// 	vec.push_back( new B ); 
// 	vec[0]->foo(); 
// 	vec[0]->bar();
// }
//6
// #include <iostream>
// class B{
// public:
// 	B(int n): number(n+'0'){}
// 	char getNumber() const {return number;}
// private:
// 	char number;
// };
// class A{
// public:
// 	A(int n):b(new B(n)){}
// 	char getB() const { return b-> getNumber();}
// private:
// 	B* b;
// };
// int main(){
// 	A* a = new A(7);
// 	std::cout<<a->getB()<<std::endl;
// }

// #include <iostream>
// #include <cstdlib>
// #include <vector>
// const int MAX = 2;
// class A{
// public:
// 	A(){std::cout << "default" << std::endl; }
// 	A(const A&){std::cout << "copy" << std::endl; }
// };
// template <typename T>
// void print(std::vector<T> &vec){
// 	std::cout << "size: " << vec.size() << '\t'
// 		<< "cap: " << vec.capacity() << std::endl;
// }
// int main(){
// 	std::vector<int> vec1;
// 	std::vector<int> vec2;
// 	vec2.reserve(MAX);
// 	vec1.push_back(rand() % 100);
// 	vec2.push_back(rand() % 100);
// 	std::vector<A> vec3(MAX);
// 	vec3.push_back(A());
// 	print(vec1);
// 	print(vec2);
// 	print(vec3);
// }

//v1 size -> 1 cap 1
//v2 size -> 1, cap 2
//v3 size -> 3 cap 4


#include <iostream>
#include <vector>
#include <cstdlib>

const int MAX = 100;
const int LETTERS = 26;

void init(std::vector<char> &vec){

	for(unsigned int i = 0; i < MAX; ++i){
		vec.push_back(rand() % LETTERS + 'A');
	}
}
void print(const std::vector<char> &vec){
	for(unsigned int i = 0; i < vec.size(); ++i){
		std::cout<<vec[i]<<" ";
	}
	std::cout<<std::endl;
}
void eraseVowels(std::vector<char> &vec){
	std::remove(vec.begin(), vec.end(), 'A');
	std::remove(vec.begin(), vec.end(), 'E');
	std::remove(vec.begin(), vec.end(), 'I');
	std::remove(vec.begin(), vec.end(), 'O');
	std::remove(vec.begin(), vec.end(), 'U');
}
int main(){
	std::vector<char> vec;
	init(vec);
	print(vec);
	std::cout<<std::endl;
	eraseVowels(vec);
	print(vec);
}





















