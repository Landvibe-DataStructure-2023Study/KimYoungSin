/*
<ģ�� ��õ ���>
��õ ���� s -> ����� t�� s�� ������ ģ������ -> ��� ����,���(s = 1 || 2)

���� ����(�ΰ�) - ��ǥ ������ �ش������ �������ִ� �����̶�� ����
				- �������ִٸ� ���� ������ �ƴϴ��� ���� ���
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool graph[501][501];
bool check[501];
bool reject[501];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int n, m, d; // n: ������ ��, m: ���� ����, d: ģ�� ��õ �ź� ����� ��
	cin >> n >> m >> d;

	while (d--) { // ģ�� ��õ �ź�
		int a;
		cin >> a;
		reject[a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			graph[i][j] = k;
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
				if (graph[k][i] == 1 && a[i] != 1 && !reject[i]) Friend.push_back(i);
			}
		}
		else if (s == 2) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] == 1) {
					if (a[i] != 1 && !reject[i]) {
						Friend.push_back(i);	
						a[i] = 1;
					}
					for (int j = 1; j <= n; j++) { // �ι�° ģ��
						if (graph[i][j] == 1 && k != j && a[j] != 1 && !reject[j]) {
							Friend.push_back(j);
							a[j] = 1;
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
/*
6 3 3
2 4 5
0 1 1 1 1 0
1 0 1 1 0 0
1 1 0 0 0 0
1 1 0 0 0 0
1 0 0 0 0 0
0 0 0 0 0 0
1 1
2 1
6 2
*/