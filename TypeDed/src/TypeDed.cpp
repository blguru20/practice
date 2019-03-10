#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <type_traits>
#include <string>
extern "C" FILE *popen(const char *command, const char *mode);
struct A {
	virtual ~A() {
	}
};
struct B: A {
};

class C {
};
class D: public C {
};

/* B b;
 auto & BR = b;
 A* ap = &b;
 A& ar = b;
 const int ki = 10;
 std::cout << "BR: " << typeid(BR).name() << std::endl;
 std::cout << "constant : " << typeid(ki).name() << std::endl;
 std::cout << "ap: " << typeid(ap).name() << std::endl;
 std::cout << "ar: " << typeid(ar).name() << std::endl;

 D d;
 C* cp = &d;
 C& cr = d;
 std::cout << "cp: " << typeid(*cp).name() << std::endl;
 std::cout << "cr: " << typeid(cr).name() << std::endl;

 int e;
 unsigned f;
 char g;
 float h;
 double i;
 std::cout << "int:\t" << typeid(e).name() << std::endl;
 std::cout << "unsigned:\t" << typeid(f).name() << std::endl;
 std::cout << "char:\t" << typeid(g).name() << std::endl;
 std::cout << "float:\t" << typeid(h).name() << std::endl;
 std::cout << "double:\t" << typeid(i).name() << std::endl;*/

template<typename FIRST> std::string typeName() {

	std::string tName;

	// get name of the type (and remove the '\n' at the end)
	FILE *fp =
			popen(
					(std::string("c++filt -t ")
							+ std::string(typeid(FIRST).name())).c_str(), "r");
	char buf[1024];
	fgets(buf, 1024, fp);
	fclose(fp);
	tName += buf;
	tName.erase(std::prev(tName.end()));

	// check whether we have a const qualifier
	if (std::is_const < FIRST > ::value) {
		tName += " const";
	}

	// check whether type declares a volatile variable
	if (std::is_volatile < FIRST > ::value) {
		tName += " volatile";
	}

	// check for lvalue and rvalue references
	if (std::is_lvalue_reference < FIRST > ::value) {
		tName += "&";
	}
	if (std::is_rvalue_reference < FIRST > ::value) {
		tName += "&&";
	}

	return tName;
}

template<typename FIRST, typename SECOND, typename ... OTHER> std::string typeName() {
	return typeName<FIRST>() + ", " + typeName<SECOND, OTHER...>();
}
template<typename T>
void f(T& param){
	std::cout << typeName< T, decltype(param) >()
				<< std::endl;
}

template<typename T>
void f1(const T& param){
	std::cout << typeName< T, decltype(param) >()
				<< std::endl;
}

template<typename T>
void fp( T* param){
	std::cout << typeName< T, decltype(param) >()
				<< std::endl;
}

void Case11(void) {
int x = 27;
const int cx = x;
const int& rx = x;
f(x);
f(cx);
f(rx);
}

void Case12(void) {
int x = 27;
const int cx = x;
const int& rx = x;
f1(x);
f1(cx);
f1(rx);

}
void Case13(void) {
int x = 27;
const int * px =& x;
/*const int& rx = x;*/
fp(&x);
fp(px);
//fp(rx);
}
int main() {
	std::cout <<"  ref or ptr but not universal ref\n ";
	Case11();
	std::cout <<"  ******\n ";
	Case12();
	std::cout <<"  ******\n ";
	Case13();

	std::cout <<"  universal ref \n ";
/*	std::cout << typeName<std::string*&, int&&, char const* const >()
			<< std::endl;*/

	return 0;
}

