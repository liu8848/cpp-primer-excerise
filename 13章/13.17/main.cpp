#include<iostream>
#include"numbered.h"

void f(numbered s) {
	std::cout << s.mysn << std::endl;
}

void f1(const numbered& s) {
	std::cout << s.mysn << std::endl;
}

int main() {
	numbered a, b = a, c = b;

	std::cout << "a:" << a.mysn << "    b:" << b.mysn << "    c:" << c.mysn << std::endl;
	f(a), f(b), f(c);
}