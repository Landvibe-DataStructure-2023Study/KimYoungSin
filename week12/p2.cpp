#include <iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1

class Entry {
public:
	int valid;
	string i, p;
	bool log; // login 여부

	Entry() {
		valid = NOITEM;
		log = false;
		i = "";
		p = "";
	}
	Entry(string i, string p) {
		valid = ISITEM;
		log = false;
		this->i = i; // i가 색깔 같은 거로 뜨는 오류 있어서 this 써줌
		this->p = p;
	}
};
class Hash {
public:
	Entry* hash;
	int cap; // 용량

	Hash() {
		cap = 200001;
		hash = new Entry[cap];
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
	void signup(string i, string p) {
		int k = stringToInt(i);
		int idx = hashFunc(k);

		while (hash[idx].valid == ISITEM) {
			if (hash[idx].i == i) {
				cout << "Invalid" << " " << hash[idx].p << "\n";
				return;
			}
			idx = hashFunc(idx + 1);
		}
		hash[idx] = Entry(i, p);
		cout << "Submit\n";
	}
	void login(string i, string p) {
		int k = stringToInt(i);
		int idx = hashFunc(k);

		while (hash[idx].valid == ISITEM) {
			if (hash[idx].i == i && hash[idx].p == p && hash[idx].log == true) {
				cout << "Quit\n";
				return;
			}
	        else if (hash[idx].i == i && hash[idx].p == p && hash[idx].log == false) {
				hash[idx].log = true;
				cout << "Submit\n";
				return;
			}
			idx = hashFunc(idx + 1);
		}
		cout << "Invalid\n";
	}
	void logout(string i) {
		int k = stringToInt(i);
		int idx = hashFunc(k);

		while (hash[idx].valid == ISITEM) {
			if (hash[idx].i == i) {
				hash[idx].log = false;
			}
			idx = hashFunc(idx + 1);
		}
		cout << "Submit\n";
	}
	void change(string i, string p) {
		int k = stringToInt(i);
		int idx = hashFunc(k);

		while (hash[idx].valid == ISITEM) {
			if (hash[idx].i == i) {
				hash[idx].p = p;
			}
			idx = hashFunc(idx + 1);
		}
		cout << "Submit\n";
	}
};
int main() {
	int t;
	cin >> t;
	Hash h;
	while (t--) {
		string s;
		cin >> s;
		if (s == "signup") {
			string i, p;
			cin >> i >> p;
			h.signup(i, p);
		}
		else if (s == "login") {
			string i, p;
			cin >> i >> p;
			h.login(i, p);
		}
		else if (s == "logout") {
			string i;
			cin >> i;
			h.logout(i);
		}
		else if (s == "change") {
			string i, p;
			cin >> i >> p;
			h.change(i, p);
		}
	}
}