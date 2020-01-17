// CPP program to illustrate
// concept of Virtual Functions

#include <iostream>
#include <vector>
using namespace std;


std::vector<int> intVec;


class base {
public:
	virtual ~base(){

	}

/*	virtual base(){
//constructors cannot be declared ‘virtual’ [-fpermissive]
	}*/
	virtual void print()
	{
		cout << "print base class" << endl;
	}
	virtual void nonOverRidden()
	{
		cout << " nonOverRidden base class" << endl;
	}
	void show()
	{
		cout << "show base class" << endl;
	}

/*	static virtual void myFun(){
	// causes syntax error -- can't be both virtual  static
	}*/
};

class derived : public base {
public:
	virtual ~derived(){}
	void print()
	{
		cout << "print derived class" << endl;
	}

	void show()
	{
		cout << "show derived class" << endl;
	}

/*	 int nonOverRidden()
	{
		cout << " nonOverRidden base class" << endl;
		return 1;
	}*/  //error: conflicting return type specified for ‘virtual int derived::nonOverRidden()
		// cannot override based on return type

		// also virtual cannot be a friend
};

int main()
{
	base* bptr;
	derived d;
	bptr = &d;
//	intVec.push_back(45);

	cout << "calling functions on derived object: " << endl;

	d.print();
	d.show();
	d.nonOverRidden();

	cout << "calling functions on base ptr with derived object: " << endl;

	// virtual function, binded at runtime
	bptr->print();

	// Non-virtual function, binded at compile time
	bptr->show();

	std::cout << "sizeOf on vector : " << sizeof(intVec) << "  : "<< intVec.size() <<std::endl;


	std::cout << "Address of bptr  " << bptr << std::endl;
	std::cout << "Address of bptr +1 " << ++bptr<< std::endl;

	std::cout << "size  of bptr " << sizeof(bptr)<< std::endl;


}
