//number 9 quiz 2
#include <iostream>
#include <cstring>

class string{
public:
	string(): buf(new char[1]){buf[0]='\0';}
	string(const char *b):buf(new char[strlen(b)+1]){strcpy(buf,b);}
	~string(){delete [] buf;}
	const char &operator[](int index)const {return buf[index];}
	char &operator[](int index){return buf[index];}
	string &operator=(const string &s){
		if(&s == this)
			return *this;
		delete [] buf;
		buf = new char[strlen(s.buf)+1];
		strcpy(buf, s.buf);
		return *this;
	}
private:
	char *buf;

};


int main(){
	string a("dog"), b;
	b = a;
	std::cout<<b[0]<<std::endl;
}