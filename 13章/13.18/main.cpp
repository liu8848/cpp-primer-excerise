#include<iostream>
#include"Employee.h"
int Employee::s_increment = 0;
int main() {
	Employee e1;
	Employee e2("Jack");

	std::cout << e1.id() << "      " << e2.id() << std::endl;
}