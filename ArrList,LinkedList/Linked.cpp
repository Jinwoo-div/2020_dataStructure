#include <iostream>
class Node {
public:
	int data;
	Node* next;
};

class S_LinkedList {
public:
	Node* head;
	Node* tail;
	S_LinkedList() {
		head = NULL;
		tail = NULL;
	}
	int empty() {
		if (head == NULL && tail == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void addFront(int x) {
		Node* v = new Node;
		v->data = x;
		if (empty()) {
			head = v;
			tail = v;
			v->next = nullptr;
		}
		else {
			v->next = head;
			head = v;
		}
		return;
	}
	void removeFront() {
		if (empty()) { std::cout << "-1" << "\n"; }
		else {
			Node* v = new Node;
			v = head;
			int tempNum = head->data;
			head = head->next;
			delete v;
			if (head == nullptr) {
				head = NULL;
				tail = NULL;
			}
			std::cout << tempNum << "\n";
		}
		return;
	}
	void front() {
		if (empty()) {
			std::cout << "-1\n";
		}
		else {
			std::cout << head->data << "\n";
		}
		return;
	}
};
		/*int List_Size() {
			int list_size = 1;
			if (Empty()) {
				return 0;
			}
			else {
				int count = 1;
				Node* cur = new Node;
				cur = head;
				while (1) {
					if (cur == NULL) {
						break;
					}
					cur = cur->next;
					count++;
				}
				return count;
			}
		}*/
	/*void Append(int x) {
		Node* v = new Node;
		v->next = NULL;
		v->data = x;
		tail->next = v;
		tail = v;
	}
	int Delete(int i) {
		if (Empty() || List_Size() < i) {
			return -1;
		}
		else {
			int count = 0;
			Node* cur = head;
			while (count == i - 1) {
				cur = cur->next;
				count++;
			}
			int tempNum = cur->next->data;
			cur->next = cur->next->next;
			return tempNum;
		}
	}*/
	/*void Print() {
		while (1) {
			std::cout << head->data;
			head = head->next;
			if (head->next == NULL) {
				break;
			}
		}
	}
	void Insert(int i, int x) {
		int count = 0;
		Node* cur_node = head;
		while (count == i - 1) {
			cur_node = head->next;
			head = head->next;
		}
		Node* new_node = NULL;
		new_node->data = x;
		new_node->next = cur_node->next->next;
		cur_node->next = new_node;
		delete cur_node;
		Print();
	}*/
int main() {
	S_LinkedList a;
	int M;
	std::string order;
	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> order;
		if (order == "addFront") {
			int i;
			std::cin >> i;
			a.addFront(i);
		}
		else if (order == "removeFront") {
			a.removeFront();
		}
		else if (order == "front") {
			a.front();
		}
		else if (order == "empty") { 
			std::cout << a.empty() << "\n"; 
		}
	}
	return 0;
}