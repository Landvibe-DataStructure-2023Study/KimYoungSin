// 삽입정렬, 오름차순
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;
	void push(int data) {
		vector<int>::iterator iter;
		for (iter = pr.begin(); iter != pr.end(); iter++) {
			if (*iter > data) {
				pr.insert(iter, data);
				return;
			}
		}
		pr.insert(pr.end(), data);
	}
	int pop() {
		int minValue = pr.front();
		pr.erase(pr.begin());
		return minValue;
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
			cout << last[i] + v.front() << " ";
		}
		cout << endl;
	}
}