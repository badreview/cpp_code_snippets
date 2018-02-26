#include <iostream>

using namespace std;
 
/// implement your class here

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
///
 
 
int main() {
	Printer printer;
 
	printer = 42;
	printer.print(); //should print "42" to standard output
 
	int* value = new int(10);
	printer = value;
	printer.print(); // should print "[10]"
 
	*value = 20; // the value pointer did not change, changed a value by it
	printer.print(); // should print "[20]"
 
	float* fvalue = new float(9.81);
	printer = fvalue;
	printer.print(); // should print "[9.81]"
 
    *fvalue = 0.2+0.3;
	printer.print(); // should print "[0.5]"
 
	printer = std::string("Hello world");
	printer.print(); 
	//should print "Hello world"
 
	printer = 2.718281;
	printer.print(); 
	//should print "2.718281"
 
    delete fvalue;
    delete value;
	return 0;
}
