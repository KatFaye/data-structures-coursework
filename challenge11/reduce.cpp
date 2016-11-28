// reduce.cpp: inverted index

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

	map<string, set<int>> dictionary;
	string input;
	int line;
	while(cin >> input) {
		cin >> line;
		dictionary[input].insert(line);
		
	}
	for(auto it = dictionary.begin(); it!=dictionary.end(); it++) {
		cout << it->first << "\t";
		bool first = true;
		for(auto s = it->second.begin(); s!=it->second.end(); s++) {
			if(!first) {
				cout << " " << *s;
			}	else {
				cout << *s;
			}
			first = false;
		}
		cout << endl;
	}
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
