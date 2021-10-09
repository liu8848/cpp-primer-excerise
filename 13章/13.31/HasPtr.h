#pragma once
#include<iostream>
#include<string>
class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
	HasPtr(const std::string&s=std::string()):ps(new std::string(s)),use(new size_t(1)),i(0) {}
	HasPtr(const HasPtr& hp) :use(hp.use), ps(hp.ps), i(hp.i) { ++* use; }
	~HasPtr()
	{
		if (-- * use == 0) {
			delete use;
			delete ps;
		}
	}
	HasPtr& operator=(const HasPtr&);
	std::string getps() {
		return *ps;
	}
private:
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
void swap(HasPtr& lhs, HasPtr& rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "µ÷ÓÃswap(HasPtr&lhs.HasPtr&rhs)" << std::endl;
}

inline
bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
	return *lhs.ps < *rhs.ps;
}