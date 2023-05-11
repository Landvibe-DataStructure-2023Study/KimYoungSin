#include <iostream>
using namespace std;

int countSub;
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

	// d�� ã��
	Node* search(int d) {
		Node* curNode = root;
		while (curNode != nullptr) {
			if (curNode->data == d) return curNode; // �Լ� ����
			else if (curNode->data > d) curNode = curNode->left;
			else if (curNode->data < d) curNode = curNode->right;
		}
		return nullptr;
	}
	void insert(int d) {
		// 1. newNode ����
		Node* newNode = new Node(d);

		// 2. ���� ��ġ ����
		if (root == nullptr) {
			root = newNode;
			return;
		}
		Node* curNode = root;
		Node* parNode = root->parent;

		while (curNode != nullptr) { // ��������
			if (curNode->data > d) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else {
				parNode = curNode;
				curNode = curNode->right;
			}
		}
		// 3. ���� ����, 2������ �����ϸ� parNode ������
		newNode->parent = parNode;
		if (parNode->data > d) {
			parNode->left = newNode;
		}
		else {
			parNode->right = newNode;
		}
	}
	void remove(int d) {
		// 1. d�� �����ϰ� �ִ� ����� ��ġ ã��
		Node* delNode = search(d);
		Node* parNode = delNode->parent;

		// 2. ����
		// 1) �ڽ� 0��
		if (delNode->left == nullptr && delNode->right == nullptr) {
			if (delNode == root) root = nullptr;
			else {
				if (delNode == parNode->left) parNode->left = nullptr;
				else if (delNode == parNode->right)parNode->right = nullptr;
			}
		}
		// 2) �ڽ� 1��
		else if (delNode->left == nullptr || delNode->right == nullptr) {
			Node* child = (delNode->left != nullptr) ? delNode->left : delNode->right;
			
			if (delNode == root) root = child;
			else {
				child->parent = delNode->parent;
				(delNode->left != nullptr)
					? delNode->left = child : delNode->right = child;
			}
		}
		// 3) �ڽ� 2��
		else if (delNode->left != nullptr && delNode->right != nullptr) {
			Node* succ = delNode->right; // �̰� ���� �̷��� �Ἥ �򰥸���..?
			Node* succPar = delNode;

			while (delNode->left != nullptr) {
				succPar = succ;
				succ = succ->left;
			}
			if (succ == succPar->left) {
				succPar->left = succ->right;
			}
			else {
				succPar->right = succ->right;
			}

			delNode->data = succ->data;
			delNode = succ;
		}
		delete delNode;
	}
	void sub(Node* node) {
		if (node == nullptr) return;
		
		sub(node->left);
		countSub++;
		sub(node->right);
	}
};
int main() {
	int n;
	cin >> n;

	BST bst;
	while (n--) {
		string s;
		int data;
		cin >> s;

		if (s == "insert") {
			cin >> data;
			bst.insert(data);
		}
		else if (s == "delete") {
			cin >> data;
			bst.remove(data);
		}
		else if (s == "sub") {
			cin >> data;
			countSub = 0;
			bst.sub(bst.search(data));
			cout << countSub << "\n";
		}
	}
}