// 선택정렬 : push는 그냥 하고, pop하면서 정렬, 오름차순
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;

	void push(int data) {
		pr.push_back(data);
	}
	// 정렬되지 않은 배열에서 뽑아야되니까 iterator 두 개 필요
	int pop() {
		vector<int>::iterator p = pr.begin();
		vector<int>::iterator iter;
		for (iter = pr.begin(); iter != pr.end(); iter++) {
			if (*p > *iter) p = iter; // 최대한 작은 걸 찾아서 순회하는거니까
		}
		int minValue = *p;
		pr.erase(p);
		return minValue;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		PQueue pq;
		vector<int> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			v.push_back(data);
		}
		for (int i = 0; i < n; i++) {
			pq.push(v.front());
			v.erase(v.begin());
		}
		for (int i = 0; i < n; i++) {
			v.push_back(pq.pop());
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}