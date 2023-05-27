#include <iostream>
#include <vector>
using namespace std;

bool graph[10001][10001]; // 1 <= S <= 10000
vector<int> v;

int main() {
	int t, s, d;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insertVertex") {
			bool result = false;
			cin >> s;
			for (int i : v) {
				if (i == s) result = true;
			}
			if (result) cout << "Exist\n";
			else v.push_back(s);
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			if (graph[s][d]) cout << "Exist\n";
			else graph[s][d] = graph[d][s] = true;
		}
		else if (cmd == "eraseVertex") { // vertex 지우면 간선도 지워야 됨
			cin >> s;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == s) v.erase(v.begin() + i);
			}
			for (int i = 1; i < 10001; i++) {
				graph[s][i] = graph[i][s] = false;
			}
		}
		else if (cmd == "isAdjacentEven") {
			int cnt = 0;
			cin >> s;
			for (int i = 1; i < 10001; i++) {
				if (graph[s][i]) cnt++;
			}
			if (cnt % 2 == 0) cout << "True" << " " << cnt;
			else cout << "False" << " " << cnt;
			cout << "\n";
		}
		else if (cmd == "maxEdgeVertex") {
			int cnt = 0, max = 0;
			bool result = false;
			int vertex; // 해당되는 정점
			for (int i : v) { // 애초에 정점만 검사하면 isV는 필요 x
				cnt = 0;
				for (int j : v) {
					if (i == j) continue;
					if (graph[i][j]) {
						cnt++;;
					}
				}
				if (cnt == max) { // max랑 같다면 더 작은 정점으로
					vertex = (i < vertex ? i : vertex);
				}
				else if (cnt > max) { // 이하가 아니라 미만으로 해두면 중복 자동제거(가장 작은 정점)
					result = true;
					max = cnt;
					vertex = i;
				}
			}
			if (!result || max == 0) cout << "-1\n";
			else cout << vertex << "\n";
		}
	}
}