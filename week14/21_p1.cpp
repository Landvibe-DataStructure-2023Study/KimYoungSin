// ���̿켱Ž��(DFS): �� �� �ִ¸�ŭ ����
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs(int x) {
	cout << x << " ";
	visited[x] = true;
	for (int i : graph[x]) {
		if (visited[i]) continue;
		dfs(i);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m; // n: ����, m: ����
		cin >> n >> m;
		while (m--) {
			int a, b; // ���� ��ȣ
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1);
		cout << "\n";
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
			visited[i] = false;
		}
	}
}