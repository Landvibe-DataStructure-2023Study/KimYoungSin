#include <iostream>
using namespace std;

struct node {
	node* next;
	int data;
};
class Queue {
public:
	int size = 0;
	node* head = NULL;
	node* tail = NULL;

	bool empty() { return size == 0; }
	void isSize() { cout << size << endl; }
	void front() {
		if (empty()) { cout << "Empty" << endl; return; }
		cout << head->data << endl;
	}
	void rear() {
		if (empty()) { cout << "Empty" << endl; return; }
		cout << tail->data << endl;
	}
	void enqueue(int x) {
		node* newNode = new node;
		newNode->next = NULL;
		newNode->data = x;

		if (empty()) { head = tail = newNode; }
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void dequeue() {
		if (empty()) { cout << "Empty" << endl; return; }
		node* deleteNode = head;
		int result = deleteNode->data;

		head = deleteNode->next;
		delete deleteNode;
		size--;
		cout << result << endl;
	}
};
int main() {
	Queue q;
	string s;
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		if (s == "isEmpty") {
			if (q.empty()) { cout << "True" << endl; }
			else cout << "False" << endl;
		}
		else if (s == "size") {
			q.isSize();
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
		else if (s == "enqueue") {
			int x;
			cin >> x;
			q.enqueue(x);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}