#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//start from first string and iterate through all of them checking if they have the same
//character as the first one. 
//Possible to put in a Trie for O(logn) search time, with O(nlogn) instead of O(n^2)
std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string longest_prefix;
	if (strs.size() == 0) return "";
	for (int i = 0; i < strs[0].size(); ++i) {
		char compare_char = strs[0][i];
		bool equal_char = true;
		for (int j = 1; j < strs.size(); ++j) {
			if (strs[j].size() < i) {
				return longest_prefix;
			}
			if (strs[j][i] != compare_char) equal_char = false;
		}
		if (equal_char == true) {
			longest_prefix += compare_char;
		}
		else {
			break;
		}
	}
	return longest_prefix;
}

int main() {
	std::vector<std::string> vec = { "aca", "cba" };
	std::cout << longestCommonPrefix(vec);

	return 0;
}