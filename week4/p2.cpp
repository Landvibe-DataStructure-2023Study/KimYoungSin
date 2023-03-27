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
	int front() {
		return head->data;
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
	int dequeue() {
		node* deleteNode = head;
		int result = head->data;

		head = deleteNode->next;
		delete deleteNode;
		size--;
		return result;
	}
};
void print(int i, int front1, int front2, int score1, int score2) {
	cout << "Round" << i << " " << front1;
	if (front1 > front2) cout << ">";
	else if (front1 < front2) cout << "<";
	else cout << "=";
	cout << front2 << " " << score1 << ":" << score2 << endl;
}

int main() {
	Queue one, two;
	int n, k, data; // k = 몇 번 enqueue?, data = enqueue data
	cin >> n;
	while (n--) {
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> data;
			one.enqueue(data);
		}
		for (int i = 0; i < k; i++) {
			cin >> data;
			two.enqueue(data);
		}
		int score1 = 0, score2 = 0; // 총점
		int plus = 0; // 이긴 쪽에 더해줄 점수
		for (int i = 1; i <= k; i++) {
			int a = one.dequeue();
			int b = two.dequeue();

			if (plus > 0) { a += plus; }
			else if (plus < 0) {
				plus = -plus; b += plus;
			}
			plus = a - b;
			if (plus > 0) {	score1++;}
			else if (plus < 0) { score2++;}
			print(i, a, b, score1, score2);
		}
		if (score1 > score2) cout << "Winner p1" << endl;
		else if (score1 < score2) cout << "Winner p2" << endl;
		else cout << "Draw" << endl;
	}
}