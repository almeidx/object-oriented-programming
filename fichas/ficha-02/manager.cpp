#include "manager.hpp"

Manager::Manager() {
	cout << "Manager created" << endl;
}

Manager::~Manager() {
	cout << "Manager destroyed" << endl;
}

bool Manager::add_person(string nome, string cidade, int idade) {
	Person p(nome, cidade, idade);
	people.push_back(p);
	return true;
}

bool Manager::add_person(Person *P) {
	people.push_back(*P);
	return true;
}

bool Manager::from_file(string nome_ficheiro) {
	ifstream file(nome_ficheiro);
	if (!file.is_open()) {
		return false;
	}

	string line;
	while (getline(file, line)) {
		list<string> tokens = Utils::split(line, ';');

		string city = tokens.front();
		tokens.pop_front();
		string name = tokens.front();
		tokens.pop_front();

		int age;
		if (!tokens.empty()) {
			age = stoi(tokens.front());
		} else {
			age = 18;
		}

		add_person(name, city, age);

		tokens.clear();
	}

	file.close();

	return true;
}

void Manager::print() {
	for (auto &person : people) {
		person.print();
	}
}

bool Manager::remove(Person *P) {
	people.remove(*P);
	return true;
}

bool Manager::remove(string name) {
	for (auto &person : people) {
		if (person.name == name) {
			remove(&person);
			return true;
		}
	}
	return false;
}

bool Manager::save_to_file(string filename) {
	ofstream file(filename, ios::trunc);
	if (!file.is_open()) {
		return false;
	}

	for (auto &person : people) {
		file << person.city << ";" << person.name << ";" << (int)person.age << endl;
	}

	file.close();

	return true;
}

Person *Manager::search_person(string nome) {
	for (auto &person : people) {
		if (person.name == nome) {
			return &person;
		}
	}
	return NULL;
}

string Manager::get_most_populated_city() {
	string city;
	int count = 0;

	for (auto &person : people) {
		int city_count = 0;
		for (auto &person2 : people) {
			if (person.city == person2.city) {
				city_count++;
			}
		}

		if (city_count > count) {
			city = person.city;
			count = city_count;
		}
	}

	return city;
}
