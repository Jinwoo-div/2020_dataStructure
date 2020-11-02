#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

class LinkedList {
private:
	Node* header;
	Node* trailer;
	int size;
public:
	LinkedList() {
		this->header = new Node;
		this->trailer = new Node;
		this->header->next = trailer;
		this->trailer->prev = header;
		this->trailer->next = NULL;
		this->size = 0;
	}
	int listSize() {
		return this->size;
	}

	bool isEmpty() {
		if (size == 0) return true;
		return false;
	}

	void insert(int data, int pos) {
		if (this->size < pos - 1) {
			return;
		}
		Node* tempNode = new Node();
		Node* v = new Node();
		v->data = data;
		tempNode = this->header;
		for (int i = 0; i < pos; i++) {
			tempNode = tempNode->next;
		}
		v->prev = tempNode->prev;
		tempNode->prev->next = v;
		v->next = tempNode;
		tempNode->prev = v;
		this->size++;
	}
	int getFront() {
		return this->header->next->data;
	}

	void remove(int pos) {
		if (this->size < pos) return;
		Node* tempNode = new Node;
		tempNode = header;
		for (int i = 0; i < pos; i++) {
			tempNode = tempNode->next;
		}
		tempNode->prev->next = tempNode->next;
		tempNode->next->prev = tempNode->prev;
		delete tempNode;
		this->size--;
	}
};

class Stack {
private:
	LinkedList* li = new LinkedList();
public:
	int empty() {
		if (this->li->listSize() == 0) return 1;
		return 0;
	}
	int top() {
		if (this->empty() == 1) return -1;
		return this->li->getFront();
	}
	void push(int data) {
		this->li->insert(data, 1);
	}
	int pop() {
		if (this->empty() == 1) return -1;
		int tempdata = this->li->getFront();
		this->li->remove(1);
		return tempdata;
	}
	int size() {
		return this->li->listSize();
	}
};

int main() {
	Stack* st = new Stack;
	int orderNum;
	string order;
	cin >> orderNum;
	while (orderNum--) {
		cin >> order;
		if (order == "empty") {
			cout << st->empty() << "\n";
		}
		else if (order == "top") {
			cout << st->top() << "\n";
		}
		else if (order == "push") {
			int data;
			cin >> data;
			st->push(data);
		}
		else if (order == "pop") {
			cout << st->pop() << "\n";
		}
		else if (order == "size") {
			cout << st->size() << "\n";
		}
	}
}