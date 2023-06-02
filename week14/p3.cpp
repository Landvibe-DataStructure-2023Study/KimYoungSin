
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt = 0;

void bfs(int x, int y) { // 재귀함수 아님
	queue<int> q;
	q.push(x);

	cnt = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop(); // 삭제만
		if (visited[top]) continue;
		visited[top] = true;

		if (top == y) cout << cnt;
		cnt++;
		for (int i : graph[top]) { // graph[1]에 저장된(=연결된) 원소 출력
			if (visited[i]) continue;
			q.push(i);
		}
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
		bfs(a, b);
		cout << "\n";
		for (int i = 0; i < 1001; i++) {
			visited[i] = false;
		}
	}
}
