// Challenge 03: Closest Numbers

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {

	int n, num;
	vector<int> nums;
	vector<pair<int, int>> smallest;
	string input;
	pair<int, int> p;

	while(getline(cin, input)) {
		/*if(input.empty()) {
			getline(cin, input);
		}*/
		nums.clear();
		smallest.clear();

		stringstream ssinp(input);
		ssinp >> n;

		getline(cin, input);
		istringstream ssin(input);
		int i = 0;
		//get input
		while(ssin.good() && i < n) {
			ssin >> num;
			nums.push_back(num);
			++i;
		}
		//sort input
		sort(nums.begin(), nums.end());

		int diff = 0, min=INT_MAX;
		//find max distance
		for(auto it = nums.begin(); it!=nums.end()-1; ++it) {
			diff = *(it+1) - *it;
			if(diff<min) { //new smallest difference
				min = diff;
				p = make_pair(*it, *(it+1));
				smallest.clear();
				smallest.push_back(p);
				
			} else if(diff==min) { //same difference
				p = make_pair(*it, *(it+1));
				smallest.push_back(p);
				
			}
		}
		//output min
		bool first = true;
		for(const pair<int, int> &it : smallest) {
			
			if(!first)
				cout << " " << it.first << " " << it.second;
			else 
				cout << it.first << " " << it.second;

			first = false;
		}
		cout << endl;


	}

    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
