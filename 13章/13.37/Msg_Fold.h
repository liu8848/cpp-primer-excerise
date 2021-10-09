#pragma once
#include<string>
#include<set>
#include<iostream>

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	Message(const std::string& str=""):contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	void save(Folder&);
	void remove(Folder&);

	void print_folders();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFolder(Folder* f) { folders.insert(f); }
	void remFolder(Folder* f) { folders.erase(f); }
};

inline
Message::Message(const Message& m) :contents(m.contents), folders(m.folders) { add_to_Folders(m); }

inline
Message& Message::operator=(const Message& rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

inline
Message::~Message() {
	remove_from_Folders();
}



inline
void swap(Message& lhs, Message& rhs) {
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}




class Folder
{
public:
	friend class Message;
	friend void swap(Folder&, Folder&);
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();

	void print_msgs();


private:
	std::set<Message*> msgs;

	void add_to_Message(const Folder&);
	void remove_from_Message();

	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message* m) { msgs.erase(m); }
};

inline
void Folder::print_msgs() {
	for (Message* m : msgs) {
		std::cout << m << "    ";
	}
	std::cout << std::endl;
}

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
Folder::Folder(const Folder& f) :msgs(f.msgs) { add_to_Message(f); }

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
	lhs.remove_from_Message();
	rhs.remove_from_Message();
	swap(lhs.msgs, rhs.msgs);
	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}
inline
void Message::print_folders() {
	for (Folder* f : folders) {
		std::cout << f << "    ";
	}
	std::cout << std::endl;
}

inline
void Message::add_to_Folders(const Message& m) {
	for (Folder* f : m.folders) {
		f->addMsg(this);
	}
}

inline
void Message::remove_from_Folders() {
	for (Folder* f : folders) {
		f->remMsg(this);
	}
}

inline
void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

inline
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}
