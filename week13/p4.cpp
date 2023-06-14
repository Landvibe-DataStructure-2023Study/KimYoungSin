/*
<친구 추천 목록>
추천 범위 s -> 사용자 t와 s번 이하의 친구관계 -> 목록 삽입,출력(s = 1 || 2)

계정 연동(부계) - 목표 범위에 해당되지만 연동되있는 계정이라면 제외
				- 연동돼있다면 같은 범위가 아니더라도 같이 출력
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
	int n, m, d; // n: 가입자 수, m: 질의 개수, d: 친구 추천 거부 사용자 수
	cin >> n >> m >> d;

	while (d--) { // 친구 추천 거부
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
		int k; // 사용자 번호
		int s; // 추천범위
		cin >> k >> s;

		int a[501] = { 0 }; // 중복 제거용 배열 => 배열 초기화할 때 {0} 해야됨
		a[k] = 1; // 본인 제외
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
					for (int j = 1; j <= n; j++) { // 두번째 친구
						if (graph[i][j] == 1 && k != j && a[j] != 1 && !reject[j]) {
							Friend.push_back(j);
							a[j] = 1;
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