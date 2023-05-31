#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

void bfs(int x) {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int top = q.front();
		q.pop(); // 삭제만
		if (visited[top]) continue; // 이건 왜?
		visited[top] = true;

		cout << top << " ";
		for (int i : graph[top]) { // graph[1]에 저장된(=연결된) 원소 출력
			if (visited[i]) continue;
			q.push(i);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m; // n: 정점, m: 간선
		cin >> n >> m;
		while (m--) {
			int a, b; // 정점 번호
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bfs(1);
		cout << "\n";
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
			visited[i] = false;
		}
	}
}
/*
* void dfs(int x) {
	cout << x << " ";
	visited[x] = true;
	for (int i : graph[x]) {
		if (visited[i]) continue;
		dfs(i);
	}
}
*/