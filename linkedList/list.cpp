 class node {
public:
	int num;
	node* next;
};

class linkedList {
	node* head;
	node* tail;
	void addFront(int newNum) {
		node* v = new node;
		v->num = newNum;
		head = v;
		v->next = head;
	}
	void addTail(int newNum) {
		node* v = new node;
		v->num = newNum;
		v->next = nullptr;
		tail->next = v;
		tail = v;
	}
	void removeFront() {
		node* tephead = head;
		head = head->next;
		delete tephead;
	}
};