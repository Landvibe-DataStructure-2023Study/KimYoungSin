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
		data = d;
		parent = p;
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
		return nullptr; // for문 다 돌았는데도 못 찾으면 nullptr 리턴
	}
	void insert(int x, int y) {
		Node* parentNode = findNode(x);
		Node* childNode = findNode(y);
		if (childNode != nullptr || parentNode == nullptr) {
			cout << "-1" << endl; return;
		}
		Node* newNode = new Node(parentNode, y, parentNode->depth + 1);

		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void depthMinus(int x, int y) {
		if (findNode(x) == nullptr || findNode(y) == nullptr) {
			cout << "-1" << endl; return;
		}
		int a = findNode(x)->depth;
		int b = findNode(y)->depth;
		cout << a + b << endl;
	}
};
int main() {
	Tree tree = Tree();
	int n, m;
	cin >> n >> m;

	while (n--) {
		int x, y;
		cin >> x >> y;
		tree.insert(x, y);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		tree.depthMinus(x, y);
	}
}