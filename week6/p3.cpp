#include <iostream>
#include <vector>
using namespace std;

class Node {
public: // 안 써주면 private처럼 작동
	int data;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int d) {
		parent = p;
		data = d;
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
	void insert(int x, int y) {
		Node* parentNode = findNode(x);
		Node* childNode = findNode(y);
		if (parentNode == nullptr || childNode != nullptr) {
			cout << "-1" << endl; return;
		}
		Node* newNode = new Node(parentNode, y);

		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void deletion(int x) {
		Node* deleteNode = findNode(x);
		if (deleteNode == nullptr) {
			cout << "-1" << endl; return;
		}
		// 1. 삭제할 노드의 자식의 부모를 삭제할 노드의 부모들로 옮김
		for (int i = 0; i < deleteNode->childList.size(); i++) {
			deleteNode->parent->childList.push_back(deleteNode->childList[i]);
			deleteNode->childList[i]->parent = deleteNode->parent;
		}
		// 2. insert처럼 부모노드 리스트에서 삭제
		for (int i = 0; i < deleteNode->parent->childList.size(); i++) {
			if (deleteNode->parent->childList[i] == deleteNode) {
				deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
				break;
			}
		}
		// 3. insert처럼 nodeList에서 삭제
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i] == deleteNode) {
				nodeList.erase(nodeList.begin() + i);
				break;
			}
		}
		//delete deleteNode;
	}
	void isParent(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr) {
			cout << "-1" << endl; return;
		}
		cout << curNode->parent->data << endl;
	}
	void isChild(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode->childList.empty()) {
			cout << "-1" << endl; return;
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			cout << curNode->childList[i]->data << " ";
		}
		cout << endl;
	}
	void min_maxChild(int x) {
		Node* curNode = findNode(x);
		// curNode==nullptr 조건을 먼저 써줘야함, 반대로 쓰면 nullptr 조건은 검사 안 하고(조건문 실행 안 하고) 넘어가버림
		if (curNode == nullptr || curNode->childList.size() < 2) {
			cout << "-1" << endl; return;
		}
		int max = 0;
		int min = 10001;
		for (int i = 0; i < curNode->childList.size(); i++) {
			if (curNode->childList[i]->data >= max) {
				max = curNode->childList[i]->data;
			}
			if (curNode->childList[i]->data <= min) {
				min = curNode->childList[i]->data;
			}
		}
		cout << max - min << endl;
	}
};
int main() {
	Tree tree = Tree();
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int x, y;
			cin >> x >> y;
			tree.insert(x, y);
		}
		else if (s == "delete") {
			int x;
			cin >> x;
			tree.deletion(x);
		}
		else if (s == "parent") {
			int x;
			cin >> x;
			tree.isParent(x);
		}
		else if (s == "child") {
			int x;
			cin >> x;
			tree.isChild(x);
		}
		else if (s == "min_maxChild") {
			int x;
			cin >> x;
			tree.min_maxChild(x);
		}
	}
}