#include <iostream>
#include <vector>
using namespace std;

bool graph[501][501];
bool check[501];
bool connect[501][501]; // ����
int main() {
	int n, m, d; // n: ������ ��, m: ���� ����, d: ���� ���� �ɼ� ���� ����� ��
	cin >> n >> m >> d;

	while (d--) {
		int i, j;
		cin >> i >> j;
		connect[i][j] = connect[j][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			if (graph[i][j] != 2) graph[i][j] = k;
		}
	}
	while (m--) {
		vector<int> Friend;
		int k; // ����� ��ȣ
		int s; // ��õ����
		cin >> k >> s;

		int a[501] = { 0 }; // �ߺ� ���ſ� �迭 => �迭 �ʱ�ȭ�� �� {0} �ؾߵ�
		a[k] = 1; // ���� ����
		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] == 1 && a[i] != 1 && !connect[k][i]) {
					Friend.push_back(i);
					a[i] = 1;
					for (int j = 1; j <= n; j++) {
						if (connect[i][j]) {
							Friend.push_back(j);
							a[j] = 1;
						}
					}
				}
			}
		}
		else if (s == 2) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] == 1) {
					if (a[i] != 1 && !connect[k][i]) { // ù��° ģ��	
						Friend.push_back(i);
						a[i] = 1;
					}
					for (int j = 1; j <= n; j++) { // ù��° ģ���� ����
						if (connect[i][j]) {
							if (k != j && a[j] != 1) {
								Friend.push_back(j);
								a[j] = 1;
							}
						}
					}
					for (int j = 1; j <= n; j++) {
						if (graph[i][j] == 1 && k != j && a[j] != 1 && !connect[k][j]) {
							Friend.push_back(j);
							a[j] = 1;

							for (int t = 1; t <= n; t++) {
								if (connect[t][j] && k != t && a[t] != 1) {
									Friend.push_back(t);
									a[t] = 1;
								}
							}
						}
					}
				}
			}
		}

		// ����
		for (int i = 0; i < Friend.size(); i++) {
			for (int j = 0; j < Friend.size(); j++) {
				if (Friend[i] < Friend[j]) swap(Friend[i], Friend[j]);
			}
		}
		for (int i : Friend) {
			cout << i << " ";
		}
		if (Friend.empty()) cout << "0";
		cout << "\n";
	}
}

