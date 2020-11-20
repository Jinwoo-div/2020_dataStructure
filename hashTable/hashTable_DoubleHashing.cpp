#include  <iostream>
#include <vector>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
};

class linearHashTable {
private:
	cell* hashArr;
	int arrSize;
	int curSize;
public:
	bool tf;
	linearHashTable(int size) {
		this->arrSize = size;
		hashArr = new cell[arrSize];
		curSize = 0;
		this->tf = true;
	}
	int hashFunc(int key) {
		return key % arrSize;
	}
	int hashFunc2(int key) {
		return (17 - (key % 17));
	}
	int find(int key) {
		int probing = 1;
		int iniIdx = hashFunc(key) % arrSize;
		int curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
		bool firstOpr = true;
		while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
			if (hashArr[curIdx].key == key) {
				tf = true;
				return probing;
			}
			else if (curIdx == iniIdx && !firstOpr) {
				cout << "loop" << endl;
				return probing;
			}
			probing += 1;
			firstOpr = false;
			curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
		}
		tf = false;
		return probing;
	}
	void put(int key, int value) {
		int probing = 1;
		int iniIdx = hashFunc(key) % arrSize;
		int curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
		bool firstOpr = true;
		if (isFull()) cout << "Full" << endl;
		else {
			while (hashArr[curIdx].flag == ISITEM) {
				if (curIdx == iniIdx && !firstOpr) {
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				firstOpr = false;
				curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
			}
			hashArr[curIdx].key = key;
			hashArr[curIdx].value = value;
			hashArr[curIdx].flag = ISITEM;
		}
		curSize++;
	}
	void erase(int key) {
		int probing = 1;
		int iniIdx = hashFunc(key) % arrSize;
		int curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
		bool firstOpr = true;
		if (isEmpty()) cout << "Empty" << endl;
		else {
			while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE) {
				if (hashArr[curIdx].key == key) {
					hashArr[curIdx].flag = AVAILABLE;
					hashArr[curIdx].value = -1;
					hashArr[curIdx].key = -1;
					break;
				}
				else if (curIdx == iniIdx && !firstOpr) {
					cout << "loop" << endl;
					break;
				}
				probing += 1;
				firstOpr = false;
				curIdx = (hashFunc(key) + (probing - 1) * hashFunc2(key)) % arrSize;
			}
		}
		curSize--;
	}
	bool isFull() {
		return (curSize == arrSize);
	}
	bool isEmpty() {
		return (curSize == 0);
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << hashArr[i].value << " ";
		}
	}
};

int main() {
	int caseNum, size, keyNum, key, findNum, find;
	cin >> caseNum;
	while (caseNum--) {
		cin >> size >> keyNum;
		linearHashTable t(size);
		while (keyNum--) {
			cin >> key;
			t.put(key, key);
		}
		cin >> findNum;
		vector<int>fina;
		while (findNum--) {
			cin >> find;
			fina.push_back(find);
		}
		for (int i = 0; i < fina.size(); i++) {
			int prob = t.find(fina[i]);
			if (t.tf == true) {
				cout << "True ";
			}
			else {
				cout << "False ";
			}
			cout << prob << endl;
		}
	}
}