#include<iostream>
#include"StrBlob.h"

int main() {
	StrBlob sb1({"hello","world"});
	auto sb2 = sb1;

	std::cout << "sb1 address:" << &(sb1.data) << "    sb2 address:" << &(sb2.data) << std::endl;
}