#include <iostream>
using namespace std;

class node {
private:
	int data;
	node* next;
public:
	node() {
		data = 0;
		next = nullptr;
	}
	~node() {
		data = 0;
		next = nullptr;
	}
	friend class singlyLinkedList;
};
class singlyLinkedList {
private:
	int listSize;
	node* head;
	node* tail;
public:
	singlyLinkedList() {
		head = NULL;
		tail = NULL;
		listSize = 0;
	}
	void print() {
		if (empty()) { cout << "empty" << endl; return; }
		node* curNode = head;
		while(curNode!=NULL) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	bool empty() { return listSize == 0; }
	void addFront(int data) { // 새로운 노드 삽입할 때는 동적할당
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;

		head = newNode;	
		listSize++;
	}
	void removeFront() {
		if (listSize == 0) { cout << "empty" << endl; return; }
		node* removeNode = head;
		head = removeNode->next;
		cout << removeNode->data << endl;
		listSize--;
	}
	void update(int idx, int data) {
		if (idx >= listSize) { cout << "error" << endl; return; }
		node* curNode = head;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		curNode->data = data;
	}
	void min() {
		int min = 10000;
		int idx=0; // 최솟값의 위치
		if (listSize == 0) { cout << "empty" << endl; return; }
		node* curNode = head;
		int i = 0;
		while(curNode!=NULL) {
			if (curNode->data < min) { // 같은 경우는 포함 안 되있으니까 그대로 감
				min = curNode->data;
				idx = i;
			}
			curNode = curNode->next;
			i++;
		}
		cout << idx << " " << min << endl;
	}
};
int main() {
	singlyLinkedList dudtls;
	int m, idx, data;
	string s;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "Print") {
			dudtls.print();
		}
		else if (s == "AddFront") {
			cin >> data;
			dudtls.addFront(data);
		}
		else if (s == "RemoveFront") {
			dudtls.removeFront();
		}
		else if (s == "Update") {
			cin >> idx >> data;
			dudtls.update(idx, data);
		}
		else if (s == "Min") {
			dudtls.min();
		}
	}
}