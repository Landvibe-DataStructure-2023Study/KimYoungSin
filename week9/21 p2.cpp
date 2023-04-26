// �������� �������� -> pop�� �� ����, data>*iter�� ���
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;
	void push(int data) {
		pr.push_back(data);
	}
	int pop() { // ���ؾߵǴϱ� �ݺ��� �ΰ� ����
		if (!pr.empty()) {
			vector<int>::iterator p = pr.begin(); // ����
			vector<int>::iterator iter;
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (*p < *iter) p = iter;
			}
			int priorityValue = *p;
			pr.erase(p); // p�� �ִ°� ����
			return priorityValue;
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> v;
		PQueue pq;
		
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