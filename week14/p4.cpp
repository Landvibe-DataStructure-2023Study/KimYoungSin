#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int minor = 101;

void dfs(int x) {
	visited[x] = true;
	if (x < minor) minor = x;

	for (int i : graph[x]) {
		if (!visited[i]) dfs(i);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k; // n: 정점, m: 간선, k: 질의 개수
		cin >> n >> m >> k;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
		while (k--) {
			int c;
			cin >> c;
			minor = 101;
			dfs(c);
			cout << minor << "\n";
			for (int i = 0; i < 101; i++) { // visited 초기화
				visited[i] = false;
			}
		}
		for (int i = 0; i < 101; i++) {
			graph[i].clear();
		}
	}
}