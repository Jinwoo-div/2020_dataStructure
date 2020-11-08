//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//enum direction { MIN = 1, MAX = -1 };
//
//class heap {
//private:
//	vector<int> v;
//	int heapSize;
//	int rootIndex;
//	int direction;
//public:
//	heap(int direction) {
//		this->v.push_back(-1);
//		this->heapSize = 0;
//		this->rootIndex = 1;
//		this->direction = direction;
//	}
//	void swap(int idx1, int idx2) {
//		v[0] = v[idx1];
//		v[idx1] = v[idx2];
//		v[idx2] = v[0];
//		v[0] = -1;
//	}
//	void upHeap(int idx) {
//		if (idx == rootIndex) return;
//		int parent = idx / 2;
//		if (v[parent] * direction > v[idx] * direction) {
//			swap(parent, idx);
//			upHeap(parent);
//		}
//	}
//	void downHeap(int idx) {
//		int left = idx * 2;
//		int right = idx * 2 + 1;
//		if (right <= heapSize) {
//			if (v[left] * direction <= v[right] * direction) {
//				if (v[left] * direction < v[idx] * direction) {
//					swap(left, idx);
//					downHeap(left);
//				}
//				else return;
//			}
//			else {
//				if (v[right] * direction < v[idx] * direction) {
//					swap(right, idx);
//					downHeap(right);
//				}
//				else return;
//			}
//		}
//		else if (left <= heapSize) {
//			if (v[left] * direction <= v[right] * direction) {
//				if (v[left] * direction < v[idx] * direction) {
//					swap(left, idx);
//					downHeap(left);
//				}
//				else return;
//			}
//		}
//		else return;
//	}
//	void insert(int e) {
//		v.push_back(e);
//		heapSize++;
//		upHeap(heapSize);
//	}
//	int pop() {
//		int top = v[rootIndex];
//		v[rootIndex] = v[heapSize];
//		heapSize--;
//		v.pop_back();
//		downHeap(rootIndex);
//		return top;
//	}
//	int top() {
//		return v[rootIndex];
//	}
//	int size() {
//		return heapSize;
//	}
//	bool isEmpty() {
//		if (heapSize == 0) return true;
//		else return false;
//	}
//	void print() {
//		if (isEmpty() == false) {
//			for (int i = rootIndex; i < heapSize; i++) {
//				cout << v[i] << " ";
//			}
//			cout << v[heapSize] << endl;
//		}
//		else cout << -1 << endl;
//	}
//	int find(int x) {
//		if (isEmpty() == false) return v.at(x);
//	}
//};
//
//int main() {
//	heap h(MAX);
//	int num;
//	string order;
//	cin >> num;
//	while (num--) {
//		cin >> order;
//		if (order == "insert") {
//			int element;
//			cin >> element;
//			h.insert(element);
//		}
//		else if (order == "size") {
//			cout << h.size() << endl;
//		}
//		else if (order == "isEmpty") {
//			cout << h.isEmpty() << endl;
//		}
//		else if (order == "pop") {
//			if (h.isEmpty() == true) {
//				cout << -1 << endl;
//			}
//			else {
//				cout << h.pop() << endl;
//			}
//		}
//		else if (order == "top") {
//			if (h.isEmpty() == true) {
//				cout << -1 << endl;
//			}
//			else {
//				cout << h.top() << endl;
//			}
//		}
//		else {
//			h.print();
//		}
//	}
//}
