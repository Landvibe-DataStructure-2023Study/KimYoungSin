#include <iostream>
using namespace std;

int n;
class arrQueue {
public:
	int arr[10000];
	int frontIdx = 0;
	int rearIdx = -1;
	int size = 0;

	void updateIdx() { // 원형큐 인덱스값 정리
		frontIdx %= n;
		rearIdx %= n;
	}
	int isSize() {
		return size;
	}
	bool isEmpty() { return size == 0; }
	bool full() { return size == n; }
	void front() {
		if (isEmpty()) { cout << "Empty" << endl; return; }
		cout << arr[frontIdx] << endl;
	}
	void rear() {
		if (isEmpty()) { cout << "Empty" << endl; return; }
		cout << arr[rearIdx] << endl;
	}
	void enqueue(int x) {
		if (full()) { cout << "Full" << endl; return; }
		rearIdx++;
		updateIdx();
		arr[rearIdx] = x;
		size++;
	}
	void dequeue() {
		if (isEmpty()) { cout << "Empty" << endl; return; }
		cout << arr[frontIdx] << endl;
		frontIdx++;
		updateIdx();
		size--;
	}
};
int main() {
	arrQueue q;
	string s;
	int k; // 명령어 개수
	cin >> n >> k;
	while (k--) {
		cin >> s;
		if (s == "size") {
			cout << q.isSize() << endl;
		}
		else if (s == "isEmpty") {
			if (q.isEmpty()) { cout << "True" << endl; }
			else cout << "False" << endl;
		}
		else if (s == "full") {
			if (q.full()) { cout << "True" << endl; }
			else cout << "False" << endl;
		}
		else if (s == "front") {
			q.front();
		}
		else if (s == "rear") {
			q.rear();
		}
		else if (s == "enqueue") {
			int data;
			cin >> data;
			q.enqueue(data);
		}
		else if (s == "dequeue") {
			q.dequeue();
		}
	}
}