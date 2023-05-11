#include <iostream>
using namespace std;

int index, result; // index: 하나씩 올리면서 find랑 같아질때까지 ++해주는 변수
class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	Node(int d) {
		data = d;
		parent = left = right = nullptr;
	}
};
class BST {
public:
	Node* root = nullptr;


	void insert(int d) {
		// 1. newNode 생성
		Node* newNode = new Node(d);
		if (root == nullptr) {
			root = newNode;
			return;
		}

		// 2. 삽입 위치 지정
		Node* curNode = root;
		Node* parNode = root->parent;

		while (curNode != nullptr) { // 리프까지 돌기
			if (curNode->data > d) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else {
				parNode = curNode;
				curNode = curNode->right;
			}
		}
		// 3. 삽입
		newNode->parent = parNode; // 부모자식관계 만들어주기

		if (parNode->data > d) parNode->left = newNode;
		else parNode->right = newNode;
	}
	void inOrder(Node* node) {
		if (node == nullptr) return; 
		inOrder(node->left); // 왼쪽

		index++;
		if (index == result) {
			cout << node->data << "\n";
			return;
		}
		inOrder(node->right); // 왼쪽에서 못 찾으면 오른쪽으로 넘어가서 똑같이
	}
};
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		BST bst;
		cin >> n;
		for (int i = 0; i < n;i++) {
			int data;
			cin >> data;
			bst.insert(data);
		}
		
		cin >> result;
		index = 0; // 전역변수로 설정해둠(inOrder함수 정의할 때도 사용해야돼서

		bst.inOrder(bst.root);
	}
}