
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt = 0;

void bfs(int x, int y) { // ����Լ� �ƴ�
	queue<int> q;
	q.push(x);

	cnt = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop(); // ������
		if (visited[top]) continue;
		visited[top] = true;

		if (top == y) cout << cnt;
		cnt++;
		for (int i : graph[top]) { // graph[1]�� �����(=�����) ���� ���
			if (visited[i]) continue;
			q.push(i);
		}
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
		bfs(a, b);
		cout << "\n";
		for (int i = 0; i < 1001; i++) {
			visited[i] = false;
		}
	}
}
