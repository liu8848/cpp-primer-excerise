#pragma once
#include<memory>
#include<iostream>
#include<algorithm>
class MyString
{
public:
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator=(const MyString& rhs);
	~MyString()
	{
		free();
	}


	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }
private:
	std::allocator<char> alloc;
	void range_initializer(const char*, const char*);
	std::pair<char*, char*>alloc_n_copy(const char*, const char*);
	void free();
	char* elements;
	char* end;
};

inline
MyString::MyString(const char* s) {
	char* s1 = const_cast<char*>(s);
	while (*s1) {
		++s1;
	}
	range_initializer(s, ++s1);
}

inline
std::pair<char*, char*> MyString::alloc_n_copy(const char* b, const char* e) {
	auto str = alloc.allocate(e-b);
	return { str,std::uninitialized_copy(b,e,str) };

}

inline
void MyString::range_initializer(const char* first, const char* last) {
	auto newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	end = newstr.second;
}

inline
MyString::MyString(const MyString& rhs) {
	range_initializer(rhs.elements, rhs.end);
	std::cout << "copy constructor" << std::endl;
}


inline
void MyString::free() {
	if (elements) {
		std::for_each(elements, end, [this](char& c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}

inline
MyString& MyString::operator=(const MyString& rhs) {
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	std::cout << "copy_assignment" << std::endl;
	return *this;
}
