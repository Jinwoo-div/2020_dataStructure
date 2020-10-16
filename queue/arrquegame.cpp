#include <iostream>
#include <string>
#include <random>

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

class player {
public:
	arrQueue *Q;
	int	loseCount;
	bool win;
	int extraHP;
	player(arrQueue* Q) {
		this->Q = Q;
		loseCount = 0;
		extraHP = 0;
		win = false;
	}
	void lose(int h) {
		loseCount++;
		win = false;
		if (h > 1) extraHP = h - 1;
		else extraHP = 0;
	}
	void Win() {
		win = true;
	}
	int showCard() {
		if (win == false) return extraHP + Q->dequeue();
		else return Q->dequeue();
	}
};

int main() {
	cin.tie(NULL);
	int gameCount, cardCount;
	cin >> gameCount;
	arrQueue winner(gameCount);
	while (gameCount != 0) {
		cin >> cardCount;
		arrQueue c1(cardCount), c2(cardCount);
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
		player p1(&c1), p2(&c2);
		int size = c1.size();
		while (size != 0) {
			int card1 = p1.showCard();
			int card2 = p2.showCard();
			if (card1 > card2) {
				p1.Win();
				p2.lose(card1 - card2);
			}
			else if (card1 < card2) {
				p2.Win();
				p1.lose(card2 - card1);
			}
			else {
				p1.Win();
				p2.Win();
			}
			size--;
		}
		if (p1.loseCount > p2.loseCount) winner.enqueue(2);
		else if (p1.loseCount < p2.loseCount)  winner.enqueue(1);
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