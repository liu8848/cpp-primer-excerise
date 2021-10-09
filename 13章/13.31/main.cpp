#include<iostream>
#include<vector>
#include<algorithm>
#include"HasPtr.h"
int main() {
	std::vector<HasPtr> vec{ HasPtr("abc"),HasPtr("hij"),HasPtr("efg")};
	for(HasPtr hp : vec)
	{
		std::cout << hp.getps() << "      ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end());
	for (HasPtr hp : vec)
	{
		std::cout << hp.getps() << "      ";
	}
	std::cout << std::endl;
}