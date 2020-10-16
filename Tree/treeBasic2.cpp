//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* par;
//	vector<Node*> chi_v;
//
//	Node(int data) {
//		this->data = data;
//		this->par = NULL;
//	}
//	~Node() {}
//
//	void setParent(Node* parent) {
//		this->par = parent;
//	}
//	void insertChild(Node* child) {
//		this->chi_v.push_back(child);
//	}
//	void delChild(Node* child) {
//		for (int i = 0; i < this->chi_v.size(); i++) {
//			if (this->chi_v[i] == child) {
//				this->chi_v.erase(this->chi_v.begin() + i);
//			}
//		}
//	}
//};
//
//class Tree {
//private:
//	Node* root;
//	vector<Node*> node_list;
//
//public:
//	Tree(int root) {
//		this->root = new Node(root);
//		this->node_list.push_back(this->root);
//	}
//	~Tree() {}
//
//	int size() {
//		return this->node_list.size();
//	}
//	void insertNode(int parData, int data) {
//		Node* newNode = new Node(data);
//
//		for (int i = 0; i < this->node_list.size(); i++) {
//			if (this->node_list[i]->data == parData) {
//				newNode->par = this->node_list[i];
//				this->node_list.push_back(newNode);
//				this->node_list[i]->insertChild(newNode);
//			}
//		}
//	}
//	void delNode(int data) {
//		for (int i = 0; i < this->node_list.size(); i++) {
//			if (this->node_list[i]->data == data) {
//				Node* temp = this->node_list[i];
//				if (temp == this->root) {//�����Ұ� �θ�� ���ϰ�
//					return;
//				}
//				for (int f = 0; f < temp->chi_v.size(); f++) {//������ ��� �ڽĵ� ���� �̾��ְ�
//					temp->chi_v[f]->par = temp->par;
//					temp->par->chi_v.push_back(temp->chi_v[f]);
//				}
//				temp->par->delChild(temp);//������ ��� �θ��� �ڽĸ������� �����Ҿ� �����ְ�
//				this->node_list.erase(this->node_list.begin() + i);//������ �� Ʈ�� ��Ʈ����Ʈ���� �����
//				delete temp;//������
//			}
//		}
//	}
//	void printChi(int data) {
//		for (int i = 0; i < this->node_list.size(); i++) {
//			if (this->node_list[i]->data == data) {
//				if (this->node_list[i]->par == NULL || this->node_list[i]->par->chi_v.size() == 1) {
//					cout << node_list[i]->data << endl;
//					return;
//				}
//				for (int f = 0; f < this->node_list[i]->par->chi_v.size(); f++) {
//					cout << this->node_list[i]->par->chi_v[f]->data << " ";
//				}
//				cout << endl;
//				return;
//			}
//		}
//		cout << "0" << endl;
//		return;
//	}
//};
//
//int main() {
//	string order;
//	int num;
//	Tree t = Tree(1);
//	cin >> num;
//	while (num--) {
//		cin >> order;
//		if (order == "insert") {
//			int par, data;
//			cin >> par >> data;
//			t.insertNode(par, data);
//		}
//		else if (order == "delete") {
//			int data;
//			cin >> data;
//			t.delNode(data);
//		}
//		else {
//			int data;
//			cin >> data;
//			t.printChi(data);
//		}
//	}
//}