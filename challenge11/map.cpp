// map.cpp: inverted index

#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

	string alnum = "abcdefghijklmnopqrstuvwxyz0123456789";
	int line = 0;
	string input;
	while(getline(cin, input)) {
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		stringstream ssinp(input);

		string word;
		line++;
		while(ssinp >> word) { //iterate over words
			int first;
			int last;
			first = word.find_first_of(alnum);
			last = word.find_last_of(alnum);
			if(last-first+1 > 0 && first != -1) //characters were found and size is not 0
				cout << word.substr(first, last+1-first) << "\t" << line << endl;
		}
	}
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
