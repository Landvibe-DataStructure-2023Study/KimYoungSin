#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs(int x, int y, int cnt) { // x���� ���� -> y�� �� ���
	//cout << x << " ";
	visited[x] = true;
	if (x == y) {
		cout << cnt << "\n";
		return;
	}
	
	for (int i : graph[x]) {
		//if (visited[i]) continue;
		if(!visited[i]) dfs(i, y, cnt + 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k; // n: ����, m: ����, k: ���� ����
		cin >> n >> m >> k;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (k--) {
			int c, d;
			cin >> c >> d;
			dfs(c, d, 0);
			if (!visited[d]) cout << "0\n";
			for (int i = 0; i < 101; i++) {
				visited[i] = false;
			}
		}
		for (int i = 0; i < 101; i++) {
			graph[i].clear();
		}
	}
}