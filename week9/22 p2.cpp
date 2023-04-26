#include <iostream>
#include <vector>
using namespace std;

int prior(int a) {
	if (a % 2 == 1) return 1;
	else return 0;
}
class PQueue {
public:
	vector<int> pr; // priority Queue

	// 선택정렬로 구현 : 그냥 push, pop하면서 정렬
	void push(int data) {
		pr.push_back(data);
	}
	int pop() {
		vector<int>::iterator p = pr.begin(); // 기준
		vector<int>::iterator iter;
		for (iter = pr.begin(); iter != pr.end(); iter++) {
			if (prior(*p) < prior(*iter)) p = iter; // p보다 우선순위가 높은 게 있다면 p를 그 iter로 교체
			else if (prior(*p) == prior(*iter)) {
				if (*p < *iter) p = iter;
			}
		}
		int priorityValue = *p;
		pr.erase(p);
		return priorityValue;
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