#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int maxValue = 0;
// p2�� ����������, max�� �̹� �����ؼ� ������ �ٲ������

void dfs(int x) { // x���� ���� -> y�� �� ���
	visited[x] = true;
	if (x > maxValue) maxValue = x;

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
			graph[b].push_back(a);
		}
		while (k--) {
			int c;
			cin >> c;
			maxValue = 0;
			dfs(c);
			cout << maxValue << "\n";
			for (int i = 0; i < 101; i++) { // visited �ʱ�ȭ
				visited[i] = false;
			}
		}
		for (int i = 0; i < 101; i++) {
			graph[i].clear();
		}
	}
}