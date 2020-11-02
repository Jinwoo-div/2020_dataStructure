//#include <iostream>
//#include <string>
//using namespace std;
//class Array_Stack {
//public:
//	int* Stack;
//	int capacity;
//	int t;
//
//	Array_Stack(int capacity) {
//		this->capacity = capacity;
//		this->Stack = new int[capacity];
//		this->t = -1;
//	}
//	int size() {
//		return t + 1;
//	}
//	bool empty() {
//		return t == -1;
//	}
//	int top() {
//		if (empty()) return -1;
//		else return Stack[t];
//	}
//	void push(int e) {
//		if (size() == capacity) cout << "Full" << endl;
//		else Stack[++t] = e;
//	}
//	int pop() {
//		if (empty()) return -1;
//		return Stack[t--];
//	}
//};
//
//bool isOper(char item) {
//	if (item == '+' || item == '-' || item == '*') {
//		return true;
//	}
//	else return false;
//}
//
//bool isNum(char item) {
//	int i;
//	if (typeid(item - '0') == typeid(int)) {
//		return true;
//	}
//	else return false;
//}
//
//int getOper_order(char op) {
//	switch (op)
//	{
//	case '*':
//		return 2;
//	case '+':
//		return 1;
//	case '-':
//		return 1;
//	}
//}
//
//int compareOper(char op1, char op2) {
//	int op1Prec = getOper_order(op1);
//	int op2Prec = getOper_order(op2);
//
//	if (op1Prec > op2Prec)
//		return 1;
//	else if (op1Prec < op2Prec)
//		return -1;
//	else
//		return 0;
//}
//
//int calPostfix(string exp) {
//	Array_Stack S(10000);
//	string postfix = exp;
//	int n = postfix.size();
//	char testch;
//
//	for (int i = 0; i < n; i++) {
//		testch = exp.at(i);
//		if (isNum(testch)) {
//			S.push(testch);
//		}
//		else if (isOper(testch)) {
//			S.push
//		}
//		else {	
//
//		}
//	}
//
//int main() {
//	Array_Stack a(10000);
//	int M;
//	string order;
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> order;
//		if (order == "empty") {
//			cout << a.empty() << endl;
//		}
//		else if (order == "top") {
//			cout << a.top() << endl;
//		}
//		else if (order == "push") {
//			int x;
//			cin >> x;
//			a.push(x);
//		}
//		else if (order == "pop") {
//			cout << a.pop() << endl;
//		}
//		else if (order == "size") {
//			cout << a.size() << endl;
//		}
//	}
//	return 0;
//}