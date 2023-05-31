#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];
int cnt;
void dfs(int x) { // x부터 시작 -> y일 때 출력
	visited[x] = true;

	for (int i : graph[x]) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (k--) {
			int c;
			cin >> c;
			cnt = 0;
			dfs(c);
			cout << cnt + 1;
			cout << endl;
			//cout << dfs(c, 0) + 1 << "\n";
		}
		for (int i = 0; i < 101; i++) {
			visited[i] = false;
			graph[i].clear();
		}
	}
}