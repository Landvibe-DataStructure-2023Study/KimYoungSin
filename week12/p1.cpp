#include <iostream>
using namespace std;
#define AVAILABLE 2

struct Entry {
	int key;
	string value;
	int valid;
	
	Entry() {
		key = 0;
		value = "";
		valid = 0;
	}
	Entry(int k, string v) { // 찾은 거 저장할 때
		key = k;
		value = v;
		valid = 1;
	}
};
class Hash {
private:
	Entry* hash;
	int cap;
public:
	Hash(int c) {
		cap = c;
		hash = new Entry[cap];
	}
	int hashFunc(int key) {
		return key % cap;
	}
	void put(int key, string value) {
		int idx = hashFunc(key);
		int probing = 1;

		while (hash[idx].valid == 1 && probing <= cap) {
			idx = hashFunc(idx + 1);
			probing++;
		}
		hash[idx] = Entry(key, value);
		cout << probing + idx << "\n";
		//if (probing > cap) return;
		
	}
	void erase(int key) {
		int idx = hashFunc(key);
		int probing = 1;

		while (hash[idx].valid != 0 && probing <= cap) {
			if (hash[idx].valid == 1 && hash[idx].key == key) {
				hash[idx].valid = AVAILABLE;
				cout << hash[idx].value << "\n";
				return;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		cout << "None\n";
	}
	string find(int key) {
		int idx = hashFunc(key);
		int probing = 1;
		
		while (hash[idx].valid != 0 && probing <= cap) {
			if (hash[idx].valid == 1 && hash[idx].key == key) {
				return hash[idx].value;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		return "None";
	}
	void vacant() {
		int idx = 0;
		int cnt = 0;
		while (idx < cap) {
			if (hash[idx].valid != 1)cnt++;
			idx++;
		}
		cout << cnt << "\n";
	}
};
int main() {
	int t, n;
	cin >> t >> n;
	Hash h(n);

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
			cout << h.find(key) << "\n";
		}
		else if (s == "vacant") {
			h.vacant();
		}	
	}
}
