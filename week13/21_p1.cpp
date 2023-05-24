// ������� ����� ����׷���
#include <iostream>
using namespace std;

bool graph[2000][2000];
int main() {
	int t, n;
	int id; 
	cin >> t >> n;
	for (int i = 0; i < n; i++) { // ����� ���� ���� �ʴ� �ǹ� ���� �ڵ�
		cin >> id; 
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
		else if (cmd == "isAdjacentTo") {
			cin >> s >> d;
			if (graph[s][d]) cout << "True\n";
			else cout << "False\n";
		}
	}
}
