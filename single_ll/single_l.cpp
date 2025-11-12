#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Node {
public:
	int key;
	string data;
	string timestamp;
	Node *next;

	Node(int k, string d)
	{
		key = k;
		data = d;
		timestamp = getCurrentTime();
		next = NULL;

	}
	static string getCurrentTime()
	{	time_t now = time(0);
		char* dt = ctime(&now);
		string ts(dt);
		ts.pop_back();
		return ts;
	}

};
class List {
	Node *head;
	Node *tail;
public:
	List() {
		head = tail = NULL;
	}

	void push_front(int key, string data) {
		Node *newNode = new Node(key,data);
		if (head == NULL) {
			head = tail = newNode;
			return;

		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		cout << "Block inserted at front.";
	}
	void push_back(int key,string data) {
		Node *newNode = new Node(key,data);
		if (head == NULL) {
			head = tail = newNode;

		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cout << "Block inserted at back.";
	}
	void insert(int key, string data, int pos) {
		if (pos < 0)
		{
			cout << "Invalid Position.";
		}
		if (pos == 0)
		{
			push_front(key,data);
			return;

		}
		Node *temp = head;
		for (int i = 0; i < pos - 1; i++) {
			if(temp == NULL) {
				cout << "Invalid Position.";
				return;
			}
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "Invalid Position.\n";
			return;

		}
		Node *newNode = new Node(key,data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
	void pop_front() {
		if (head == NULL) {
			cout << "List is empty.";
			return;

		}
		Node *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		cout << "Block deleted successfully.";

	}
	void pop_back() {
		if (head == NULL) {
			cout << "List is empty.";
			return;
		}
		if(head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			Node *temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail = temp;
		}

	}

	void deleteKey(int key) {
		if (head == NULL) {
			cout << "List is empty";
			return;
		}
		if(head-> key == key) {
			pop_front();
			return;
		}
		Node* temp = head;
		while(temp -> next && temp-> next -> key !=key) {
			temp = temp-> next;
		}
		if(!temp->next) {
			cout << "Block not found.";
			return;

		}
		Node* toDel = temp ->next;
		temp -> next = toDel -> next;
		if(toDel == tail ) {
			tail = temp;

		}
		delete toDel;
		cout << "Block deleted.";

	}
	void printLL() {
		if (head == NULL) {
			cout << "Blockchain is empty.\n";
			return;
		}
		Node *temp = head;
		cout << "\n--- Blockchain ---\n";
		while (temp != NULL) {
			cout << "[Key: " << temp->key << " | Data: " << temp->data << " | Time: " << temp->timestamp << "] -> ";
			temp = temp->next;
		}
		cout << "NULL\n" << endl;
	}

};
int main() {
	List blockchain;
	int choice, key, pos;
	string data;
	while (true) {
		cout << "\n===== Blockchain Menu =====\n";
		cout << "1. Insert Block at beginning\n";
		cout << "2. Insert Block at end\n";
		cout << "3. Insert Block in between\n";
		cout << "4. Delete Block from beginning\n";
		cout << "5. Delete Block from end\n";
		cout << "6. Delete Block by key\n";
		cout << "7. Display Blockchain\n";
		cout << "8. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter key & data: ";
			cin >> key >> data;
			blockchain.push_front(key, data);
			break;

		case 2:
			cout << "Enter key & data: ";
			cin >> key >> data;
			blockchain.push_back(key, data);
			break;

		case 3:
			cout << "Enter key & data: ";
			cin >> key >> data;
			cout << "Insert At Position: ";
			cin >> pos;
			blockchain.insert(key, data, pos);
			break;

		case 4:
			blockchain.pop_front();
			break;

		case 5:
			blockchain.pop_back();
			break;

		case 6:
			cout << "Enter key to delete: ";
			cin >> key;
			blockchain.deleteKey(key);
			break;

		case 7:
			blockchain.printLL();
			break;

		case 8:
			cout << "Exiting...\n";
			return 0;

		default:
			cout << "Invalid choice. Try again.\n";
		}

	}

}