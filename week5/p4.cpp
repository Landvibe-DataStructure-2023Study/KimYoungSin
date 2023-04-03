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
	int size;
	Sequence() {
		size = 0;
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
		size++;
	}
	void result(int size, int index) { // index는 0부터 시작
		if (size % 2 == 1 && (size / 2) + 1 == index + 1) cout << "middle" << endl; // 중앙값
		else if (index + 1 <= size / 2) cout << "header" << endl;
		else { cout << "trailer" << endl; }
	}
};

int main() {
	int n;
	cin >> n;
	while (n--) {
		Sequence seq = Sequence();
		Iterator p = Iterator();
		p.node = seq.begin();

		int k;
		cin >> k;
		while (k--) {
			int data;
			cin >> data;
			seq.insert(p, data);
		}
		p.node = seq.begin();

		int idx = 0; // 최종 위치의 인덱스
		int m;
		cin >> m;
		while (m--) {
			int order;
			cin >> order;
			if (order < 0) {
				order = -order;
				while (order-- && p.node != seq.begin()) {
					--p;
					idx--;
				}
			}
			else {
				while (order-- && p.node != seq.end()) {
					++p;
					idx++;
				}
			}
			int info = p.node->data;
			if (info < 0) {
				info = -info;
				while (info-- && p.node != seq.begin()) {
					--p;
					idx--;
				}
			}
			else {
				while (info-- && p.node != seq.end()) {
					++p;
					idx++;
				}
			}
		}
		seq.result(seq.size,idx);
	}
}