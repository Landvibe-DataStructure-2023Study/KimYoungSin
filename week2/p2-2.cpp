#include <iostream>
using namespace std;

class node {
	node* next;
	node* prev;
	int data;
	
	friend class LinkedList;
};
class LinkedList {
private:
	node* head;
	node* tail;
	int listSize=0;
public:
	LinkedList() { // head�� tail�� ���ο� ���� ���̶� ���� �ھƳ���
		head = new node;
		tail = new node;
		head->next = tail; // �ʱⰪ(�ƹ��͵� ���� �Ŷ� �Ȱ�����)
		tail->prev = head;
		head->data = 10000;
		tail->data = 10000;
		listSize = 0;
	}
	bool empty() { return head->next==tail; }
	void print() {
		if (head->next == tail) {
			cout << "empty" << endl;
			return;
		}
		node* curNode = head->next;
		while(curNode != tail) {
			cout << curNode->data << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}
	// ������ ���<->������ ����� �������
	// ������ ���<->������ ����� ������� => ���� �� �� ���� �ʿ�
	void insert(int idx, int data) {
		if (idx > listSize) { cout << "error" << endl; return; }
		node* newNode = new node;
		newNode->data = data; // �ݵ�� �ʱ�ȭ
		
		node* nextNode = head -> next;
		for (int i = 0; i < idx; i++) {
			nextNode = nextNode->next;
		}
		node* preNode = nextNode->prev; // prev -> new -> next

		newNode->prev = preNode;
		preNode->next = newNode;
		nextNode->prev = newNode;
		newNode->next = nextNode;
		listSize++;
	}
	void remove(int idx) {
		if (empty() || idx >= listSize) { cout << "error" << endl; return; }
		node* newNode = new node;
		newNode = head->next; // ���̳�� ����ϰ� �����Ƿ� head�� �ƴ϶� head->next
		for (int i = 0; i < idx; i++) {
			newNode = newNode->next;
		}
		node* preNode = newNode->prev; // prev -> new -> next
		node* nextNode = newNode->next;

		preNode->next = newNode->next;
		nextNode->prev = newNode->prev;
		int result = newNode->data;
		delete newNode;
		listSize--;
		cout << result << endl;
	}
	void removeAll(int data) {
		int cnt = 0;
		node* curNode = head->next;
		
		while (curNode != tail) { // pre -> cur -> next
			if (curNode->data == data) {
				node* preNode = curNode->prev;
				node* nextNode = curNode->next;

				preNode->next = nextNode;
				nextNode->prev = preNode;
				listSize--;
				cnt++;
			}
			curNode = curNode->next;
		}
		if (cnt == 0 || empty()) { cout << "not found" << endl; return; }
		else { cout << cnt << endl;  }
	}
	void neighbor(int idx) {
		if (idx >= listSize) { cout << "error" << endl; return; }
		node* curNode = head->next;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		node* preNode = curNode->prev;
		node* nextNode = curNode->next;
		int min;
		if (idx == 0) { cout << nextNode->data << endl; }
		else if (idx == listSize - 1) { cout << preNode->data << endl; }
		else {
			if (preNode->data < nextNode->data) { min = preNode->data; }
			else { min = nextNode->data; }
			cout << min << endl;
		}
	}
};
int main() {
	LinkedList dudtls;
	int m, idx, data;
	string s;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "Print") {
			dudtls.print();
		}
		else if (s == "Insert") {
			cin >> idx >> data;
			dudtls.insert(idx, data);
		}
		else if (s == "Remove") {
			cin >> idx;
			dudtls.remove(idx);
		}
		else if (s == "RemoveAll") {
			cin >> data;
			dudtls.removeAll(data);
		}
		else if (s == "NeighborMin") {
			cin >> idx;
			dudtls.neighbor(idx);
		}
	}
	return 0;
}