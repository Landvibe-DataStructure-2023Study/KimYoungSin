// 선택정렬, 내림차순 - 그냥 넣고 정렬하면서 pop
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr; // priority queue
	void push(int data) {
		pr.push_back(data);
	}
	int pop() {
		if (!pr.empty()) {
			vector<int>::iterator p = pr.begin(); // 기준
			vector<int>::iterator iter;
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (*p < *iter) { p = iter; } // 큰거부터 뺄거니까, p보다 큰 iter가 나오면 p를 그거로 초기화
			}
			int maxValue = *p;
			pr.erase(p);
			return maxValue;
		}
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