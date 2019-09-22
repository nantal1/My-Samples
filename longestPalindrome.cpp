#include <string>
#include <iostream>



//Start from either side and see if the string meets in the middle
std::string longestPalindrome(std::string s) {
	int counter = 0;
	int max_palindrome = 0;
	int pos = 0;
	std::string longest_palindrome;
	for (int i = 0; i < s.size() / 2;) {
		for (int j = s.size() - 1; j >= s.size() / 2;) {
			if (i >= j) {
				if (i == j) {
					++counter;
				}
				if (counter > max_palindrome) {
					longest_palindrome = s.substr(pos, pos + counter);
					max_palindrome = counter;
					counter = 0;
				}
				break;
			}
			if (s[i] == s[j]) {
				++i;
				--j;
				counter += 2;
			}
			else {
				pos = i + 1;
				counter = 0;
				break;
			}
		}
	}
	return longest_palindrome;
}

int main() {
	std::cout << longestPalindrome("ababa");
	return 0;
}