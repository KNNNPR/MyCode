#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

std::vector<std::string> req_list(std::string package, std::vector<std::string> exception = {}, std::string new_exception = "") {
	if (new_exception != "") exception.push_back(new_exception);
	char t;
	int counter = 0;
	std::string line, search = "\"requires_dist\":", word = "";
	std::vector<std::string> list{}, sub_list;
	std::string url = "curl -o data.txt https://pypi.org/pypi/" + package + "/json";
	std::regex reg_1("[a-zA-Z]"), reg_2("extra[ ]*="), reg_3("([_\\-\\w]+).*");
	system(url.c_str());
	std::ifstream file("data.txt");
	std::getline(file, line, 'i');
	if (line == "{\"message\": \"Not Found\"}") {
		file.close();
		return { "NotFound_" };
	}
	line = "";
	while (file.get(t)) {
		if (search[counter] == t) counter += 1;
		else counter = 0;
		if (counter == 16) {
			do {
				file.get(t);
				line.push_back(t);
				if (line == "null") {
					file.close();
					return {};
				}
			} while (t != ']');
			file.close();
			for (char c : line) {
				if (c == '\"' and t != '\\' and word != "") {
					if (regex_search(word, reg_1) and !regex_search(word, reg_2)) {
						word = std::regex_replace(word, reg_3, "$1");
						list.push_back("\"" + package + "\" -> \"" + word + "\"");
						for (std::string line : exception) {
							if (line == word) {
								word = "";
								break;
							}
						}
						if (word != "") {
							sub_list = req_list(word, exception, package);
							if (sub_list.size() > 0 and sub_list[0] != "NotFound_")
								list.insert(list.end(), sub_list.begin(), sub_list.end());
						}
					}
					word = "";
				}
				else word.push_back(c);
				t = c;
			}
			return list;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::string package;
	std::cout << "Введите название пакета:\n";
	std::cin >> package;
	std::vector<std::string> list = req_list(package);
	if (system("cls") != 0) system("clear");
	if (list.size() > 0 and list[0] == "NotFound_") std::cout << "Пакет " << package << " не найден";
	else {
		std::cout << "Граф зависимостей пакета " << package << " в виде текста на языке Graphviz : \n";
		std::cout << "digraph G {\n";
		if (list.size() == 0) std::cout << package << ";\n";
		else for (std::string line : list) std::cout << "\t" << line << ";\n";
		std::cout << "}";
	}
}