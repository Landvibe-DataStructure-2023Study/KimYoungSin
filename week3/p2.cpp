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
	bool empty() { return listSize == 0; }
	int top() {
		return head->data;
	}
	void push(int data) {
		node* newNode = new node;
		newNode->data = data;

		newNode->next = head;
		head = newNode;
		listSize++;
	}
	int pop() {
		node* deleteNode = head;
		head = deleteNode->next;

		int result = deleteNode->data;
		listSize--;
		delete deleteNode;
		return result;
	}
};
int result(int x) { // �� �ڸ��� �����ִ� �Լ�
	if (x < 0) x = -x;
	int sum = 0;
	while (x != 0) {
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}
int main() {
	llStack st;
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '1' && s[i] <= '9') {
				st.push(s[i] - '0');
			}
			else {
				int b = st.pop(); // '-' ������ ���� pop�ϴ� ������ �߿�
				int a = st.pop();
				switch (s[i]) {
				case '+': st.push(a + b); break;
				case '-': st.push(a - b); break;
				case '*': st.push(a * b); break;
				}
			}
		}
		cout << result(st.pop()) << endl;
	}
}