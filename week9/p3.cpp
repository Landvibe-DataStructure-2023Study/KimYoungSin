// 선택정렬, 내림차순
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;
	void push(int data) {
		pr.push_back(data);
	}
	int pop() {
		vector<int>::iterator p = pr.begin();
		vector<int>::iterator iter;
		for (iter = pr.begin(); iter != pr.end(); iter++) {
			if (*p < *iter) p = iter;
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
		vector<int> last;
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
			last.push_back(v.back()); // front <-> back
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		for (int i = 1; i < n; i++) {
			cout << v.front() - last[i] << " ";
		}
		cout << endl;
	}
}