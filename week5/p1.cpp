#include <iostream>
using namespace std;

class Node { // Iterator에서 node를 선언할때 class node라고 선언하면(이름 같으면) 채점서버에서 오류뜸
public:
	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};
class Iterator {
public:
	Node* node = nullptr;
	Iterator* operator++() { // operator: 연산자
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
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	Node* begin() { return head->next; } // 시작 위치 나타냄
	Node* end() { return tail; } // 끝 위치 나타냄
	void insert(Iterator& p, int e) { // prev -> new -> p
		Node* newNode = new Node();
		newNode->data = e;
		// 왼쪽 연결 - 기존에 있던 prev와 p.node를 이용해서 연결
		newNode->prev = p.node->prev;
		p.node->prev->next = newNode;

		newNode->next = p.node;
		p.node->prev = newNode;
		size++;
	}
	void erase(Iterator& p) { // prev -> p(delete) -> next
		if (size == 0) { cout << "empty" << endl; return; }
		else if (p.node == end()) { return; }
		Node* deleteNode = p.node;

		p.node->prev->next = p.node->next;
		p.node->next->prev = p.node->prev;
		p.node = begin();
		size--;

		delete deleteNode; // 삭제 연산할 때는 잊지말고 delete
	}
	void findmultiple(int e) {
		Node* curNode = head->next; // head->next부터 값 저장돼있음
		bool result = 0;
		int idx = 0;
		while (curNode!=tail) {
			if (curNode->data%e == 0) {
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

	string s;
	int n;
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
			seq.insert(p,data);
		}
		else if (s == "erase") {
			seq.erase(p);
		}
		else if (s == "nextP") {
			if(p.node!=seq.end()) ++p;
		}
		else if (s == "prevP") {
			if (p.node != seq.begin()) --p;
		}
		else if (s == "findmultiple") {
			int data;
			cin >> data;
			seq.findmultiple(data);
		}
	}
}