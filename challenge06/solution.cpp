// Challenge 06: Lowest Common Ancestor

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Main Execution

struct Node {
	int val;
	Node * left;
	Node * right;
};
class bst {

public:
	bst();
	~bst();
	void insert(int val);
	int commonAncestor(int a, int b);
	void print();
private:
	vector<int> find(int val); //returns vector of path to node
	void insert(int val, Node * curr); //add value to bst
	void delBST(Node * curr); //delete bst
	void print(Node * curr); //inorder traversal
	Node * root;
};

int main(int argc, char *argv[]) {

	int inp, a, b;
	string num, input;
	bool first = true;

	getline(cin, num);
	while(num!="-1") {
		if(!first) 
			cout << endl;
		first = false;
		bst tree;
		getline(cin, input); //read in tree
		stringstream nodes(input);
		for(int i=0;i<stoi(num);i++) {
			nodes >> inp; //convert input to int
			tree.insert(inp);
		}
		//tree.print();
		getline(cin, num); //number of pairs
		for(int i=0;i<stoi(num);i++) {
			getline(cin, input); //numbers to find ancestor for
			stringstream nodes(input);
			nodes >> a >> b;
			//cout << a << " " << b << endl;
			cout << tree.commonAncestor(a, b) << endl;
		}

		getline(cin, num);
	}
    return EXIT_SUCCESS;
}
bst::bst() {
	root = nullptr;
}
bst::~bst() {
	delBST(root);
}
void bst::insert(int val, Node * curr) {

	if(val < curr->val) { // go to left subtree
		if(curr->left!=nullptr)
			insert(val, curr->left);
		else {
			curr->left = new Node;
			Node * newNode = curr->left;
			newNode->val = val;
			newNode->left = nullptr;
			newNode->right = nullptr;
		}
	} else { //go to right subtree
		if(curr->right!=nullptr)
			insert(val, curr->right);
		else {
			
			curr->right = new Node;
			Node * newNode = curr->right;
			newNode->val = val;
			newNode->left = nullptr;
			newNode->right = nullptr;
		}
	}

}
void bst::insert(int val) {
	if(root!=nullptr)
		insert(val, root);
	else {
		root = new Node;
		root->val = val;
		root->left = nullptr;
		root->right = nullptr;
	}
}
void bst::print() {
	print(root);
	cout << endl;
}
void bst::print(Node * curr) {
	if (curr == nullptr) {
		return;
	}
	print(curr->left);

	cout << curr->val << " ";

	print(curr->right);
}
void bst::delBST(Node * curr) {
	if(curr!=nullptr) {
		delBST(curr->right);
		delBST(curr->left);
		delete curr;
	}
}
int bst::commonAncestor(int a, int b) {
	int result = -1; //no common ancestor found

	//cout << "Search for " << a << ": ";
	vector<int> aVec = find(a);
	//cout << endl;
	//cout << "Search for " << b << ": ";
	vector<int> bVec = find(b);

	for(int i : aVec) {
		for(int j : bVec) {
			if(i==j)
				result = i; //set result to common value
		}
	}
	return result;
}
vector<int> bst::find(int val) {
	Node * loc = root; //start searching at root
	vector<int> result;

	while(loc->val!=val) {
		result.push_back(loc->val);
	//	cout << loc->val << " ";
		if(val<loc->val) { //search left subtree
			loc = loc->left;
		} else { //search right subtree
			loc = loc->right;
		}
	}
	result.push_back(loc->val); //push_back value itself
	//cout << loc->val << endl;
	return result;
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
