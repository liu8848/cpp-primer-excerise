#include<iostream>
#include"MyString.h"
#include<vector>

int main() {

	char cstr[] = "hello";

  	MyString s1(cstr);
	std::cout << "size:" << s1.size() << "    length:" << s1.length() << "    contents:" << s1.c_str() << std::endl;

	MyString s2(s1);
	std::cout << "size:" << s2.size() << "    length:" << s2.length() << "    contents:" << s2.c_str() << std::endl;

	MyString s3 = s2;
	std::cout << "size:" << s3.size() << "    length:" << s3.length() << "    contents:" << s3.c_str() << std::endl;

	std::vector<MyString> svec;
	svec.reserve(8);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
}