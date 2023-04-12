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
		//if (node == root) { cout << 0 << " "; } // ��Ʈ�� �θ���� nullptr�̹Ƿ� �� ��츸 ���� ����ó��
		cout << node->data << " "; // ����� �θ� ������ ���(������ȸ�ϱ� ���� ���)

		for (int i = node->childList.size() - 1; i >=0 ; i--) {
			preOrder(node->childList[i]);
		}
	}
};
int main() {
	int t, n;
	cin >> t;

	while (t--) {
		Tree tree = Tree();
		int dataList[1000];
		int depthList[1000];

		// Ʈ���� ������ȸ�� �� �־���
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dataList[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> depthList[i];
		}
		// ���� ����� depth�� ���� ����� depth�� ���ϸ鼭 �ݺ��� ����
		/*
		5 2 8 9 10 6 7 3 4 1
		2 1 3 3 3 2 2 1 1 0
		*/

		// 0��°�� ��Ʈ�̰�, ��Ʈ�� �̹� ���� ��������� => i=0���� n-1���� ���� ��忡 ���� ������ ������
		for (int i = n - 1; i > 0; i--) {
			if (depthList[i] == depthList[i - 1]) { // ���� ���� ���� �׳� ���� �� �����ٰ� �߰�(�θ� ����)
				Node* curParent = tree.findNode(dataList[i])->parent;
				tree.insert(curParent->data, dataList[i - 1]);
			}
			else if (depthList[i] < depthList[i - 1]) { // �׳� �ٷ� ������带 �������� �ڽ����� ����
				// Node* curNode = tree.findNode(dataList[i]); => �̰� insert �Լ����� �����ݾ�
				tree.insert(dataList[i], dataList[i - 1]);
			}
			// 4 2��� 2(depth)�� �θ��� 1�� ã�Ƽ� insert => �˾Ƽ� �� �ڿ��ٰ� ����
			// ���� ��忡 �� ���� �ְ�, ���� �θ� �������� �� �� ���� => �����带 ���������� ���� ���̸�ŭ ->parent �ؼ� �˾Ƴ���
			else if (depthList[i] > depthList[i - 1]) {
				Node* curNode = tree.findNode(dataList[i]);
				int k = depthList[i] - depthList[i - 1]; // �̰� ���� �� ����

				while (k--) {
					curNode = curNode->parent;
				}
				Node* parentNode = curNode->parent;
				tree.insert(parentNode->data, dataList[i - 1]);
			}
		}
		tree.preOrder(tree.root);
		cout << endl;
	}
}