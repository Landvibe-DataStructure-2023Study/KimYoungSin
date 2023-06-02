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
		int n, m, k; // n: ����, m: ����, k: ���� ����
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
			for (int i = 0; i < 101; i++) { // visited �ʱ�ȭ
				visited[i] = false;
			}
		}
		for (int i = 0; i < 101; i++) {
			graph[i].clear();
		}
	}
}