#include<iostream>
#include"HasPtr.h"

int main() {
	HasPtr hp1("hello world!");//���ù��캯��
	HasPtr hp2(hp1);//���ÿ������캯��
	HasPtr hp3("");
	hp3 = hp1;//�������������

	HasPtr hp4(HasPtr("hello world!"));
	std::cout << std::endl;
	return 0;
}