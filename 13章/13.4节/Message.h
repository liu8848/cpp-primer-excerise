#pragma once
#include<string>
#include<set>

class Folder;
class Message
{
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	explicit Message(const std::string&str=""):contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFolder(Folder* f) { folders.insert(f); }
	void remFolder(Folder* f) { folders.erase(f); }
};

inline void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

inline void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

inline 
void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

inline
void Message::remove_from_Folders() {
	for (auto f : folders) {
		f->remMsg(this);
	}
}

inline
Message::Message(const Message& m) :contents(m.contents), folders(m.folders) { add_to_Folders(m); }

inline
Message& Message::operator=(const Message&rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);;
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