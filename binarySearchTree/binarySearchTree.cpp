//#include <iostream>
//
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* leftChild;
//	Node* rightChild;
//	Node* parent;
//	Node() {
//		this->leftChild = NULL;
//		this->rightChild = NULL;
//		this->parent = NULL;
//		this->data = -1;
//	}
//
//	Node(int data) {
//		this->data = data;
//		Node();
//	}
//};
//
//class binarySearchTree {
//private:
//	Node* root;
//public:
//	binarySearchTree() {
//		this->root = NULL;
//	}
//
//	void insert(int inputData) {
//		Node* newNode = new Node(inputData);
//		Node* saveNode = NULL;
//
//		if (root == NULL) {
//			root = newNode;
//		}
//		else {
//			Node* curNode = root;
//			while (curNode != NULL) {
//				saveNode = curNode;
//				if (curNode->data == inputData) {
//					cout << "Duplication" << endl;
//					return;
//				}
//				else if (curNode->data > inputData) {
//					curNode = curNode->leftChild;
//				}
//				else {
//					curNode = curNode->rightChild;
//				}
//			}
//			newNode->parent = saveNode;
//			if (saveNode->data > inputData) {
//				saveNode->leftChild = newNode;
//			}
//			else {
//				saveNode->rightChild = newNode;
//			}
//		}
//	}
//
//	Node* find(int inputData) {
//		Node* curNode = root;
//		while (curNode != NULL) {
//			if (curNode->data == inputData) return curNode;
//			else if (curNode->data > inputData) {
//				curNode = curNode->leftChild;
//			}
//			else {
//				curNode = curNode->rightChild;
//			}
//		}
//		return NULL;
//	}
//
//	Node* minNode(Node* node) {
//		Node* curNode = node;
//		Node* saveNode = NULL;
//		while (curNode != NULL) {
//			saveNode = curNode;
//			curNode = curNode->leftChild;
//		}
//		return saveNode;
//	}
//
//	Node* maxNode(Node* node) {
//		Node* curNode = node;
//		Node* saveNode = NULL;
//		while (curNode != NULL) {
//			saveNode = curNode;
//			curNode = curNode->rightChild;
//		}
//		return saveNode;
//	}
//
//	void erase(int data) {
//		Node* curNode = find(data);
//		int numOfChild = bool(curNode->leftChild) + bool(curNode->rightChild);
//
//		if (numOfChild == 0) {
//			if (curNode == root) {
//				root = NULL;
//			}
//			else {
//				curNode->parent->leftChild = NULL;
//				curNode->parent->rightChild = NULL;
//				delete curNode;
//			}
//		}
//		else if (numOfChild == 1) {
//			if (curNode == root) {
//				if (curNode->leftChild != NULL) {
//					root = curNode->leftChild;
//				}
//				else {
//					root = curNode->rightChild;
//				}
//			}
//			else {
//				Node* curParent = curNode->parent;
//				Node* curChild = new Node();
//				if (curParent->leftChild == curNode) {
//					curChild = curNode->leftChild;
//					curParent->leftChild = curChild;
//				}
//				else {
//					curChild = curNode->rightChild;
//					curParent->rightChild = curChild;
//				}
//				delete curNode;
//			}
//		}
//		else if (numOfChild == 2) {
//			Node* min = minNode(curNode->rightChild);
//			int data = min->data;
//			erase(min->data);
//			curNode->data = data;
//		}
//	}
//};
//
//int main() {
//	int cas, size, num, x;
//	cin >> cas;
//	while (cas--) {
//		binarySearchTree tr;
//		cin >> size;
//		while (size--) {
//			cin >> num;
//			tr.insert(num);
//		}
//		cin >> x;
//		int max, min;
//		if (tr.find(x)->leftChild == NULL) {
//			min = x;
//		}
//		else {
//			min = tr.maxNode(tr.find(x)->leftChild)->data;
//		}
//		if (tr.find(x)->rightChild == NULL) {
//			max = x;
//		}
//		else {
//			max = tr.minNode(tr.find(x)->rightChild)->data;
//		}
//		cout << min << " " << max << endl;
//	}
//}