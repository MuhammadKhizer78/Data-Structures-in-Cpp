#include <iostream>
using namespace std;

// =====================================
// NODE CLASS — represents one node
// =====================================
class node {
public:
	int val;     // stores data value
	node *next;  // pointer to the next node

	// constructor to assign value and set next = null
	node(int v) {
		val = v;
		next = nullptr;
	}
};

// =====================================
// LINKED LIST CLASS
// =====================================
class linkedlist {
private:
	node *head;   // points to the first node
	int length;   // keeps count of how many nodes exist

public:
	// constructor to initialize an empty list
	linkedlist() {
		head = nullptr;
		length = 0;
	}

	// ===========================
	// INSERT FUNCTION
	// ===========================
	void insert(int val, int pos) {

		// check if position is valid
		if (pos < 1 || pos > length + 1) {
			cout << "invalid position" << endl;
			return;
		}

		// create a new node using given value
		node *n = new node(val);

		// if inserting at start (1st position)
		if (pos == 1) {
			n->next = head; // link new node to old head
			head = n;       // move head to new node
		}
		else {
			// pointer to traverse till the node before the position
			node *current = head;

			// move (pos - 1) steps
			for (int i = 1; i < (pos - 1); i++) {
				current = current->next;
			}

			// connect the new node in the chain
			n->next = current->next;
			current->next = n;
		}

		length++; // increase total nodes
	}

	// ===========================
	// GET VALUE FUNCTION
	// ===========================
	void getval(int pos) {

		// validate position
		if (pos < 1 || pos > length) {
			cout << "invalid position" << endl;
			return;
		}

		// check if list is empty
		if (length == 0) {
			cout << "list is empty" << endl;
			return;
		}

		node *current = head;

		// move pointer to given position
		for (int i = 1; i < pos; i++) {
			current = current->next;
		}

		cout << "value at position " << pos << " = " << current->val << endl;
	}

	// ===========================
	// UPDATE VALUE FUNCTION
	// ===========================
	void updateval(int val, int pos) {

		if (pos < 1 || pos > length) {
			cout << "invalid position" << endl;
			return;
		}

		if (length == 0) {
			cout << "list is empty" << endl;
			return;
		}

		node *current = head;

		// move till position
		for (int i = 1; i < pos; i++) {
			current = current->next;
		}

		// change the node’s value
		current->val = val;
	}

	// ===========================
	// REMOVE BY POSITION FUNCTION
	// ===========================
	void removeval(int pos) {

		if (pos < 1 || pos > length) {
			cout << "invalid position" << endl;
			return;
		}

		if (length == 0) {
			cout << "list is empty" << endl;
			return;
		}

		node *current = head;

		// deleting the first node
		if (pos == 1) {
			head = head->next; // move head to next node
			delete current;    // delete old head
		}
		else {
			// move till node before the one to delete
			for (int i = 1; i < pos - 1; i++) {
				current = current->next;
			}

			// node to delete
			node *temp = current->next;

			// skip the deleting node
			current->next = temp->next;

			delete temp;
		}

		length--; // decrease count
	}

	// ===========================
	// CLEAR LIST FUNCTION
	// ===========================
	void clear() {
		// keep removing head node until list is empty
		while (head != nullptr) {
			removeval(1);
		}
	}

	// ===========================
	// DISPLAY FUNCTION
	// ===========================
	void display() {
		node *current = head;

		cout << "Linked List: ";
		while (current != nullptr) {
			cout << current->val << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	// ===========================
	// REMOVE BY VALUE FUNCTION
	// ===========================
	void removebyval(int val) {

		if (length == 0) {
			cout << "the list is empty" << endl;
			return;
		}

		// if the value is in the first node
		if (head->val == val) {
			node *temp = head;
			head = head->next;
			delete temp;
			length--;
			return;
		}

		node *current = head;

		// move until next node matches value or reach end
		while (current->next != nullptr && current->next->val != val) {
			current = current->next;
		}

		// if reached end, not found
		if (current->next == nullptr) {
			cout << "value not found" << endl;
			return;
		}

		// delete the matching node
		node *temp = current->next;
		current->next = temp->next;
		delete temp;
		length--;
	}

	// ===========================
	// FIND FUNCTION
	// ===========================
	int find(int val) {

		if (head == nullptr) {
			cout << "list is empty" << endl;
			return -1;
		}

		node *current = head;
		int pos = 1; // start position count

		// traverse until value found or list ends
		while (current != nullptr && current->val != val) {
			current = current->next;
			pos++;
		}

		if (current == nullptr) {
			cout << "value not found" << endl;
			return -1;
		}

		cout << "value found at position " << pos << endl;
		return pos;
	}

	// ===========================
	// COPY FUNCTION
	// ===========================
	void copylinkedlist(linkedlist &list) {

		// first clear current list to avoid mixing
		clear();

		// if other list is empty
		if (list.head == nullptr) {
			head = nullptr;
			length = 0;
			return;
		}

		// pointer to the source list
		node *current = list.head;
		int pos = 1;

		// insert all values one by one into this list
		while (current != nullptr) {
			insert(current->val, pos);
			pos++;
			current = current->next;
		}
	}
};

// =====================================
// MAIN FUNCTION — TEST THE CLASS
// =====================================
int main() {

	linkedlist list; // creating a linked list object

	// inserting nodes
	list.insert(10, 1);
	list.insert(20, 2);
	list.insert(30, 3);
	list.display();

	// get value from a position
	list.getval(2);

	// update a value at position
	list.updateval(25, 2);
	list.display();

	// remove by position
	list.removeval(1);
	list.display();

	// remove by value
	list.removebyval(100);
	list.display();

	// find a value in list
	list.find(56);
	list.display();

	// clear the list
	list.clear();
	list.display();

	// create another list and copy it
	linkedlist list1;
	list1.insert(5, 1);
	list1.insert(15, 2);
	list1.insert(25, 3);
	list1.display();

	// copy list1 into list2
	linkedlist list2;
	list2.copylinkedlist(list1);
	list2.display();

	return 0;
}
