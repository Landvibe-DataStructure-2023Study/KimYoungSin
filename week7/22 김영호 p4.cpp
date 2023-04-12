#include <iostream>
#include <vector>
using namespace std;

int sum;
class Node {
public:
	int weight;
	int data;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int d, int w) {
		parent = p;
		data = d;
		weight = w;
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

		Node* newNode = new Node(parentNode, y, 0);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void postOrder(Node* node) {	
		for (int i = 0; i < node->childList.size(); i++) {
			postOrder(node->childList[i]);
		}
		sum += node->weight;
	}
};
int main() {
	Tree tree = Tree();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.insert(x, y);
	}
	for (int i = 0; i < n; i++) { // 용량 설정
		int x, y;
		cin >> x >> y;
		tree.findNode(x)->weight = y;
	}
	while (m--) {
		sum = 0;
		int x;
		cin >> x;
		tree.postOrder(tree.findNode(x));
		cout << sum << endl;
	}
}