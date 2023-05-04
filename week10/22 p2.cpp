// 최대힙
#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
	vector<int> v;
	int heapSize = 0;

	Heap() {
		v.push_back(-1);
	}
	void Swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}
	void upHeap(int index) {
		int par = index / 2;
		if (index == 1) return;
		else {
			if (v[par] < v[index]) {
				Swap(par, index);
				upHeap(par);
			}
		}
	}
	void downHeap(int index) {
		int left = index * 2, right = index * 2 + 1;
		int bestPrior = index;
		if (left <= heapSize && v[left] > v[bestPrior]) bestPrior = left;
		if (right <= heapSize && v[right] > v[bestPrior]) bestPrior = right;

		if (bestPrior != index) {
			Swap(bestPrior, index);
			downHeap(bestPrior);
		}
	}
	void insert(int i) {
		v.push_back(i);
		heapSize++;
		upHeap(heapSize);
	}
	int pop() {
		int result = v[1];
		v[1] = v[heapSize];
		v.pop_back();
		heapSize--;
		downHeap(1);

		return result;
	}
	int top() {
		return v[1];
	}
	int size() {
		return heapSize;
	}
	void print() {
		for (int i = 1; i <= heapSize; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		Heap hp;
		int k, s; // k = 원소개수, s = 온도
		cin >> k >> s;
		while (k--) {
			int data;
			cin >> data;
			hp.insert(data);
		}
		int cnt = 0;
		bool result = 0;
		while (hp.top() > s) {
			if (hp.size() <= 2) break;
			int a = hp.pop();
			hp.pop();
			int b = hp.pop();
			hp.insert((a + b) / 2);
			cnt++;
		}
		if (hp.top() <= s) result = 1;

		if (result == 0) cout << "False" << "\n";
		else {
			cout << cnt << "\n";
			hp.print();
		}
	}
}