#include <iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2 // 삭제할 땐 available 필요

class Entry {
public:
	int valid, num, classNum;
	bool attend;
	string name;

	Entry() {
		num = 0; // 학번
		classNum = 0; // 분반
		name = ""; // 이름
		attend = false; // 출석 여부
		valid = NOITEM;
	}
	Entry(int n, int c, string nm) {
		num = n;
		classNum = c;
		name = nm;
		attend = false; // add 조건 : 결석 상태로 설정
		valid = ISITEM;
	}
};
class Hash {
public:
	Entry* hashNum;
	Entry* hashName; // num, name 둘 다 이용하니까 배열 두 개 만들어줌
	int cap; // 용량
	int size;

	Hash() {
		cap = 200001;
		hashNum = new Entry[cap];
		hashName = new Entry[cap];
		size = 0;
	}
	int stringToInt(string s) {
		int result = 0;
		int cnt = 1;
		for (int i = 0; i < 6; i++) {
			result += (s[i] - 'a') * cnt;
			cnt *= 26;
		}
		return result;
	}
	int hashFunc(int key) {
		return key % cap;
	}
	void add(int x, int c, string s) {
		int nameIdx = hashFunc(stringToInt(s));
		int numIdx = hashFunc(x);

		while (hashName[nameIdx].valid == ISITEM) {
			nameIdx = hashFunc(nameIdx + 1);
		}
		hashName[nameIdx] = Entry(x, c, s);

		while (hashNum[numIdx].valid == ISITEM) {
			numIdx = hashFunc(numIdx + 1);
		}
		hashNum[numIdx] = Entry(x, c, s);
	}
	void remove(int x) {
		int numIdx = hashFunc(x);
		while (hashNum[numIdx].valid != NOITEM) {
			if (hashNum[numIdx].valid == ISITEM && hashNum[numIdx].num == x) {
				cout << hashNum[numIdx].name << " " << hashNum[numIdx].classNum << "\n";
				hashNum[numIdx].valid = AVAILABLE;
				break;
			}
			numIdx = hashFunc(numIdx + 1);
		}
		int nameIdx = hashFunc(stringToInt(hashNum[numIdx].name));

		while (hashName[nameIdx].valid != NOITEM) {
			if (hashName[nameIdx].valid == ISITEM && hashName[nameIdx].num == x) {
				hashName[nameIdx].valid = AVAILABLE;
				if (hashName[nameIdx].attend == true)
					size--;
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
	}
	void change(int x, int c) { // 학번 x인 학생의 분반을 c로 변경
		int numIdx = hashFunc(x);

		while (hashNum[numIdx].valid != NOITEM) {
			if (hashNum[numIdx].valid == ISITEM && hashNum[numIdx].num == x) {
				hashNum[numIdx].classNum = c;
				break;
			}
			numIdx = hashFunc(numIdx + 1);
		}

		int nameIdx = hashFunc(stringToInt(hashNum[numIdx].name));


		while (hashName[nameIdx].valid != NOITEM) {
			if (hashName[nameIdx].valid == ISITEM && hashName[nameIdx].num == x) {
				hashName[nameIdx].classNum = c;
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
	}
	void name(int x) { // 학번이 x인 학생의 이름 출력
		int numIdx = hashFunc(x);
		while (hashNum[numIdx].valid != NOITEM) {
			if (hashNum[numIdx].valid == ISITEM && hashNum[numIdx].num == x) {
				cout << hashNum[numIdx].name << "\n";
				return;
			}
			numIdx = hashFunc(numIdx + 1);
		}
	}
	void present(string s) { // 이름 s인 학생 -> 출석, 학번과 분반 출력 or invalid
		int nameIdx = hashFunc(stringToInt(s));
		while (hashName[nameIdx].valid != NOITEM) {
			if (hashName[nameIdx].valid == ISITEM && hashName[nameIdx].name == s) {
				if (hashName[nameIdx].attend == false) {
					size++;
				}
				
				hashName[nameIdx].attend = true;
				cout << hashName[nameIdx].num << " " << hashName[nameIdx].classNum << "\n";
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
		cout << "Invalid\n";
	}
	void absent(string s) { // 이름 s인 학생 -> 결석, 학번과 분반 출력 or invalid
		int nameIdx = hashFunc(stringToInt(s));
		while (hashName[nameIdx].valid != NOITEM) {
			if (hashName[nameIdx].valid == ISITEM && hashName[nameIdx].name == s) {
				if (hashName[nameIdx].attend == true) {
					size--;
				}

				hashName[nameIdx].attend = false;
				cout << hashName[nameIdx].num << " " << hashName[nameIdx].classNum << "\n";
				return;
			}
			nameIdx = hashFunc(nameIdx + 1);
		}
		cout << "Invalid\n";
	}
};
int main() {
	int t, x, c;
	string s;
	cin >> t;
	Hash h;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x >> c >> s;
			h.add(x, c, s);
		}
		else if (cmd == "delete") {
			cin >> x;
			h.remove(x);
		}
		else if (cmd == "name") {
			cin >> x;
			h.name(x);
		}
		else if (cmd == "change") {
			cin >> x >> c;
			h.change(x, c);
		}
		else if (cmd == "present") {
			cin >> s;
			h.present(s);
		}
		else if (cmd == "absent") {
			cin >> s;
			h.absent(s);
		}
	}
	cout << h.size << "\n";
}