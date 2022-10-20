#ifndef PESSOA_H
#define PESSOA_H

#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Person {
	string name;
	string cc;
	// list<Account *> acc_list;

public:
	Person(string _nome, string _cc);
	virtual ~Person();
	void print();
	string get_cc();
	void save_to_file(ofstream &F);
};

#endif // PESSOA_H
