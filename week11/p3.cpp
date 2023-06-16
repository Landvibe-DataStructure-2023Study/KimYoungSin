#include <iostream>
using namespace std;

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

	Node* search(int d) {
		Node* curNode = root;
		while (curNode != nullptr) {
			if (curNode->data == d) return curNode;
			else if (curNode->data > d) curNode = curNode->left;
			else if (curNode->data < d) curNode = curNode->right;
		}
		return nullptr;
	}
	void insert(int d) {
		Node* newNode = new Node(d);
		if (root == nullptr) {
			root = newNode;
			return;
		}

		Node* curNode = root;
		Node* parNode = root->parent;
		while (curNode != nullptr) {
			if (curNode->data > d) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else {
				parNode = curNode;
				curNode = curNode->right;
			}
		}
		newNode->parent = parNode;
		if (parNode->data > d) parNode->left = newNode;
		else parNode->right = newNode;
	}
	int leftSub(Node* node) {
		if (node == nullptr) return 0;
		int cnt = 0;
		cnt += leftSub(node->left);
		cnt++; // 현재노드
		cnt += leftSub(node->right);
		return cnt;
	}
};
int main() {
	BST bst;
	int n, m;
	cin >> n >> m;

	while (n--) {
		int data;
		cin >> data;
		bst.insert(data);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;

		Node* a = bst.search(x)->right;
		Node* b = bst.search(y)->right;
		int result =  bst.leftSub(a) - bst.leftSub(b);

		if (result < 0) cout << -result << "\n";
		else cout << result << "\n";
	}
}