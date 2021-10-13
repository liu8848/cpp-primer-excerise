#pragma once
#include<iostream>
class Quote
{
public:
	Quote() = default;
	Quote(const std::string& book, double sale_price) :bookNo(book),price(sale_price) {}
	std::string isbn() { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

