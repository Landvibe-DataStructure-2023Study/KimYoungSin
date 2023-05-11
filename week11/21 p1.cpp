#include <iostream>
using namespace std;

int index, result; // index: �ϳ��� �ø��鼭 find�� ������������ ++���ִ� ����
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
		// 1. newNode ����
		Node* newNode = new Node(d);
		if (root == nullptr) {
			root = newNode;
			return;
		}

		// 2. ���� ��ġ ����
		Node* curNode = root;
		Node* parNode = root->parent;

		while (curNode != nullptr) { // �������� ����
			if (curNode->data > d) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else {
				parNode = curNode;
				curNode = curNode->right;
			}
		}
		// 3. ����
		newNode->parent = parNode; // �θ��ڽİ��� ������ֱ�

		if (parNode->data > d) parNode->left = newNode;
		else parNode->right = newNode;
	}
	void inOrder(Node* node) {
		if (node == nullptr) return; 
		inOrder(node->left); // ����

		index++;
		if (index == result) {
			cout << node->data << "\n";
			return;
		}
		inOrder(node->right); // ���ʿ��� �� ã���� ���������� �Ѿ�� �Ȱ���
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
		index = 0; // ���������� �����ص�(inOrder�Լ� ������ ���� ����ؾߵż�

		bst.inOrder(bst.root);
	}
}