#include <iostream>
using namespace std;

int index, k;
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

	void insert(int d) { // Node Ŭ�������� data �����̸� �����ϱ� �� �򰥸��� d
		Node* newNode = new Node(d);

		if (root == nullptr) {
			root = newNode;
			return; // root �����ϰ� ������
		}

		Node* curNode = root;
		Node* parNode = curNode->parent;

		while (curNode != nullptr) { // ���� ��ġ �����ϰ� parNode �߽����� 
			if (curNode->data > d) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else {
				parNode = curNode;
				curNode = curNode->right;
			}
		}
		newNode->parent = parNode; // �θ� �ڽ� ����� ���� ����
		if (parNode->data > d) parNode->left = newNode;
		else parNode->right = newNode;
	}
	void remove(int x) {
		//1. del,par,childNode ����
		Node* delNode = search(x);
		if (delNode == nullptr) { return; }
		Node* parNode = delNode->parent;
		Node* childNode;

		//2. �ڽ� 0��, 1��, 2���� �� childNode ����
		if (delNode->left == nullptr && delNode->right == nullptr) {
			childNode = nullptr;
		}
		else if (delNode->left == nullptr && delNode->right != nullptr) {
			childNode = delNode->right;
		}
		else if (delNode->left != nullptr && delNode->right == nullptr) {
			childNode = delNode->left;
		}
		else { // �ڽ� �� �� ����
			childNode = delNode->right; // �� �� ���������� ���ٰ� �������� ����
			while (childNode->left != nullptr) {
				childNode = childNode->left;
			}

			delNode->data = childNode->data;
			delNode = childNode;
			parNode = delNode->parent;
			childNode = delNode->right;
		}

		// 3. delNode �����ֱ�
		if (parNode == nullptr) { // ��� �ϳ��ۿ� ���� ��
			root = childNode;
			if (childNode != nullptr) {
				root->parent = nullptr;
			}
		}
		else if (delNode == parNode->left) {
			parNode->left = childNode;
			if (childNode != nullptr) {
				childNode->parent = parNode;
			}
		}
		else {
			parNode->right = childNode;
			if (childNode != nullptr) {
				childNode->parent = parNode;
			}
		}
		delete delNode;
	}
	void min(Node* node) { // k��°�� ���� ���� ���, max�� left right �ٲ㼭
		if (node == nullptr) return;
		min(node->left);

		index++;
		if (index == k) {
			cout << node->data << "\n";
			return;
		}
		min(node->right);
	}
	void depth(Node* node) {
		Node* curNode = node;
		int depth = 0;

		while (curNode != root) {
			curNode = curNode->parent;
			depth++;
		}
		cout << depth << "\n";
	}
	int height(Node* node) {
		if (node == nullptr) return -1;

		if (height(node->left) < height(node->right))
			return height(node->right) + 1;
		else
			return height(node->left) + 1;
	}
};
int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	BST bst;
	int t, data;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "insert") {
			cin >> data;
			bst.insert(data);
			bst.depth(bst.search(data));
		}
		else if (s == "delete") {
			cin >> data;
			bst.depth(bst.search(data));
			bst.remove(data);
		}
		else if (s == "min") {
			cin >> k;
			index = 0;
			bst.min(bst.root);
		}
		else if (s == "height") {
			cin >> data;
			cout << bst.height(bst.search(data)) << "\n";
		}
	}
}