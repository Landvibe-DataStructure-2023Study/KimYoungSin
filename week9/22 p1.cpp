// 삽입정렬, 오름차순 - push할 때 정렬, 그냥 pop
#include <iostream>
#include <vector>
using namespace	std;

class PQueue {
public:
	vector<int> pr;
	// 계속 정렬된 채로 들어가니까 뒤에 더 작은 수가 있을지에 대한 염려는 할 필요 x
	// => iterator를 하나만 만들어도 됨
	void push(int data) {
		if (pr.empty()) pr.push_back(data);
		else {
			vector<int>::iterator iter;
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (*iter > data) {
					pr.insert(iter, data);
					return; // insert했으면 return 하는 거 잊지말고
				}
			}
			pr.insert(pr.end(), data);
		}
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