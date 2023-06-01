#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];
int cnt = 0;

void bfs(int x) { // ����Լ� �ƴ�
	queue<int> q;
	q.push(1);

	cnt = 1;
	while (!q.empty()) {
		int top = q.front();
		q.pop(); // ������
		if (visited[top]) continue;
		visited[top] = true;
		
		if(cnt % 2 == 1) cout << top << " ";
		cnt++;
		for (int i : graph[top]) { // graph[1]�� �����(=�����) ���� ���
			if (visited[i]) continue;
			q.push(i);
		}
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
		cnt = 0;
		bfs(1);
		cout << "\n";
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
			visited[i] = false;
		}
	}
}
