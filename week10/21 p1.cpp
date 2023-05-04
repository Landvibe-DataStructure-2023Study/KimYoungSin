// 최대힙 우선순위 큐
#include <iostream>
#include <vector>
using namespace std;


class Heap {
public:
	int heapSize = 0;
	//int indexOfRoot = 1; // index는 1부터 시작하니까
	vector<int> v;

	Heap() {
		v.push_back(-1); // v[0] 자리에 아무거나 넣고 시작
	}
	void Swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}
	void upHeap(int index) {
		int par = index / 2;
		if (index == 1) return;
		else if(v[par] < v[index]) {
			Swap(par, index);
			upHeap(par);
		}
	}
	void downHeap(int index) {
		int left = index * 2, right = index * 2 + 1;
		int idxOfBestPrior = index;
		// left가 heapSize보다 작은 경우를 먼저 써줘야함
		// 뒤에걸 먼저 검사하면 heapSize보다 큰 인덱스를 고려하는거기 때문에 오류
		if (left <= heapSize && v[left] > v[idxOfBestPrior]) 
			idxOfBestPrior = left;

		if (right <= heapSize && v[right] > v[idxOfBestPrior])
			idxOfBestPrior = right;

		if (idxOfBestPrior != index) {
			Swap(index, idxOfBestPrior);
			downHeap(idxOfBestPrior);
		}
	}
	bool isEmpty() { return heapSize == 0; }
	void size() { cout << heapSize << endl; }
	void top() { 
		if (isEmpty()) { cout << "-1" << endl; return; }
		cout << v[1] << endl; 
	}
	void print() {
		if (isEmpty()) { cout << "-1" << endl; return; }
		for (int i = 1; i <= heapSize; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	void insert(int i) {
		v.push_back(i);
		heapSize++;
		upHeap(heapSize);
	}
	int pop() {
		if (isEmpty()) { return -1; }
		else {
			int maxValue = v[1];
			//Swap(1, heapSize);
			v[1] = v[heapSize];
			heapSize--;
			v.pop_back();
			downHeap(1);
			return maxValue;
		}
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