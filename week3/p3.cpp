#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class llStack {
private:
	int listSize;
	node* head;
public:
	llStack() {
		listSize = 0;
		head = NULL;
	}
	void size() {
		cout << listSize << endl;
	}
	bool empty() { return listSize == 0; }
	void top() {
		if (empty()) { cout << "-1" << endl; return; }
		cout << head->data << endl;
	}
	void push(int data) {
		node* newNode = new node;
		newNode->data = data;

		newNode->next = head;
		head = newNode;
		listSize++;
	}
	void pop() {
		if (empty()) { cout << "-1" << endl; return; }
		node* deleteNode = head;
		head = deleteNode->next;

		int result = deleteNode->data;
		listSize--;
		delete deleteNode;
		cout << result << endl;
	}
};
int main() {
	llStack st;
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "size") {
			st.size();
		}
		else if (s == "empty") {
			cout << st.empty() << endl;
		}
		else if (s == "top") {
			st.top();
		}
		else if (s == "push") {
			int k;
			cin >> k;
			st.push(k);
		}
		else if (s == "pop") {
			st.pop();
		}
	}
}
