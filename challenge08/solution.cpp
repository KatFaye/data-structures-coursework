// Challenge 08: Palindrome Permutation

// Main Execution
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <typeinfo>
#include <ctype.h>

using namespace std;
bool is_palindrome(unordered_map<string, int> p, int size) {

	if(size%2 == 0) {
		//even
		for(const auto& i : p) {
			if(i.second%2 == 1) //can't be a palindrome
				return false;
		}
	} else {
		//odd
		int odds = 0;
		for(const auto& i : p) {
			if(i.second%2 == 1)
				//cout << i.first << endl;
				odds++;
				//cout << odds;
			if(odds > 1) //can't be a palindrome
				return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]) {

	string input;
	while(getline(cin, input)) {

		unordered_map<string, int> palindrome;
		int size = 0;
		for( auto it = input.begin(); it != input.end(); ++it) {
			if(isalpha(*it)) {
				size++;
				char c = tolower(*it);
				stringstream ss;
				string target;
				ss << c;
				ss >> target;
				auto search = palindrome.find(target);
				if(search == palindrome.end()) {
					//insert value
					palindrome.insert(make_pair<string, int>(string(target), 1));
				} else {
					//increment counter
					search->second++;
				}
			}
		}
		bool isP = is_palindrome(palindrome, size);
		/*for(const auto& i : palindrome) {
			cout << i.first << " " << i.second << endl;
		}*/
		string output = isP ? " is" : " is not";
		cout << "\"" << input << "\"" << output << " a palindrome permutation"<< endl;

	}
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
