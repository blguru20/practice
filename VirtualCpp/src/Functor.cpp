/*
 * Functor.cpp
 *
 *  Created on: 28-Nov-2019
 *      Author: nbhatm
 */


#include <iostream>



class  Multiply {
	int x;
public:
	Multiply(int val){
		x = val;
	}
	int operator()(int y){
		return x*y;
	}
};


int main()
{
	Multiply mul(6);


	std::cout<< mul(5) << "\n";
}

