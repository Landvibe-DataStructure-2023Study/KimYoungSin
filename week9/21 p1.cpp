// 삽입정렬 -> push할 때 정렬
// 오름차순 정렬 -> data가 현재 가리키는 값보다 작
#include <iostream>
#include <vector>
using namespace std;

class PQueue {
public:
	vector<int> pr;

	void push(int data){
		if (pr.empty()) pr.push_back(data);
		else {
			vector<int>::iterator iter;
			// 반복자 순회, 제일 작은 값이 앞에 있을거니까 한 번씩만 비교해줘도 됨
			for (iter = pr.begin(); iter != pr.end(); iter++) {
				if (data < *iter) {
					pr.insert(iter, data);
					return;
				}
			}
			// 끝까지 돌아도 다 못 찾은 경우
			pr.insert(pr.end(), data);
		}
	}
	int pop() {
		if (!pr.empty()) {
			int data = pr.front();
			pr.erase(pr.begin());
			return data;
		}
		else return 0;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> v; // 수열
		PQueue pq; // 우선순위 큐
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			v.push_back(data);
		}
		for (int i = 0; i < n; i++) {
			pq.push(v.front());
			v.erase(v.begin()); // 기존 수열벡터에 있던 거 빼줌

		}
		for (int i = 0; i < n; i++) {
			v.push_back(pq.pop());
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}