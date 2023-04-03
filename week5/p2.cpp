#include <iostream>
using namespace std;

class Node {
public:
	int data = 0;
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
	Node* head;
	Node* tail;
	Sequence() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
	Node* begin() { return head->next; }
	Node* end() { return tail; }
	void insert(Iterator& p, int e) { // prev -> new -> p.node, 더미노드여서 경우 고려 필요 없음
		Node* newNode = new Node; 
		newNode->data = e;

		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;

		newNode->next = p.node;
		p.node->prev = newNode;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
  		Sequence seq = Sequence();
		Iterator p = Iterator();
		p.node = seq.begin();

		int size;
		cin >> size;
		while (size--) {
			int data;
			cin >> data;
			seq.insert(p, data);
		}

		p.node = seq.begin(); // insert연산 수행하고 나면 p.node위치가 바뀌어있기 때문에 초기화 필요
		int m; // 명령어 수
		cin >> m;
		while (m--) { 
			int order;
			cin >> order;
			if (order < 0) {
				order = -order;
				while (order-- && p.node != seq.begin()) {
					--p;
				}
			}
			else {
				while (order--&& p.node != seq.end()) {
					 ++p;
				}
			}
			int info = p.node->data;
			if (info < 0) {
				info = -info;
				while (info--&& p.node != seq.begin()) {
					 --p;
				}
			}
			else {
				while (info--&& p.node != seq.end()) {
					++p;
				}
			}
		}
		cout << p.node->data << endl;
	}
}