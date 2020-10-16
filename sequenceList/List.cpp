#include <iostream>
#include <string>
using namespace std;
class node {
public:
	int data;
	node* next;
	node* prev;
};

class sequenceList {
public:
	class iterator {
	public:
		node* p;
		iterator(node* v) {
			this->p = v;
		}
		int operator*(iterator& v) {
			return v.p->data;
		}
		iterator& operator++() {
			p = p->next;
			return *this;
		}
		iterator& operator--() {
			p = p->prev;
			return *this;
		}
		bool operator!=(iterator& v) {
			if (v.p != p) return true;
			return false;
		}
		bool operator==(iterator& v) {
			if (v.p == p) return true;
			return false;
		}
	};
	node* header;
	node* trailer;
	int size;
	sequenceList() {
		this->header = new node;
		this->trailer = new node;
		this->header->next = this->trailer;
		this->trailer->prev = this->header;
		this->size = 0;
	}
	int isempty() {
		if (size == 0) return 1;
		return 0;
	}
	int listsize() {
		return size;
	}
	iterator begin() {
		return iterator(header->next);
	}
	iterator end() {
		return iterator(trailer);
	}
	void insert(iterator& p, int data) {
		node* v = new node;
		v->data = data;
		v->next = p.p;
		v->prev = p.p->prev;
		p.p->prev = v;
		v->prev->next = v;
		size++;
	}
	int erase(iterator& p) {
		if (isempty() == 0) {
			p.p->next->prev = p.p->prev;
			p.p->prev->next = p.p->next;
			delete p.p;
			size--;
			return 0;
		}
		return 1;
	}
	int print() {
		if (isempty() == 1) return 1;
		node* tmp = trailer;
		for (int i = 0; i < size; i++) {
			cout << tmp->prev->data << "\n";
			tmp = tmp->prev;
		}
		return 0;
	}
};

int main() {
	sequenceList L;
	sequenceList::iterator iter(L.begin().p);
	int size;
	string order;
	cin >> size;
	while (size--) {
		cin >> order;
		if (order == "insert") {
			int a;
			cin >> a;
			L.insert(iter, a);
		}
		else if (order == "erase") {
			int re = L.erase(iter);
			if (re == 1) cout << "Empty" << "\n";
		}
		else if (order == "size") {
			cout << L.listsize() << "\n";
		}
		else if (order == "begin") {
			iter = L.begin();
		}
		else if (order == "end") {
			iter = L.end();
		}
		else if (order == "++") {
			++iter;
		}
		else if (order == "--") {
			--iter;
		}
		else if (order == "reversePrint") {
			int re = L.print();
			if (re == 1) cout << "Empty" << "\n";
			else cout << "\n";
		}
	}
	return 0;
}