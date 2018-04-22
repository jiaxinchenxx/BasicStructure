#include <iostream>
#include <string>

using namespace std;

class LinkedNode {

public:
	int data;
	LinkedNode * next;

	//LinkedNode(int data, LinkedNode * next){
	//	this->data = data;
	//	this->next = next;

	//}
};


class LinkedList {

public:
	LinkedNode * HEAD;
	int curLen;

	LinkedList();
	~LinkedList();

	bool insert2HEAD(int x);
	bool insert2TAIL(int x);
	bool insert(int x, int a);
	bool delNODE(int x);
	bool TURN();
	void ShowList();
	int getMax(LinkedNode * p);
	int getCurLEN(LinkedNode * p);
	float getAVER(LinkedNode * p);
	LinkedNode* merge2(LinkedList * l1, LinkedList * l2);

};


LinkedList::LinkedList() {
	this->HEAD = new LinkedNode();
	HEAD->next = NULL;
	this->curLen = 0;

}

LinkedList::~LinkedList() {

	LinkedNode * p;
	LinkedNode * q;

	p = HEAD;

	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
}

bool LinkedList::insert2HEAD(int x) {

	LinkedNode * tmp = new LinkedNode();
	tmp->data = x;

	tmp->next = HEAD->next;
	HEAD->next = tmp;
	curLen++;

	return true;
}

bool LinkedList::insert2TAIL(int x) {

	LinkedNode * p;

	p = HEAD;

	while (p->next)
		p = p->next;

	p->next = new LinkedNode();
	p->next->data = x;
	p->next->next = NULL;

	curLen++;

	return true;

}

bool LinkedList::insert(int x, int a) {

	bool isFound = false;
	LinkedNode * p = HEAD->next;

	while (p) {
		if (p->data == a) {
			isFound = true;
			break;
		}
		else
			p = p->next;
	}

	if (isFound) {
		LinkedNode * tmp;
		tmp = p->next;
		p->next = new LinkedNode();
		p->next->data = x;
		p->next->next = tmp;
		return true;
	}

	else
		return false;
}

bool LinkedList::delNODE(int x){

	bool isFound = false;
	LinkedNode * p = HEAD;

	while (p->next) {
		if (p->next->data == x) {
			isFound = true;
			break;
		}
		else
			p = p->next;
	}

	if (isFound) {
		p->next = p->next->next;
		return isFound;
	}
	else
		return false;
}

void LinkedList::ShowList() {

	LinkedNode * p = HEAD->next;

	while (p) {
		cout << p->data << endl;
		p = p->next;
	}

}

bool LinkedList::TURN() {

	LinkedNode * a;
	LinkedNode * b;
	LinkedNode * c;

	if (curLen == 1)
		return true;
	if (curLen == 0)
		return false;

	a = HEAD->next;
	b = HEAD->next->next;
	c = HEAD->next->next->next;
	a->next = NULL;

	while (b != NULL) {
		b->next = a;
		a = b;
		b = c;
		if(c)
			c = c->next;

	}

	HEAD->next = a;
	return true;
}


int GETMAX(int a, int b) {
	return a > b ? a : b;
}

int LinkedList::getMax(LinkedNode * p) {
	
	if (p->next)
		return GETMAX(p->data, getMax(p->next));
	else
		return p->data;
}

int LinkedList::getCurLEN(LinkedNode * p) {

	if (p->next)
		return 1 + getCurLEN(p->next);
	else
		return 1;

}

float LinkedList::getAVER(LinkedNode * p) {

	if (p->next)
		return p->data / (float)curLen + getAVER(p->next);
	else
		return p->data / (float)curLen;

}


LinkedNode* LinkedList::merge2(LinkedList * l1, LinkedList * l2) {

	if (l1->curLen == 0) {
		l2->TURN();
		return l2->HEAD;
	}
	if (l2->curLen == 0) {
		l1->TURN();
		return l1->HEAD;
	}

	LinkedNode *n1, *n2, *curNode, *tmp;
	n1 = l1->HEAD->next;
	n2 = l2->HEAD->next;
	if (n1->data < n2->data) {
		curNode = n1;
		n1 = n1->next;
	}
	else {
		curNode = n2;
		n2 = n2->next;
	}

	tmp = new LinkedNode();
	tmp->next = curNode;

	while (n1 && n2) {
		if (n1->data < n2->data) {
			curNode->next =  n1;
			n1 = n1->next;
		}
		else {
			curNode->next = n2;
			n2 = n2->next;
		}
		curNode = curNode->next;
	}

	if (n1 == NULL)
		curNode->next = n2;
	else if (n2 == NULL)
		curNode->next = n1;

	return tmp;


}

/*
void main() {
	LinkedList l1,l2,l3;
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 1)
			l1.insert2TAIL(1);
		else
			l2.insert2TAIL(2);
	}
	l1.ShowList();
	l2.ShowList();
	//l1.TURN();
	//l1.ShowList();

	l3.HEAD = l3.merge2(&l1, &l2);
	l3.ShowList();

	cin.clear();
	cin.sync();
	cin.get();
}


*/