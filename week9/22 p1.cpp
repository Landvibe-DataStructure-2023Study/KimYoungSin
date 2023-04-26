// ��������, �������� - push�� �� ����, �׳� pop
#include <iostream>
#include <vector>
using namespace	std;

class PQueue {
public:
	vector<int> pr;
	// ��� ���ĵ� ä�� ���ϱ� �ڿ� �� ���� ���� �������� ���� ������ �� �ʿ� x
	// => iterator�� �ϳ��� ���� ��
	void push(int data) {
		if (pr.empty()) pr.push_back(data);
		else {
			vector<int>::iterator iter;
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (*iter > data) {
					pr.insert(iter, data);
					return; // insert������ return �ϴ� �� ��������
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