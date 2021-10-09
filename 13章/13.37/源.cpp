#include<iostream>
#include"Msg_Fold.h"

int main() {
	Folder f1 = Folder();
	Folder f2 = Folder();
	Message m1("hello"), m2("world"), m3("today");
	m1.save(f1);
	m2.save(f1);
	m3.save(f2);
	m1.print_folders();
	m2.print_folders();
	m3.print_folders();
	f1.print_msgs();
	f2.print_msgs();


	swap(f1, f2);
	m1.print_folders();
	m2.print_folders();
	m3.print_folders();
	f1.print_msgs();
	f2.print_msgs();
}