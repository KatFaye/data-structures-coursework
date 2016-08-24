// Challenge 01: Rotating Arrays
// Author: Kat Herring

// Main Execution

#include <iostream>
#include <vector> 
#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
void print(vector<char>);

int main(int argc, char *argv[]) {

	string input, input2;
	int n, r; //number, rotations
	char d, j; //direction
	vector<char> Cipher;

	//cout << "n r d" << endl;
	while (getline(cin, input)) { //works for 12 input -- fix

		Cipher.clear();
		string arr[3];
	    int i = 0;
	    stringstream ssin(input);
	    while (ssin.good() && i < 3){
	        ssin >> arr[i];
	        ++i;
	    }

	    stringstream convert(arr[0]);
	    convert>>n;
	    stringstream convert2(arr[1]);
	    convert2>>r;
	    stringstream convert3(arr[2]);
	    convert3>>d;
	    
	    getline(cin, input2);
	    stringstream ssinp(input2);
	    i = 0;
	    while (ssinp.good() && i < n) {
	    	ssinp >> j;
	    	Cipher.push_back(j);
	    	i++;
	    }
		//perform rotation
		if(d=='R' || d=='r') {
			//rotate to the right
			for(int k=0; k<=r-1; k++) {

				for(int j=0; j<=n-1; j++) {
					swap(Cipher[j], Cipher[n-1]);
					
				}
				//print(Cipher);
			}
		} else if(d=='L' || d=='l') {
			//rotate to the left
			for(int k=0; k<=r-1; k++) {
				for(int j=n-1; j>0; j--) {
					swap(Cipher[j], Cipher[0]);
					
				}
				//print(Cipher);
			}
		} else {
			cout << "Invalid input for direction." << endl;
			return EXIT_FAILURE;
		}

		//print output 
		print(Cipher);	
	}
	
    return EXIT_SUCCESS;
}
void print(vector<char> Cipher) {
	for(vector<char>::iterator it=Cipher.begin(); it!=Cipher.end(); ++it) {
		cout << *it;
		if(it!=Cipher.end()-1) {
			cout << " ";
		}
	}
	cout << endl;
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
