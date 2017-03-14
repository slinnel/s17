#include <iostream> 
using std::cout; using std::endl;
/*class string{
	public:
		string() {cout <<"default"<<endl;}
		string (const char *n) { cout << "convert" << endl;}
		string (const string&) { cout << "copy" << endl;}
		const string &operator=(const string&){
			cout<< "assignment" << endl;
		}
	private:
		char * buf;

};
const string doit(const string x){
	return x;
}
int main(){
	string a("me");
	a = doit(a);
}
//		#1 convert copy copy assignment

//NUMBER 2 & 3
#include <cstring>
class string {
	public:
    	string(const char* s) : buf(new char[strlen(s)+1]) { strcpy(buf, s);}
    	string(const string &s) : buf(new char[strlen(s.buf)+1]) {strcpy(buf, s.buf);}
    	~string() { delete [] buf; }
    	const string &operator=(const string &s){
    		if(&s == this){
    			return *this;
    		}
    		delete [] buf;
    		buf = new char[strlen(s.buf)+1];
    		strcpy(buf, s.buf);
    		return *this;
    	}
    	const char* getBuf() const { return buf; }
	private:
    	char * buf;
};
    
int main() {
       string a("dog"), b = a;
       cout << a.getBuf() << endl;
       string c("cat");
       cout << c.getBuf() << endl;
       c = a;
       cout << c.getBuf() << endl;

}

//#3
#include <iostream>
   #include <vector>
   #include <cstdlib>
   const int MAX = 3;
   void print(std::vector<int>& vec) {
     std::cout << "size: " << vec.size() << 't' << "cap: " << vec.capacity() << std::endl;
}
	void print_items(std::vector<int>& vec){
		for(auto s : vec){
			std::cout<<"item"<<s<<std::endl;
		}
	}
   int main() {
     std::vector<int> vec1;
     std::vector<int> vec2(MAX);
     std::vector<int> vec3;
     vec3.reserve(MAX);
     vec1.push_back(rand() % 100);
     vec2.push_back(rand() % 100);
     vec3.push_back(rand() % 100);
     print(vec1);
     print(vec2);
     print(vec3);
     print_items(vec2);
}
*/
#include <iostream>
#include <vector>
using std::string; using std::cout; using std::endl;
class A {
	public:
    	A(const string& n) : name(n) {}
        const string getName() const { return name; }
        int getAge() const { return 111; }
 private:
       string name;
     };
     class B : public A {
     public:
       B(const string& n, int a) : A(n), age(a) {}
       const string getName() const { return "Torvalds"; }
       int getAge() const { return age; }
     private:
       int age;
     };
    
     int main() {
       std::vector<A*> people;
       people.push_back(new B("Abe", 21));
       people.push_back(new A("Bill"));
       cout << people[0]->getAge() << endl;
       cout << people[1]->getAge() << endl;
       for(auto p : people){
       		delete p;
       }
}
//THE FUNCTION IS NOT VITURAL





