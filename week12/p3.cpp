#include <iostream>
using namespace std;
#define AVAILABLE 2

int cnt = 0;
struct Entry {
	int key;
	string value;
	int valid;

	Entry() {
		key = 0;
		value = "";
		valid = 0;
	}
	Entry(int k, string v) {
		key = k;
		value = v;
		valid = 1;
	}
};
class Hash {
private:
	Entry* hash;
	int cap;
	int divisor;
public:
	Hash(int c, int d) {
		cap = c;
		divisor = d;
		hash = new Entry[cap];
	}
	int hashFunc(int key) {
		return key % cap;
	}
	int hashFunc2(int key) {
		return divisor - (key % divisor);
	}
	void put(int key, string value) {
		int idx = hashFunc(key);
		int probing = 1;

		while (1) {
			if (hash[idx].valid != 1) {
				hash[idx] = Entry(key, value);
				cout << probing + idx << "\n";
				cnt++;
				return;
			}
			idx = hashFunc(idx + hashFunc2(key));
			probing++;
			if (probing > cap) return;
		}
	}
	void erase(int key) {
		int idx = hashFunc(key);
		while (1) {
			if (hash[idx].valid == 0) {
				cout << "None\n";
				return;
			}
			if (hash[idx].key == key) {
				hash[idx].valid = AVAILABLE;
				//hash[idx].value = ""; hash[idx].key = 0;
				cout << hash[idx].value << "\n";
				cnt--;
				return;
			}
			idx = hashFunc(idx + hashFunc2(key));
		}
	}
	
	void find(int key) {
		int idx = hashFunc(key);
		while (1) {
			if (hash[idx].valid == 0) {
				cout << "None\n";
				return;
			}
			if (hash[idx].key == key) {
				cout << hash[idx].value << "\n";
				return;
			}
			idx = hashFunc(idx + hashFunc2(key));
		}
	}
	/*void vacant() {
		int idx = 0;
		int cnt = 0;
		while (idx < cap) {
			if (hash[idx].valid != 1)cnt++;
			idx++;
		}
		cout << cnt << "\n";
	}*/
};
int main() {
	int t, n, m;
	cin >> t >> n >> m; // m = divisor
	Hash h(n, m);

	while (t--) {
		string s;
		cin >> s;

		if (s == "put") {
			int key;
			string value;
			cin >> key >> value;
			h.put(key, value);
		}
		else if (s == "erase") {
			int key;
			cin >> key;
			h.erase(key);
		}
		else if (s == "find") {
			int key;
			cin >> key;
			h.find(key);
		}
		else if (s == "vacant") {
			cout << n - cnt << "\n";
		}
	}
}