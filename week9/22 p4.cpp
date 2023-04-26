// 선택 정렬, 1. 짝수 2. 작은 수일 때 우선순위 높음
#include <iostream>
#include <vector>
using namespace std;

int prior(int a) {
	if (a % 2 == 0) return 1;
	else return 0;
}
class PQueue {
public:
	vector<int> pr;
	void push(int data) {
		pr.push_back(data);
	}
	int pop() {
		vector<int>::iterator iter;
		vector<int>::iterator p = pr.begin();
		for (iter = pr.begin(); iter != pr.end(); iter++) { // p보다 우선순위가 높은 게 있다면 p를 그거로 교체
			if (prior(*p) < prior(*iter)) p = iter;
			else if (prior(*p) == prior(*iter)) { // p보다 더 작은 게 있다면 p를 그거로 교체
				if (*p > *iter) p = iter;
			}
		}
		int maxValue = *p;
		pr.erase(p);
		return maxValue;
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