#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
<program> ::= <s-exp-list>
<s-exp-list> ::= <s-exp> | <s-exp> <s-exp-list>
<s-exp> ::= <groups> | <students> | <subjects> | <comms>

<groups> ::= '(' '!' <group-list> ')'
<students> ::= '(' '?' <student-list> ')'
<subjects> ::= '(' '~' <subject> ')'
<comms> ::= '#' <chars> '\n'

<group-list> ::= <word> | <word> <group-list>
<word> ::= <letter> | <letter> <word>
<letter> ::= 'a' | ... | 'z' | 'A' | ... | 'Z' | '0' | ... | '9' | '-' | '.'

<student-list> ::= <student> | <student> <student-list>
<student> ::= '\'' <age> <word> <name> '\''
<age> ::= <number> | <number> <age>
<number> ::= '0' | ... | '9'
<name> ::= <word> | <word> <name>

<subject> ::= '\'' <name> '\''

<chars> ::= <char> | <char> <chars>
<char> ::= Any char
*/
enum state {
	WAITING, GROUPS, STUDENTS, SUBJECT
};

class inserted {
	friend class exec;
	inserted* parent = nullptr;
	inserted* child = nullptr;
	state current_state = WAITING;
	bool writing = false;
	std::string word;
	std::vector<std::string> intermediate_result;
	std::vector<std::string> results;
	inserted(inserted* parent) {
		this->parent = parent;
	}
	void set_state(state state) {
		if (current_state != WAITING) std::cout << "Not expected state symbol\n";
		current_state = state;
		word = "";
		intermediate_result = {};
		results = {};
	}
	inserted* level_down() {
		child = new inserted(this);
		return child;
	}
	inserted* level_up() {
		if (parent == nullptr) { std::cout << "Not expected ')'\n"; return this; }
		parent->transfer(summation());
		return parent;
	}
	void transfer(std::string result) {
		child = nullptr;
		results.push_back(result);
	}
	std::string tab(std::string text) {
		std::string new_text = "\t";
		for (char t : text) {
			new_text.push_back(t);
			if (t == '\n') new_text.push_back('\t');
		}
		return new_text;
	}
	std::string wrap(std::string text) {
		std::string new_text = "\"" + text + "\"";
		return new_text;
	}
	std::string listing() {
		int size = results.size();
		std::string list = "";
		for (int num = 0; num < size; num++) {
			if (num != 0) list += ",\n";
			list += results[num];
		}
		return list;
	}
	std::string summation() {
		switch (current_state) {
		case(WAITING): return sum_waiting();
		case(GROUPS): return sum_groups();
		case(STUDENTS): return sum_students();
		case(SUBJECT): return sum_subject();
		}
	}
	std::string sum_waiting() {
		std::string final_result = "{\n" + tab(listing()) + "\n}";
		return final_result;
	}
	std::string sum_groups() {
		proc_groups();
		std::string final_result = wrap("groups") + ": [\n" + tab(listing()) + "\n]";
		return final_result;
	}
	std::string sum_students() {
		proc_students();
		std::string final_result = wrap("students") + ": [\n" + tab(listing()) + "\n]";
		return final_result;
	}
	std::string sum_subject() {
		std::string final_result = wrap("subject") + ": " + wrap(results[0]);
		return final_result;
	}
	void processing(char t) {
		if (t == '\t' || t == '\n') return;
		switch (current_state) {
		case(GROUPS): proc_groups(t); break;
		case(STUDENTS): proc_students(t); break;
		case(SUBJECT): proc_subject(t); break;
		}
	}
	void proc_groups(char t = ' ') {
		if (t == ' ') { if (word != "") results.push_back(word); word = ""; }
		else word.push_back(t);
	}
	void proc_students(char t = ' ') {
		if (t == '\'') {
			if (writing) {
				proc_students();
				if (intermediate_result.size() == 3) {
					std::string result;
					result += "{\n\t\"age\": " + intermediate_result[0];
					result += ",\n\t\"group\": " + intermediate_result[1];
					result += ",\n\t\"name\": " + intermediate_result[2];
					result += "\n}";
					results.push_back(result);
				}
				writing = false;
			}
			else {
				intermediate_result = {};
				writing = true;
			}
		}
		else if (writing) {
			if (t == ' ') {
				if (word != "") {
					if (intermediate_result.size() == 3) intermediate_result[2] += " " + word;
					else intermediate_result.push_back(word);
					word = "";
				}
			}
			else word.push_back(t);
		}
	}
	void proc_subject(char t) {
		if (t == '\'') {
			if (writing) {
				results.push_back(word);
				writing = false;
			}
			else {
				word = "";
				writing = true;
			}
		}
		else if (writing) word.push_back(t);
	}
};

class exec {
	inserted* current = new inserted(nullptr);
	bool sleeping = false;
public:
	void processing(char t) {
		if (sleeping && t != '\n') return;
		else if (sleeping) sleeping = false;
		else {
			switch (t) {
			case('('): current = current->level_down(); break;
			case(')'): current = current->level_up(); break;
			case('!'): current->set_state(GROUPS); break;
			case('?'): current->set_state(STUDENTS); break;
			case('~'): current->set_state(SUBJECT); break;
			case('#'): sleeping = true; break;
			default: current->processing(t);
			}
		}
	}
	std::string get_results() {
		if (current->parent != nullptr) std::cout << "Missing expected ')'\n";
		return current->summation();
	}
};

int main(int argc, char* args[]) {
	setlocale(LC_ALL, "Russian");
	std::string path, result_path;
	if (argc == 1) {
		std::cout << "Enter path of source file: ";
		getline(std::cin, path);
	}
	else path = args[1];
	result_path = "result.json";
	exec* ex = new exec();
	char t;
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cout << "File " << path << " not exists\n";
		path = "config_example.txt";
		std::cout << "Default path: " << path << "\n";
		file.open(path);
	}
	if (!file.is_open()) {
		std::cout << "File on default path not exists\n";
	}
	else {
		while (file.get(t)) {
			ex->processing(t);
		}
		file.close();
	}
	std::string result = ex->get_results();
	std::cout << result << "\n";
	std::ofstream json_file(result_path);
	if (!json_file.is_open()) std::cout << "JSON file not exists\n";
	else {
		json_file << result;
		json_file.close();
		std::cout << "Saved to " << result_path << "\n";
	}
}