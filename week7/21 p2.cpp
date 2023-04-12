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
	void postOrder(Node* node) {
		for (int i = 0; i < node->childList.size(); i++) {
			postOrder(node->childList[i]);
		}
		//if (node == root) { cout << 0 << " "; } // 루트의 부모노드는 nullptr이므로 이 경우만 따로 예외처리
		cout << node->data << " "; // 노드의 부모 데이터 출력(전위순회니까 먼저 출력)
	}
};
int main() {
	int t, n;
	cin >> t;

	while (t--) {
		Tree tree = Tree();
		int dataList[1000];
		int depthList[1000];

		// 트리를 전위순회한 값 주어짐
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dataList[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> depthList[i];
		}
		// 현재 노드의 depth와 다음 노드의 depth를 비교하면서 반복문 진행
		/*
		1 2 5 3 6 8 9 10 7 4
		0 1 2 1 2 3 3 3 2 1
		*/
		
		// 0번째는 루트이고, 루트는 이미 값이 저장돼있음 => i=0부터 n-1까지 다음 노드에 대한 연산을 수행함
		for (int i = 0; i < n - 1; i++) {
			if (depthList[i] == depthList[i + 1]) { // 깊이 같을 때는 그냥 같은 층 옆에다가 추가(부모 공유)
				Node* curParent = tree.findNode(dataList[i])->parent;
				tree.insert(curParent->data, dataList[i + 1]);
			}
			else if (depthList[i] < depthList[i + 1]) { // 그냥 바로 다음노드를 현재노드의 자식으로 삼음
				// Node* curNode = tree.findNode(dataList[i]); => 이거 insert 함수에서 해주잖아
				tree.insert(dataList[i], dataList[i + 1]);
			}
			// 4 2라면 2(depth)의 부모인 1을 찾아서 insert => 알아서 그 뒤에다가 삽입
			// 다음 노드에 들어갈 값만 있고, 얘의 부모가 누군지는 알 수 없음 => 현재노드를 다음노드와의 깊이 차이만큼 ->parent 해서 알아내자
			else if (depthList[i] > depthList[i + 1]) {
				Node* curNode = tree.findNode(dataList[i]);
				int k = depthList[i] - depthList[i + 1];
				
				while (k--) {
					curNode = curNode->parent;
				}
				Node* parentNode = curNode->parent;
				tree.insert(parentNode->data, dataList[i + 1]);
			}
		}
		tree.postOrder(tree.root);
		cout << endl;
	}
}