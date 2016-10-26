
// Challenge 07: Linked List Deduplication
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

// Structures
struct Node {
	int data;
	Node * next;
};
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void addNode(const int value); //add to end of list
	void print();
	void deleteNode(Node * &del);
	void deduplicate(); //removes duplicates from list
private:
	Node * head;
};
LinkedList::LinkedList() {
	head = nullptr;
}
LinkedList::~LinkedList() {
	Node * it = head;
	Node * next = head;

	while(it) {
		next = it->next;
		delete it;
		it = next;
	}
}
void LinkedList::addNode(const int value) { //adds to end of list
	Node * temp = new Node{value, nullptr};

	if(!head) {
		head = temp;
	} else {
		Node * last = head;
		while(last->next) {
			last = last->next;
		}
		last->next = temp;
	}
}
void LinkedList::deleteNode(Node * &del) {

	Node * prev = head;
	if(prev==del) {
		head = nullptr;
		delete del;
		return;
	}
	while(prev->next && prev->next != del) {
		prev = prev->next;
	} 
	if(prev->next) {
		prev->next = prev->next->next;
	}

	delete del;
}
void LinkedList::print() {
	Node * it = head;
	bool first = true;

	while(it) {
		if(first)
			cout << it->data;
		else
			cout << " " << it->data;
		first = false;
		it = it->next;
	}
	cout << endl;
}
void LinkedList::deduplicate() {
	unordered_set<int> deduplicate;
	Node * it = head;
	Node * temp = head;
	while(it) {
		auto search = deduplicate.find(it->data);

		if(search!=deduplicate.end()) {
			temp = it;
			it = temp->next;
			//cout << "found " << it->data << endl;
			deleteNode(temp);	
			

		} else {
			deduplicate.insert(it->data);
			it = it->next;
		}
		
	}
}
int main(int argc, char *argv[]) {
	//get input and store into linked list
 	int n, value;
 	string input;

 	while(getline(cin, input)) {
 		stringstream convert(input);
 		convert >> n;

 		LinkedList list;
 		getline(cin, input);

 		stringstream ssinp(input);
 		for(int i=0; i<n; i++) {
 			ssinp >> value;
 			list.addNode(value);
 		}
 		list.deduplicate();
 		list.print();

 	}
 	

 	return EXIT_SUCCESS;
}