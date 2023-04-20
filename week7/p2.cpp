#include <iostream>
#include <vector>
using namespace std;

int sum;
vector<int> pList;
class Node {
public:
	int data;
	int weight;
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
			if (nodeList[i]->data == x) return nodeList[i];
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = findNode(x);
		Node* newNode = new Node(parentNode, y, 0);

		nodeList.push_back(newNode);
		parentNode->childList.push_back(newNode);
	}
	void postSum(Node* node) {	
		for (int i = 0; i < node->childList.size(); i++) {
			postSum(node->childList[i]);
		}
		sum += node->weight;
	}
	void postOrder(Node* node) { // pList 정렬
		for (int i = 0; i < node->childList.size(); i++) {
			postOrder(node->childList[i]);
		}
		pList.push_back(node->data);
	}
};
int main() {
	Tree tree = Tree();
	int n, c;
	int x, y, w; // x: 폴더번호
	cin >> n >> c;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		tree.insert(x, y);
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> w;
		tree.findNode(x)->weight = w;
	}
	tree.postOrder(tree.root); // pList 정렬

	bool result = 0;
	for (int i = 0; i < pList.size(); i++) { // pList는 후위순회 되어있음
		sum = 0;
		tree.postSum(tree.findNode(pList[i])); // sum 계산
		if (sum >= c) {
			cout << pList[i] << " ";
			result = 1;
		}
	}
	if (result == 0) cout << "-1";
	cout << endl;
}

/*
11 200
1 2
1 5
2 8
2 12
12 11
8 4
1 10
10 7
12 6
8 16
1 222
2 30
11 333
12 55
8 33
4 10
16 3
7 20
6 205
10 15
5 70
*/