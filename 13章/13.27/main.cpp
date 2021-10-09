#include<iostream>
#include"HasPtr.h"

int main() {
	HasPtr hp1("hello");
	std::cout << "hp1 use:" << hp1.get_use() << "    address:" <<hp1.use << std::endl;
	HasPtr hp2(hp1);
	std::cout << "hp1 use:" << hp1.get_use() << "    address:" << hp1.use << std::endl;
	std::cout << "hp2 use:" << hp2.get_use() << "    address:" << hp2.use << std::endl;

	HasPtr hp3("world");
	std::cout << "hp1:" << *hp1.ps << "    hp3:" << *hp3.ps << std::endl;
	swap(hp1, hp3);
	std::cout << "hp1:" << *hp1.ps << "    hp3:" << *hp3.ps << std::endl;
}