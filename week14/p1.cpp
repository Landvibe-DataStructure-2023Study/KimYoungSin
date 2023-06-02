// 깊이우선탐색(DFS): 갈 수 있는만큼 가기
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt = 0;

void dfs(int x, int y) {
	cnt++;
	if (x == y) cout << cnt;
	visited[x] = true;
	for (int i : graph[x]) {
		if (!visited[i]) dfs(i, y);
	}
}
int main() {
	int n, m, q; // n: 정점 개수(5<=n<=1000) m: 간선, q: 질의
	cin >> n >> m >> q;
	while (m--) {
		int a, b; // 정점 번호
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		cnt = 0;
		dfs(a, b);
		cout << "\n";
		for (int i = 0; i < 1001; i++) {
			// 처음 입력받은 그래프 상태르 탐색만 하는거니까 clear는 뺌
			// graph[i].clear();
			visited[i] = false;
		}
	}
}
