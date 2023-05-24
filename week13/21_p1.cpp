// 인접행렬 기반의 무향그래프
#include <iostream>
using namespace std;

bool graph[2000][2000];
int main() {
	int t, n;
	int id; 
	cin >> t >> n;
	for (int i = 0; i < n; i++) { // 결과에 영향 주지 않는 의미 없는 코드
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
