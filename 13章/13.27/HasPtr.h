#pragma once
#include<iostream>
class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0),use(new std::size_t(1)) {}
	HasPtr(const HasPtr& hp) :ps(hp.ps), i(hp.i), use(hp.use) { ++* use; }
	HasPtr& operator=(const HasPtr&);
	int get_use() {
		return *use;
	}
	~HasPtr();
	std::size_t* use;
	std::string* ps;
	int i;
};

inline 
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
	++* rhs.use;
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

inline 
HasPtr::~HasPtr() {
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
}

inline
void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "µ÷ÓÃswap(HasPtr&lhs,HasPtr&rhs)" << std::endl;
}