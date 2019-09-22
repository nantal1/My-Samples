#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


//string.erase the '.' and string.insert the "[.]"
std::string defangIPaddr(std::string address) {
	for (int i = 0; i < address.length(); i++) {
		if (address[i] == '.') {
			address.erase(i, 1);
			address.insert(i, "[.]");
			i = i + 2;
		}
	}
	return address;
}

int main() {
	std::string str = "255.100.50.0";
	std::cout << defangIPaddr(str);
	return 0;
}