#pragma once
#include<vector>
#include<memory>
#include<string>
#include<initializer_list>
#include<stdexcept>
class ConstStrBlob;
class StrBlob
{
public:
	using size_type = std::vector<std::string>::size_type;
	friend class ConstStrBlob;

	StrBlob():data(std::make_shared<std::vector<std::string>>()){}
	StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
	StrBlob(const StrBlob& sb):data(std::make_shared<std::vector<std::string>>(*sb.data)){}
	StrBlob& operator=(const StrBlob&);

	size_type size() {
		return data->size();
	}

	bool empty() {
		return data->empty();
	}
	void push_back(const std::string& t) {
		data->push_back(t);
	}
	void pop_back() {
		check(0, "pop_back on empty StrBlob!");
		data->pop_back();
	}

	std::string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}


	const std::string& front() const{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const std::string& back() const{
		check(0, "back on empty StrBlob");
		return data->back();
	}

//private:
	void check(size_t i, const std::string& msg) const{
		if (i >= data->size())
			throw std::out_of_range::out_of_range(msg);
	};
	std::shared_ptr<std::vector<std::string>> data;
};

inline
StrBlob& StrBlob::operator=(const StrBlob& sb) {
	data.reset(new std::vector<std::string>(*sb.data));
	return *this;
}