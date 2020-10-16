#include <iostream>
#include <string>
#include <random>

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

class player {
public:
	LinkedQueue Q;
	int winCount;
	bool win;
	int extraHP;
	player(LinkedQueue Q) {
		this->Q = Q;
		winCount = 0;
		extraHP = 0;
		win = 0;
	}
	void lose() {
		win = false;
	}
	void Win(int h) {
		winCount++;
		win = true;
		if (h > 1) extraHP = h - 1;
		else extraHP = 0;
	}
	int showCard() {
		if (win == true) return extraHP + Q.dequeue();
		else return Q.dequeue();
	}
};

int main() {
	cin.tie(NULL);
	int gameCount, cardCount;
	cin >> gameCount;
	LinkedQueue c1, c2, winner;
	while (gameCount != 0) {
		cin >> cardCount;
		int cardCount2 = cardCount;
		while (cardCount != 0) {
			int temp;
			cin >> temp;
			c1.enqueue(temp);
			cardCount--;
		}
		while (cardCount2 != 0) {
			int temp;
			cin >> temp;
			c2.enqueue(temp);
			cardCount2--;
		}
		player p1(c1), p2(c2);
		int size = c1.size();
		while (size != 0) {
			int card1 = p1.showCard();
			int card2 = p2.showCard();
			if (card1 > card2) {
				p1.Win(card1 - card2);
				p2.lose();
			}
			else if (card1 < card2) {
				p2.Win(card2 - card1);
				p1.lose();
			}
			else {
				p1.lose();
				p2.lose();
			}
			size--;
		}
		if (p1.winCount > p2.winCount) winner.enqueue(1);
		else if (p1.winCount < p2.winCount)  winner.enqueue(2);
		else winner.enqueue(0);
		gameCount--;
	}
	int size = winner.size();
	while (size != 0) {
		cout << winner.dequeue() << "\n";
		size--;
	}
	return 0;
}
