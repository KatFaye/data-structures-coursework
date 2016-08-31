// Challenge 02: Adding List-Based Integers


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct node {
	T data;
	node *next;
};
template <typename T>
class List {
public:
	node<T>* head = nullptr;
	int size;
	void addNode(T);
	void print();
	List<T> addLists(List<T>, List<T>);
	void clear();
};

// Main Execution
int main(int argc, char *argv[]) {

	string input, number;
	int i = 0, n;
	List<int> a[3];

	//output result

	while(getline(cin, input)) {
	//getline(cin, input);
		stringstream nums(input);
		while (nums >> number) {
			a[i].size = 0;
			for(char& digit : number) {
				n = (int)digit - '0'; //convert to int
				a[i].addNode(n);
				a[i].size++;
			}
			i++;
		}
	
	//a[0].print();
	//a[1].clear();
	//a[1].print();

		a[2] = a[0].addLists(a[0], a[1]);
		a[2].print();
	for(int i = 0;i<3;i++) {
			a[i].clear();
		}
	}
    return 0;
}
template <typename T>
void List<T>::addNode(T num) { //adds to front
	node<T>* temp = new node<T>;
	temp->data = num;
	temp->next = head;
	head = temp;
}
template <typename T>
void List<T>::print() {
	node<T>* curr;
	curr = head;

	while(curr!=nullptr) {
		cout << curr->data;
		curr = curr->next;
	}
	cout << endl;
}
template <typename T>
List<T> List<T>::addLists(List<T> a, List<T> b) {

//determine which is larger (if applicable)
	List<T> c;
	int cin = 0, cout, s, sum;
	node<T> *larger, *smaller;

	if (a.size > b.size) {
		larger = a.head;
		smaller = b.head;
	} else {
		larger = b.head;
		smaller = a.head;
	}

	while(larger!=nullptr) {
		if(smaller!=nullptr) {
			s = smaller->data;
		} else {
			s = 0;
		}
		sum = larger->data + s + cin;
		if(sum>=10) {
			sum = sum - 10;
			cout = 1;
		} else {
			cout = 0;
		}
		c.addNode(sum);
		larger = larger->next;
		if(smaller!=nullptr)
			smaller = smaller-> next;
		cin = cout;
	}
	if(cin==1) { //overflow on last addition
		c.addNode(1);
	}

	return c;
}
template <typename T>
void List<T>::clear() {

    node<T> *temp = head;
    while(temp->next) {
           temp = head->next;
           delete head;
           head = temp;
   }
}
// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
