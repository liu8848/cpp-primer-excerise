#pragma once
#include<memory>
#include"StrVec.h"
#include<map>
#include<set>
#include<istream>
#include<fstream>
#include<string>
#include<sstream>
class QueryResult;
class TextQuery
{
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
private:
	std::shared_ptr<StrVec> file;
	std::map < std::string, std::shared_ptr<std::set<size_t>>>wm;
};

inline
TextQuery::TextQuery(std::ifstream& is) :file(new StrVec()) {
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto& lines = wm[word];
			if (!lines) {
				lines.reset(new std::set<size_t>);
			}
			lines->insert(n);
		}
	}
}


class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(std::string s,std::shared_ptr<std::set<size_t>>p,
		std::shared_ptr<StrVec>f):sought(s),lines(p),file(f) {}

private:
	std::string sought;
	std::shared_ptr<std::set<size_t>> lines;
	std::shared_ptr<StrVec> file;
};



inline
QueryResult TextQuery::query(const std::string& sought)const {
	static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);

	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}

