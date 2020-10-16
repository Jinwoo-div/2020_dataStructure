#include <iostream>
#include <string>
using namespace std;

class arrQueue {
public:
	int arrSize;
	int arrFront;
	int currentSize;
	int rear;
	int* arr;
	arrQueue(int size) {
		this->arrFront = 0;
		this->rear = -1;
		this->arrSize = size;
		this->currentSize = 0;
		arr = new int[this->arrSize + 1];
		for (int i = 0; i < this->arrSize + 1; i++) {
			arr[i] = 0;
		}
	}
	int isEmpty() {
		if (currentSize == 0) return 1;
		else return 0;
	}
	int size() {
		return currentSize;
	}
	int enqueue(int data) {
		if (currentSize != arrSize) {
			rear = (rear + 1) % arrSize;
			arr[rear] = data;
			currentSize++;
			return 0;
		}
		else return -1;
	}
	int dequeue() {
		if (isEmpty()) return -1;
		else {
			int temp = arr[arrFront];
			arr[arrFront] = 0;
			arrFront = (arrFront + 1) % arrSize;
			currentSize--;
			return temp;
		}
	}
	int front() {
		if (isEmpty()) return -1;
		else {
			return arr[arrFront];
		}
	}
	int getRear() {
		if (isEmpty()) return -1;
		else {
			return arr[rear];
		}
	}
};

int main() {
	int size;
	cin >> size;
	int n;
	cin >> n;
	arrQueue Q(size);
	while (n--) {
		string order;
		cin >> order;
		if (order == "enqueue") {
			int a;
			cin >> a;
			int temp = Q.enqueue(a);
			if (temp == -1 ) {
				cout << "Full" << endl;
			}
		}
		else if (order == "dequeue") {
			int temp = Q.dequeue();
			if (temp == -1) {
				cout << "Empty" << endl;
			}
			else {
				cout << temp << endl;
			}
		}
		else if (order == "size") {
			cout << Q.size() << endl;
		}
		else if (order == "isEmpty") {
			cout << Q.isEmpty() << endl;
		}
		else if (order == "front") {
			if (Q.isEmpty()) {
				cout << "Empty" << endl;
			}
			else cout << Q.front() << endl;
		}
		else if (order == "rear") {
			if (Q.isEmpty()) {
				cout << "Empty" << endl;
			}
			else cout << Q.getRear() << endl;
		}
	}
	return 0;
}