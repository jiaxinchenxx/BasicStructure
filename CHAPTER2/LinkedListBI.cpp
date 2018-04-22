#include <iostream>
#include <string>
using namespace std;



class BiLinkedNode {

public:

	int data;
	BiLinkedNode *prev;
	BiLinkedNode *next;


};


class BiLinkedList {

public:

	BiLinkedNode *HEAD;
	int curLen;

	BiLinkedList();
	~BiLinkedList();

	bool insert2Tail(int x);
	bool insert2Head(int x);
	void ShowList();
	bool SHUFFLE();
	
};

BiLinkedList::BiLinkedList() {
	this->HEAD = new BiLinkedNode();
	HEAD->next = NULL;
	HEAD->prev = NULL;
	this->curLen = 0;

}

BiLinkedList::~BiLinkedList() {

	BiLinkedNode * p;
	BiLinkedNode * q;

	p = HEAD;

	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
}

bool BiLinkedList::insert2Head(int x) {
	
	BiLinkedNode *tmp = new BiLinkedNode();
	tmp->data = x;

	tmp->next = HEAD->next;
	HEAD->next->prev = tmp;
	HEAD->next = tmp;
	tmp->prev = HEAD;

	curLen++;

	return true;
}

bool BiLinkedList::insert2Tail(int x) {

	BiLinkedNode *tmp = new BiLinkedNode();
	BiLinkedNode *p = HEAD;
	tmp->data = x;

	while (p->next)
		p = p->next;

	p->next = tmp;
	tmp->prev = p;

	curLen++;

	return true;

}


bool BiLinkedList::SHUFFLE() {

	BiLinkedNode *f = HEAD->next;
	BiLinkedNode *r = HEAD;

	while (r->next)
		r = r->next;

	BiLinkedNode *tmp;

	bool isBACK = false;

	while (f != r) {

		if (!isBACK) {
			isBACK = !isBACK;
			f = f->next;
			continue;
		}
		else {
			isBACK = !isBACK;
			tmp = f->prev;
			tmp->next = f->next;
			f->next->prev = tmp;

			if (!r->next) {
				r->next = f;
				f->prev = r;
				f->next = NULL;
				f = tmp->next;
				continue;                  
			}
			r->next->prev = f;
			f->prev = r;
			f->next = r->next;
			r->next = f;

			f = tmp->next;
		}
	}
		
	return true;
}

void BiLinkedList::ShowList() {

	BiLinkedNode *p = HEAD->next;
	
	while (p) {
		cout << p->data << endl;
		p = p->next;
	}
}

/*
void main() {

	BiLinkedList l1;
	for (int i = 1; i <= 10; i++) {
		l1.insert2Tail(i);
	}

	l1.ShowList();
	l1.SHUFFLE();
	l1.ShowList();


	cin.clear();
	cin.sync();
	cin.get();

}

*/


