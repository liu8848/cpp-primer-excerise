#include<iostream>
#include"StrVec.h"
#include"TextQuery.h"

void print(const StrVec& s) {
	std::cout << "size:" << s.size()<<"    capacity:"<<s.capacity()<<std::endl;
	std::cout << "contents:";
	for (auto str = s.begin(); str != s.end(); str++) {
		std::cout << *str << "      ";
	}
	std::cout << std::endl;
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << "出现" << qr.lines->size() << "次" << std::endl;
	for (auto num : *qr.lines) {
		os << "\t第" << num + 1 << "行：" << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

void runQueries(std::ifstream& infile) {
	TextQuery tq(infile);
	while (true) {
		std::cout << "请输入要查询的词，或按q退出:";
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main() {
	//StrVec v1({ "hello","world" });
	//print(v1);
	//StrVec v2(v1);
	//print(v2);
	//StrVec v3(v1);
	//print(v3);

	//v1.resize(10);
	//v2.resize(10, "today");
	//v3.reserver(5);
	//print(v1);
	//print(v2);
	//print(v3);
	std::string path = "";
	std::ifstream infile("D:\\OneDrive\\桌面\\test.txt");
	runQueries(infile);
}