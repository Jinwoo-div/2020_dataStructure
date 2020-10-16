#include <iostream>
#include <string>
class Array {
public:
	int arr[10000];
	Array() {
		for (int i = 0; i < 10000; i++) {
			arr[i] = 0;
		}
	}
	void At(int i) {
		if (i >= Find_Max()) {
			std::cout << "0" << "\n";
			return;
		}
		std::cout << arr[i] << "\n";
	}
	/*void Delete(int i) {
		int tempNum = arr[i];
		for (; i < 9999; i++) {
			arr[i] = arr[i + 1];
		}
		arr[10000] = 0;
		std::cout << tempNum << "\n";
	}*/
	void set(int i, int val) {
		if (i >= Find_Max()) {
			std::cout << "0" << "\n";
			return;
		}
		arr[i] = val;
	}
	int Find_Max() {
		int p = 0;
		while (1) {
			if (arr[p] == 0) {
				int idx = p;
				return idx;
			}
			p++;
		}
	}
	void add(int i, int val) {
		int lasti = Find_Max();
		if (i >= lasti) {
			arr[lasti] = val;
		}
		else if (lasti > 10000) {
			arr[0] = val;
		}
		else {
			for (; i != lasti; lasti--) {
				arr[lasti] = arr[lasti - 1];
			}
			arr[i] = val;
		}
	}
};
int main() {
	Array a;
	int M;
	std::string order;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> order;
		if (order == "at") {
			int i;
			std::cin >> i;
			a.At(i);
		}
		else if (order == "set") {
			int i, val;
			std::cin >> i >> val;
			a.set(i, val);
		}
		else if (order == "add") {
			int i, val;
			std::cin >> i >> val;
			a.add(i, val);
		}
	}
}