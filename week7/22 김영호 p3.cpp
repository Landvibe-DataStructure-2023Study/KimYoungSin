#include <iostream>
#include <vector>
using namespace std;

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
	void postOrder(Node* node) {
		for (int i = 0; i < node->childList.size(); i++) {
			postOrder(node->childList[i]);
		}
		cout << node->depth << " ";
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		Tree tree = Tree();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			tree.insert(x, y);
		}
		tree.postOrder(tree.root);
		cout << endl;
	}
}