// ������� ����� ����׷���
#include <iostream>
#include <vector>
using namespace std;

bool graph[2000][2000];
int main() {
	int t, n;
	int id;
	cin >> t >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) { // ����� ���� ���� �ʴ� �ǹ� ���� �ڵ�
		cin >> id;
		v.push_back(id);
	}

	while (t--) {
		int s, d;
		string cmd;
		cin >> cmd;
		if (cmd == "insertEdge") {
			cin >> s >> d;
			if (graph[s][d]) cout << "Exist\n";
			else graph[s][d] = graph[d][s] = true;
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			if (!graph[s][d]) cout << "None\n";
			else graph[s][d] = graph[d][s] = false;
		}
		else if (cmd == "incidentEdges") {
			int cnt = 0;
			cin >> s;
			for (int i = 0; i < n; i++) {
				if (graph[s][v[i]] == true || graph[v[i]][s] == true) cnt++;
			}
			cout << cnt << "\n";
		}
	}
}
