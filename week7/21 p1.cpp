// ������ȸ: �θ������ ���
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
	void insert(int x, int y) { // �ߺ� ���ٰ� ����
		Node* parentNode = findNode(x);
		Node* newNode = new Node(parentNode, y);

		newNode->parent->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void preOrder(Node* node) {
		//if (!node) return; //=> ���� �� ���൵ ��. for�� ������ ���� �˾Ƽ� ������ ����Լ�
		if (node == root) { cout << 0 << " "; } // ��Ʈ�� �θ���� nullptr�̹Ƿ� �� ��츸 ���� ����ó��
		else cout << node->parent->data << " "; // ����� �θ� ������ ���(������ȸ�ϱ� ���� ���)
		for (int i = 0; i < node->childList.size(); i++) {
			preOrder(node->childList[i]); 
		}
	}
};
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		Tree tree = Tree(); // Ʈ�� �ʱ�ȭ �ؾߵǴϱ�, while�� �ȿ��ٰ� ����
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

