// �ּ���
#include <iostream>
#include <vector>
using namespace std;

class Heap { // 1���� ����
public:
	int heapSize = 0;
	vector<int> v;

	Heap() {
		v.push_back(-1);
	}
	void Swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}
	void upHeap(int index) { // ���� �ƴ϶� �ε����� �Ǵ�
		int par = index / 2; // �θ� ��� �ε���
		if (index == 1) return;
		else {
			if (v[par] > v[index]) {
				Swap(par, index);
				upHeap(par);
			}
		}
	}
	void downHeap(int index) { // ���� ����� ���ʿ����� �ڽ� ��
		int left = index * 2, right = index * 2 + 1;
		int bestPrior = index;

		if (left <= heapSize && v[left] < v[bestPrior]) {
			bestPrior = left;
		}
		if (right <= heapSize && v[right] < v[bestPrior]) {
			bestPrior = right;
		}
		if (bestPrior != index) {
			Swap(bestPrior, index);
			downHeap(bestPrior);
		}
	}
	bool isEmpty() { return heapSize == 0; }
	void size() { cout << heapSize << "\n"; }
	void insert(int i) {
		v.push_back(i);
		heapSize++; // heapSize++ ���� ����ߵǴ� �� ����!
		upHeap(heapSize); // �ε����� 1���� �����ϴϱ� �������� heapSize
	}
	int pop() {
		int result = v[1];
		v[1] = v[heapSize];
		v.pop_back();
		heapSize--;
		downHeap(1);

		return result;
	}
	void top() {
		if (isEmpty()) {
			cout << "-1" << "\n";
			return;
		}
		cout << v[1] << "\n";
	}
	void print() {
		if (isEmpty()) {
			cout << "-1" << "\n";
			return;
		}
		for (int i = 1; i <= heapSize; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
};
int main() {
	Heap hp;
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "insert") {
			int idx;
			cin >> idx;
			hp.insert(idx);
		}
		else if (s == "size") {
			hp.size();
		}
		else if (s == "isEmpty") {
			if (hp.isEmpty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (s == "pop") {
			cout << hp.pop() << endl;
		}
		else if (s == "top") {
			hp.top();
		}
		else if (s == "print") {
			hp.print();
		}
	}
}