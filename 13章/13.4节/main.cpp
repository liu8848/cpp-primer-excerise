#include<iostream>
#include"Folder.h"
#include"Message.h"
int main() {
	Folder f1 = Folder();
	Message m1("hello"), m2("world"), m3("today");
	m1.save(f1);
	m2.save(f1);
	f1.print_msg();
}