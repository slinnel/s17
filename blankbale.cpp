#include <iostream>

class Student {
public:
	Student() : gpa(0), number(0){std::cout<<"default"<<std::endl;}
	Student(const Student& s): gpa(s.gpa), number(s.number){std::cout<<"copy"<<std::endl;}
	Student(int g, int n): gpa(g), number(n){std::cout<<"construct"<<std::endl;}
	int get_gpa()const{
		return gpa;
	}
	int get_number()const{
		return number;
	}
private:
	int gpa;
	int number;
};

std::ostream& operator<<(std::ostream& out, const Student& s){
	out<<"("<<s.get_number()<<", "<<s.get_gpa()<<")\n";
	return out;
}


int main(){
	Student a , b(1,3), c = b;



	std::cout<<b;


	return 0;
}
