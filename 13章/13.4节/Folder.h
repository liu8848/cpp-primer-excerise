#pragma once
#include<set>
#include"Message.h"
class Folder
{
	friend void swap(Folder&, Folder&);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void print_msg();
private:
	std::set<Message*> msgs;

	void add_to_Message(const Folder&);
	void remove_from_Message();

	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.erase(m); }
};

inline
Folder::Folder(const Folder&f):msgs(f.msgs) {}

inline
void Folder::add_to_Message(const Folder& f) {
	for (Message* m : f.msgs) {
		m->addFolder(this);
	}
}

inline 
void Folder::remove_from_Message() {
	for (Message* m : msgs) {
		m->remFolder(this);
	}
}

inline
Folder& Folder::operator=(const Folder& rhs) {
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

inline
Folder::~Folder() {
	remove_from_Message();
}

inline
void swap(Folder& lhs, Folder& rhs) {
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

inline
void Folder::print_msg() {
	for (Message*m:msgs)
	{
		std::cout << m << "    ";
	}
	std::cout << std::endl;
}


