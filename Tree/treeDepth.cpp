#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
	~Node() {}

	void setParent(Node* parent) {
		this->par = parent;
	}
	void insertChild(Node* child) {
		this->chi_v.push_back(child);
	}
	void delChild(Node* child) {
		for (int i = 0; i < this->chi_v.size(); i++) {
			if (this->chi_v[i] == child) {
				this->chi_v.erase(this->chi_v.begin() + i);
			}
		}
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> node_list;
	int depth;
	vector<int> childV;

public:
	Tree(int root) {
		this->depth = 0;
		this->root = new Node(root);
		this->node_list.push_back(this->root);
	}
	~Tree() {}

	int size() {
		return this->node_list.size();
	}
	void insertNode(int parData, int data) {
		Node* newNode = new Node(data);

		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == parData) {
				newNode->par = this->node_list[i];
				this->node_list.push_back(newNode);
				this->node_list[i]->insertChild(newNode);
			}
		}
	}
	void delNode(int data) {
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == data) {
				Node* temp = this->node_list[i];
				if (temp == this->root) {//삭제할게 부모면 안하고
					return;
				}
				for (int f = 0; f < temp->chi_v.size(); f++) {//삭제할 노드 자식들 새로 이어주고
					temp->chi_v[f]->par = temp->par;
					temp->par->chi_v.push_back(temp->chi_v[f]);
				}
				temp->par->delChild(temp);//삭제할 노드 부모의 자식모음에서 삭제할애 지워주고
				this->node_list.erase(this->node_list.begin() + i);//삭제할 애 트리 노트리스트에서 지우고
				delete temp;//노드삭제
			}
		}
	}
	void printChi(int data) {
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == data) {
				if (this->node_list[i]->chi_v.size() == 0) {
					cout << "0" << endl;
					return;
				}
				for (int f = 0; f < this->node_list[i]->chi_v.size(); f++) {
					cout << this->node_list[i]->chi_v[f]->data << " ";
				}
				cout << endl;
				return;
			}
		}
		cout << "0" << endl;
		return;
	}
	void getDepth(int data) {
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == data) {
				if (this->node_list[i]->par == NULL) {
					cout << this->depth << endl;
					this->depth = 0;
					return;
				}
				this->depth++;
				this->getDepth(this->node_list[i]->par->data);
				return;
			}
		}
	}
	void getMax(int depth) {
		if (depth == 0) {
			cout << this->root->data << endl;
			return;
		}
		this->depth = depth - 1;
		getNode(this->root->chi_v);
		if (this->childV.size() == 0) {
			cout << "0" << endl;
			return;
		}
		for (int i = 0; i < this->childV.size() - 1; i++) {
			if (childV[i] > childV[i + 1]) childV[i + 1] = childV[i];
		}
		cout << childV.back() << endl;
		vector<int> reset;
		this->childV = reset;
		return;
	}
	void getNode(vector<Node*>chi) {
		if (chi.size() == 0) {
			return;
		}
		if (this->depth == 0) {
			for (int i = 0; i < chi.size(); i++) {
				childV.push_back(chi[i]->data);
			}
			return;
		}
		for (int i = 0; i < chi.size(); i++) {
			this->depth--;
			getNode(chi[i]->chi_v);
			this->depth++;
		}
		return;
	}
};

int main() {
	int treeNum, DepthQuestion;
	Tree t = Tree(1);
	cin >> treeNum >> DepthQuestion;
	while (treeNum--) {
		int par, data;
		cin >> par >> data;
		t.insertNode(par, data);
	}
	while (DepthQuestion--) {
		int data;
		cin >> data;
		t.getMax(data);
	}
}