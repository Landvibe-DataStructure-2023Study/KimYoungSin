#include <iostream>
#include <vector>
using namespace std;

int cnt;
class Node {
public:
	int data;
	int depth;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int d, int dep) {
		parent = p;
		data = d;
		depth = dep;
	}
};
class Tree {
public:
	Node* root;
	vector<Node*> nodeList;
	Tree() {
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* findNode(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->data == x) {
				return nodeList[i];
			}
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = findNode(x);

		Node* newNode = new Node(parentNode, y, parentNode->depth + 1);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void preOrder(Node* node) {
		if (node->childList.empty()) {
			cnt++; return;
		}
		for (int i = 0; i < node->childList.size(); i++) {
			preOrder(node->childList[i]);
		}
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	Tree tree = Tree();
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insert(x, y);
	}
	for (int i = 0; i < m; i++) {
		cnt = 0;
		int x;
		cin >> x;
		Node* pile = tree.findNode(x);	
		tree.preOrder(pile);
		cout << cnt << endl;
	}
}