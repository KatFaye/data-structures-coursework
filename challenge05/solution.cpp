// Challenge 05: BST

#include <climits>
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

bool isBST(int arr[], int min, int max, int n, int i);
// Main Execution
int main(int argc, char *argv[]) {

	int n, i = 0;
    
    string input;
    while(getline(cin, input)) {
    	i++;
    	stringstream ssinp(input);
    	ssinp >> n;

    	int arr[n];
    	for(int i=0; i<n; i++) {
    		ssinp >> arr[n];
            cout << arr[n] << " ";
    	
    	}
        cout << typeid(arr[0]).name() << " " << arr[0] + arr[1] << " " << endl;
    	bool bst = isBST(arr, INT_MIN, INT_MAX, n, 0);
    	if(bst)
    		cout << "Tree " << i << " is a BST\n";
    	else 
    		cout << "Tree " << i << " is not a BST\n";
    }

    return EXIT_SUCCESS;
}
bool isBST(int arr[], int min, int max, int n, int i) {
    bool result = true;
    if(arr[i] == -1) {
        return true;
    }
    if(arr[i] <= min || arr[i] > max) {
        cout << arr[i] << " min: " << min << " max: " << max;
        return false;
    }
    if((2*i)+1 < n) {
        result = isBST(arr, min, arr[i], n, (2*i)+1);
        if(!result) {
            return false;
        }
    }
    if((2*i)+2 < n) {
        result = isBST(arr, arr[i], max, n, (2*i)+2);
        if(!result) {
            return false;
        }
    }
    return result;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
