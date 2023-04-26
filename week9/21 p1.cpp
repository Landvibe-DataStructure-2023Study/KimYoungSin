// �������� -> push�� �� ����
// �������� ���� -> data�� ���� ����Ű�� ������ ��
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;

	void push(int data){
		if (pr.empty()) pr.push_back(data);
		else {
			vector<int>::iterator iter;
			// �ݺ��� ��ȸ, ���� ���� ���� �տ� �����Ŵϱ� �� ������ �����൵ ��
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (data < *iter) {
					pr.insert(iter, data);
					return;
				}
			}
			// ������ ���Ƶ� �� �� ã�� ���
			pr.insert(pr.end(), data);
		}
	}
	int pop() {
		if (!pr.empty()) {
			int data = pr.front();
			pr.erase(pr.begin());
			return data;
		}
		else return 0;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> v; // ����
		PQueue pq; // �켱���� ť
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			v.push_back(data);
		}
		for (int i = 0; i < n; i++) {
			pq.push(v.front());
			v.erase(v.begin()); // ���� �������Ϳ� �ִ� �� ����

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