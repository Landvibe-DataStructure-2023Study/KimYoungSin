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
		cout << node->data << " ";

		for (int i = node->childList.size() - 1; i >=0 ; i--) { // 거꾸로 삽입하니까, 전위순회도 거꾸로 해야함
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

		// 트리를 후위순회한 값 주어짐
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dataList[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> depthList[i];
		}
		// 현재 노드의 depth와 다음 노드의 depth를 비교하면서 반복문 진행
		/*
		5 2 8 9 10 6 7 3 4 1
		2 1 3 3 3 2 2 1 1 0
		*/

		// 배열의 앞에서부터 받으면, 그 위의 부모가 아직 없어서 삽입할 수 없음 => 뒤에서부터 읽자(후위연산 역순)
		// 배열의 끝 = n - 1, i = 1일때, 배열[0]번째 요소를 처리하는 연산을 마지막으로 함
		for (int i = n - 1; i > 0; i--) {
			if (depthList[i] == depthList[i - 1]) { // 깊이 같을 때는 그냥 같은 층 옆에다가 추가(부모 공유), 뭐를 부모로하는지 주의해서 삽입
				Node* curParent = tree.findNode(dataList[i])->parent;
				tree.insert(curParent->data, dataList[i - 1]);
			}
			else if (depthList[i] < depthList[i - 1]) { // i-1이 커지면 바로 다음노드를 현재노드의 자식으로 삼음
				tree.insert(dataList[i], dataList[i - 1]);
			}
			// i - 1이 더 작으면 부모 찾아주기
			else if (depthList[i] > depthList[i - 1]) {
				Node* curNode = tree.findNode(dataList[i]);
				int k = depthList[i] - depthList[i - 1]; // 이거 순서 잘 봐라

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
