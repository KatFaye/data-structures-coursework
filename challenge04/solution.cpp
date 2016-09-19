// Challenge 04: Card Rank

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Main Execution
struct Person {

	string name;
	int val;
	int suit;
};

bool gVal(Person const& a, Person const& b) {

	if(a.val==b.val)
		return a.suit > b.suit;
	else
		return a.val > b.val;
}
void print(vector<Person> people) {

	bool first = true;

	for(auto it=people.begin(); it!=people.end(); it++) {
		
		if(!first)
			cout << ", " << (*it).name;
		else
			cout << (*it).name;

		first = false;
	}
	cout << endl;
}
int convertToInt(string val) {
	int value;

	if(val=="J")
		return 11;
	if(val=="Q")
		return 12;
	if(val=="K")
		return 13;
	if(val=="A")
		return 14;
	else {
		stringstream convert(val);
		convert >> value;
		return value;
	}
}
int conSuit(char suit) {
	//clubs, diamonds, hearts, spades
	if(suit=='C')
		return 1;
	if(suit=='D')
		return 2;
	if(suit=='H')
		return 3;
	if(suit=='S')
		return 4;
	else
		return 0; //error
}
int main(int argc, char *argv[]) {
    

    string num, input, val;
    char suit;
    vector<Person> people;
    getline(cin,num);
    while(num != "-1") {

    	people.clear();

    	for(int i=0;i<stoi(num);i++) {
    		getline(cin, input);
    		stringstream persons(input);
    		Person p;
    		persons >> p.name;
    		
    		persons >> val;
    		p.val = convertToInt(val);
    		persons >> suit;
    		p.suit = conSuit(suit);
    		people.push_back(p);

    	}
    	getline(cin,num);
    	sort(people.begin(), people.end(), &gVal);
    	print(people);
    }
    
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
