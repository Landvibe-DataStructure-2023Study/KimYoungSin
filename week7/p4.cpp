#include <iostream>
#include <vector>
using namespace std;

int k; // 기준
bool result = 0;
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
			if (nodeList[i]->data == x) return nodeList[i];
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = findNode(x);
		Node* newNode = new Node(parentNode, y, parentNode->depth + 1);

		nodeList.push_back(newNode);
		parentNode->childList.push_back(newNode);
	}
	void preOrder(Node* node) { // pList 정렬
		if(node->depth == k && node->childList.empty()){
			result = 1;
			cout << node->data << " ";
		}
		for (int i = 0; i < node->childList.size(); i++) {
			preOrder(node->childList[i]);
		}
	}
};
int main() {
	Tree tree = Tree();
	int n, m;
	int x, y; // x: 폴더번호
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		tree.insert(x, y);
	}

	for (int i = 0; i < m; i++) {
		result = 0;
		cin >> k;

		tree.preOrder(tree.root);
		if (result == 0) cout << "-1";
		cout << endl;
	}
}

/*
10 3
1 2
1 5
2 8
2 12
12 11
8 4
1 10
10 7
8 16
3
2
4
*/