#include<iostream>
#include"HasPtr.h"

int main() {
	HasPtr hp1("hello world!");//调用构造函数
	HasPtr hp2(hp1);//调用拷贝构造函数
	HasPtr hp3("");
	hp3 = hp1;//调用运算符重载

	HasPtr hp4(HasPtr("hello world!"));
	std::cout << std::endl;
	return 0;
}