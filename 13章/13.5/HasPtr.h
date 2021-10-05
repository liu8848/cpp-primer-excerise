#pragma once
#include<string>
#include<iostream>
class HasPtr
{
public:
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0){
		std::cout << "���ù��캯��" << std::endl;
	}
	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {
		std::cout << "���ÿ������캯����" << std::endl;
	}
	HasPtr& operator = (const HasPtr &);
	~HasPtr();
private:
	std::string* ps;
	int i;
};

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	std::cout << "���ÿ�����ֵ�������" << std::endl;
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
	std::cout << "��������������" << std::endl;
	delete ps;
}