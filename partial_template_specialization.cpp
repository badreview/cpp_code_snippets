#include <iostream>

using namespace std;
 
struct PrintTypeBase {
	virtual void print(){};
};

template <typename T>
struct PrintType : public PrintTypeBase {
	PrintType(const T& t) : _t(t){}
	void print() { cout<<_t<<endl; }
	T _t;
};

template <typename T>
struct PrintType<T*> : public PrintTypeBase {
	PrintType(T* t) : _t(t){}
	void print() { cout<<"["<<*_t<<"]"<<endl; }
	T *_t;
};

//Printer class to print any object assigned to it, 
//as long as the object can be streamed to std::cout
class Printer {
public:
~Printer() { delete _ptr; }
template <typename T>
Printer& operator=(const T &t) {
	_ptr = new PrintType<T>(t);
	return *this;
}

void print() {
	_ptr->print();
}
private:
PrintTypeBase *_ptr;
};

int main() {
	Printer printer;
	
	printer = 58;
	printer.print(); //print "58" to standard output
	
	printer = 3.18777;
	printer.print(); 
	//print "3.18777"	
 
	int* i_ptr = new int(30);
	printer = i_ptr;
	printer.print(); // print "[30]"
 
	*i_ptr = 5; // changed the value pointed by the pointer
	printer.print(); // print "[5]"
	delete i_ptr;
 
	float* f_ptr = new float(3.88);
	printer = f_ptr;
	printer.print(); // print "[3.88]"
	
	*f_ptr = 0.12+0.3;		
	printer.print(); // print "[0.42]"
	delete f_ptr;
 
	printer = std::string("What does fool mean?");
	printer.print(); 
	//print "What does fool mean?"
 
	return 0;
}
