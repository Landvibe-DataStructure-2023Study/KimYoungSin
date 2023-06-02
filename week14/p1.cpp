// ���̿켱Ž��(DFS): �� �� �ִ¸�ŭ ����
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
	int n, m, q; // n: ���� ����(5<=n<=1000) m: ����, q: ����
	cin >> n >> m >> q;
	while (m--) {
		int a, b; // ���� ��ȣ
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
			// ó�� �Է¹��� �׷��� ���¸� Ž���� �ϴ°Ŵϱ� clear�� ��
			// graph[i].clear();
			visited[i] = false;
		}
	}
}
