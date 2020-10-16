#include <iostream>
#include <string>
using namespace std;
class node {
public:
	int data;
	node* next;
};

class linkedList {
public:
	node* f;
	node* r;
	linkedList() {
		this->f = NULL;
		this->r = NULL;
	}
	int front() {
		return f->data;
	}
	int end() {
		return r->data;
	}
	void addEnd(int data) {
		node* v = new node;
		v->next = NULL;
		v->data = data;
		if (f == NULL) {
			r = v;
			f = v;
		}
		else {
			r->next = v;
			r = v;
		}
	}
	int removeFront() {
		if (f != NULL) {
			node* tmp = f;
			int tmp_int = f->data;
			f = f->next;
			delete tmp;
			return tmp_int;
		}
		return -1;
	}
};

class LinkedQueue {
public:
	linkedList* S;
	int n;
	LinkedQueue() {
		this->S = new linkedList();
		this->n = 0;
	}
	int size() {
		return n;
	}
	int isEmpty() {
		if (n == 0) return 1;
		else return 0;
	}
	int front() {
		if (isEmpty() == 1) return 1;
		else return S->front();
	}
	int rear() {
		if (isEmpty() == 1) return 1;
		else return S->end();
	}
	void enqueue(int e) {
		n++;
		S->addEnd(e);
	}
	int dequeue() {
		if (isEmpty() == 1) { return -1; }
		else {
			int num = S->removeFront();
			n--;
			return num;
		}
	}
};


int main() {
	int size;
	cin >> size;
	int originalSize = size;
	int n;
	cin >> n;
	LinkedQueue Q;
	while (n--) {
		string order;
		cin >> order;
		if (order == "enqueue") {
			int a;
			cin >> a;
			if (size == 0) {
				cout << "Full" << endl;
			}
			else {
				Q.enqueue(a);
				size--;
			}
		}
		else if (order == "dequeue") {
			if (size == originalSize) {
				cout << "Empty" << endl;
			}
			else {
				cout << Q.dequeue() << endl;
				size++;
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
			else cout << Q.rear() << endl;
		}
	}
	return 0;
}
