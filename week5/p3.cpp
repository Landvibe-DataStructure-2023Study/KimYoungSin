#include <iostream>
using namespace std;

class Node {
public:
	int data = 0; // public에다가만 쓰니까 초기화도 같이
	Node* next = nullptr;
	Node* prev = nullptr;
};
class Iterator {
public:
	Node* node = nullptr;
	Iterator* operator++() {
		node = node->next;
		return this;
	}
	Iterator* operator--() {
		node = node->prev;
		return this;
	}
};
class Sequence {
public:
	int size;
	Node* head;
	Node* tail;
	Sequence() {
		head = new Node;
		tail = new Node;
		size = 0;
		head->next = tail;
		tail->prev = head;
	}
	Node* begin() { return head->next; }
	Node* end() { return tail; }

	void insert(Iterator& p, int e) { // prev -> new -> p.node
		Node* newNode = new Node;
		newNode->data = e;
		// 왼쪽
		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		//오른쪽
		p.node->prev = newNode;
		newNode->next = p.node;
		size++;
	}
	void erase(Iterator& p) { // prev -> p.node -> next;
		if (size == 0) { cout << "empty" << endl; return; }
		if (p.node == end()) { return; }
		Node* deleteNode = p.node;

		p.node->prev->next = p.node->next;
		p.node->next->prev = p.node->prev;
		p.node = begin();
		
		size--;
		delete deleteNode;
	}
	void findDivisor(int e) {
		Node* curNode = head->next; // head->next부터 값 저장돼있음
		bool result = 0;
		int idx = 0;
		while (curNode != tail) {
			if (e % curNode->data == 0) {
				cout << idx << " ";
				result = 1;
			}
			curNode = curNode->next;
			idx++;
		}
		if (result == 0) cout << "-1";
		cout << endl;
	}
};
int main() {
	Sequence seq = Sequence();
	Iterator p = Iterator();
	p.node = seq.begin();

	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "begin") {
			p.node = seq.begin();
		}
		else if (s == "end") {
			p.node = seq.end();
		}
		else if (s == "insert") {
			int data;
			cin >> data;
			seq.insert(p, data);
		}
		else if (s == "erase") {
			seq.erase(p);
		}
		else if (s == "nextP") {
			if (p.node != seq.end()) ++p;
		}
		else if (s == "prevP") {
			if (p.node != seq.begin()) --p;
		}
		else if (s == "finddivisor") {
			int data;
			cin >> data;
			seq.findDivisor(data);
		}
	}
}