#include <iostream>
using namespace std;

struct node {
	char data;
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
	char top() {		
		return head->data;
	}
	void push(int data) {
		node* newNode = new node;
		newNode->data = data;

		newNode->next = head;
		head = newNode;
		listSize++;
	}
	char pop() {
		node* deleteNode = head;
		head = deleteNode->next;

		char result = deleteNode->data;
		listSize--;
		delete deleteNode;
		return result;
	}
};
int precedence(char op) { // 연산자 우선순위 비교
	switch (op) {
	case ')': return 0; break;
	case '+': case'-': return 1; break;
	case '*': return 2; break;
	}
}
int main() {
	llStack st;
	int t, cnt = 0;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= '1' && s[i] <= '9') {
				cout << s[i];
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
				while (!st.empty()) {
					if (precedence(st.top()) >= precedence(s[i])) {
						cout << st.pop();
					}
					else break;
				}
				if(st.empty()) cnt++; // 스택이 비어있을 때를 체크해야되므로 push하기 전에 cnt++ 해야됨
				st.push(s[i]);
			}
			
		}
		while (!st.empty()) { cout << st.pop(); }
		cout << " " << cnt << endl;
		cnt = 0;
	}
}