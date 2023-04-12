// 전위순회: 부모노드부터 출력
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int d) {
		data = d;
		parent = p;
	}
};
class Tree {
public:
	Node* root;
	vector<Node*> nodeList;
	Tree() {
		root = new Node(nullptr, 1);
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
	void insert(int x, int y) { // 중복 없다고 가정
		Node* parentNode = findNode(x);
		Node* newNode = new Node(parentNode, y);

		newNode->parent->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void preOrder(Node* node) {
		//if (!node) return; //=> 굳이 안 써줘도 됨. for문 끝까지 돌고 알아서 끝내는 재귀함수
		if (node == root) { cout << 0 << " "; } // 루트의 부모노드는 nullptr이므로 이 경우만 따로 예외처리
		else cout << node->parent->data << " "; // 노드의 부모 데이터 출력(전위순회니까 먼저 출력)
		for (int i = 0; i < node->childList.size(); i++) {
			preOrder(node->childList[i]); 
		}
	}
};
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		Tree tree = Tree(); // 트리 초기화 해야되니까, while문 안에다가 선언
		cin >> n;
		while (n--) {
			int x, y;
			cin >> x >> y;
			tree.insert(x, y);
		}
		tree.preOrder(tree.root);
		cout << endl;
	}
}

