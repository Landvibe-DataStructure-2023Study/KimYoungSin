#include <iostream>
using namespace std;

class arrayStack {
private:
	int maxSize;
	int top;
	int* arr;
public:
	arrayStack(int size) {
		maxSize = size;
		arr = new int[size]; // ������ �ʴ� size ũ��� �����Ҵ�
		top = -1;
	}
	int size() { // 0��° �ε������� ���� �ִٸ�, 1�� ũ��ϱ�
		return top + 1;
	}
	bool empty() { return top == -1; }
	bool full() { return size() == maxSize; }
	void isTop() {
		if (empty()) { cout << "-1" << endl; return; }
		cout << arr[top] << endl;
	}
	void push(int data) {
		if (size() == maxSize) { cout << "FULL" << endl; return; }
		arr[++top] = data;
	}
	void pop() {
		if (empty()) { cout << "-1" << endl; return; }
		cout << arr[top--] << endl;
	}
};
int main() {
	int t, n;
	string s;
	cin >> t >> n;
	arrayStack st(t);

	while (n--) {
		cin >> s;
		if (s == "size") {
			cout << st.size() << endl;
		}
		else if (s == "empty") {
			cout << st.empty() << endl;
		}
		else if (s == "full") {
			cout << st.full() << endl;
		}
		else if (s == "top") {
			st.isTop();
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