#include <iostream>
#include <vector>
using namespace std;

bool graph[10001][10001]; // 1 <= S <= 10000
vector<int> v;

/*bool isV(int a) { // ��ü graph�� �˻��ϸ鼭 �̰ű��� ���� timeLimit
	bool result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == a) result = 1;
	}
	return result;
}*/

int main() {
	int t, s, d;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insertVertex") {
			bool result = false;
			cin >> s;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == s) result = true;
			}
			if (result) cout << "Exist\n";
			else v.push_back(s);
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			if (graph[s][d]) cout << "Exist\n";
			else graph[s][d] = graph[d][s] = true;
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			if (!graph[s][d]) cout << "None\n";
			else graph[s][d] = graph[d][s] = false;
		}
		else if (cmd == "isAdjacentOdd") {
			int cnt = 0;
			cin >> s;
			for (int i = 1; i < 10001; i++) {
				if (graph[s][i]) cnt++;
			}
			if (cnt % 2 == 1) cout << "True" << " " << cnt;
			else cout << "False" << " " << cnt;
			cout << "\n";
		}
		else if (cmd == "minEdgeVertex") {
			int cnt = 0, min = 10001;
			bool result = false;
			int vertex; // �ش�Ǵ� ����
			for (int i : v) { // ���ʿ� ������ �˻��ϸ� isV�� �ʿ� x
				cnt = 0;
				for (int j : v) {
					if (i == j) continue;
					if (graph[i][j]) {
						cnt++;;
					}
				}
				if (cnt == min) { // min�̶� ���ٸ� �� ���� ��������
					vertex = (i < vertex ? i : vertex);
				}
				else if (cnt < min) { // ���ϰ� �ƴ϶� �̸����� �صθ� �ߺ� �ڵ�����(���� ���� ����)
					result = true;
					min = cnt;
					vertex = i;
				}
			}
			if (!result || min == 0) cout << "-1\n";
			else cout << vertex << "\n";
		}
	}
}