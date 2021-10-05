#pragma once
#include<string>
#include<iostream>
class HasPtr
{
public:
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){
		std::cout << "调用构造函数" << std::endl;
	}
	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {
		std::cout << "调用拷贝构造函数！" << std::endl;
	}
	HasPtr& operator = (const HasPtr &);
	~HasPtr();
private:
	std::string* ps;
	int i;
};

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	std::cout << "调用拷贝赋值运算符！" << std::endl;
	if (this != &rhs) {
		std::string* temp_ps = new std::string(*rhs.ps);
		delete ps;
		ps = temp_ps;
		i = rhs.i;
	}
	return *this;
}

inline
HasPtr::~HasPtr() {
	std::cout << "调用析构函数！" << std::endl;
	delete ps;
}