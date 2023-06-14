#include <iostream>
#include <vector>
using namespace std;

bool graph[501][501];
bool check[501];
bool connect[501][501]; // 연동
int main() {
	int n, m, d; // n: 가입자 수, m: 질의 개수, d: 계정 연동 옵션 쓰는 사용자 수
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
		int k; // 사용자 번호
		int s; // 추천범위
		cin >> k >> s;

		int a[501] = { 0 }; // 중복 제거용 배열 => 배열 초기화할 때 {0} 해야됨
		a[k] = 1; // 본인 제외
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
					if (a[i] != 1 && !connect[k][i]) { // 첫번째 친구	
						Friend.push_back(i);
						a[i] = 1;
					}
					for (int j = 1; j <= n; j++) { // 첫번째 친구의 연동
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

		// 정렬
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

