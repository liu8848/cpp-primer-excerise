#pragma once
#include<string>
#include<vector>
#include<memory>
class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(std::initializer_list<std::string>il);
	~StrVec();
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity()const { return cap - first_free; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void reserver(size_t n);
	void resize(size_t count);
	void resize(size_t count,const std::string&);
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);
	std::string* elements;
	std::string* first_free;
	std::string* cap;
};

inline
void StrVec::chk_n_alloc() {
	if (size() == capacity()) {
		reallocate();
	}
}

inline
void StrVec::push_back(const std::string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

inline
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
	auto data = alloc.allocate(e - b);
	return{ data,std::uninitialized_copy(b,e,data) };
}

inline
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		 }
		alloc.deallocate(elements, cap - elements);
	}
}

inline
void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

inline
StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline
StrVec& StrVec::operator=(const StrVec& rhs) {
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

inline
StrVec::~StrVec() {
	free();
}

inline
void StrVec::alloc_n_move(size_t new_cap) {
	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

inline
void StrVec::reserver(size_t n) {
	if (n <= capacity()) return;
	alloc_n_move(n);
}

inline 
void StrVec::resize(size_t count,const std::string&s) {
	if (count > size()) {
		if (count > capacity()) reserver(count * 2);
		for (size_t i = size(); i != count; i++) {
			alloc.construct(first_free++, s);
		}
	}
	else if(count<size())
	{
		while (first_free != elements + count) {
			alloc.destroy(--first_free);
		}

	}
}

inline
void StrVec::resize(size_t count) {
	resize(count, std::string());
}

inline
StrVec::StrVec(std::initializer_list<std::string>il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}