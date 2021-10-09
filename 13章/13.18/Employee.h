#pragma once
#include<string>
class Employee
{
public:
	Employee();
	Employee(const std::string&);
	const int id() { return eid; }
private:
	std::string name;
	int eid;
	static int s_increment;
};

inline
Employee::Employee() {
	eid = s_increment++;
}

inline
Employee::Employee(const std::string& _name) {
	eid = s_increment++;
	name = _name;
}

