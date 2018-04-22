#include <iostream>
#include <string>

using namespace std;

class ArrStack{

public:

	int maxSize;
	int top;

	int *st;


	ArrStack(int maxSize) {
		this->maxSize = maxSize;
		st = new int[this->maxSize];

		top = -1;

	}

	~ArrStack() {
		delete [] st;

	}

	void clear(){
		this->top = -1;
	}

	bool push(const int x) {
		if (top == this->maxSize - 1) {
			cout << "Full Stack!"<<endl;
			return false;
		}

		st[++top] = x;
		return true;
	}

	bool pop(int & item) {
		if (top == -1) {
			cout << "EMPTY Stack!" << endl;
			return false;
		}
		item = st[top--];
		return true;
	}

	int Top(int & item) {
		if (top == -1) {
			cout << "EMPTY Stack" << endl;
			return false;
		}

		item = st[top];
		return true;

	}

	bool isEmpty() {
		if (top == -1)
			return false;
		else
			return true;
	}
};


class ArrQueue {

public:

	int maxSize;
	int front;
	int rear;

	int *q;

	ArrQueue(int maxSize) {

		this->maxSize = maxSize + 1;
		q = new int[this->maxSize];

		front = 0;
		rear = 0;
	}

	~ArrQueue() {
		delete[] q;

	}

	void clear() {
		front = rear;
	}

	bool EnQueue(int x) {

		if ((rear + 1) % maxSize == front) {
			cout << "FULL Queue!" << endl;
			return false;
		}

		q[rear] = x;
		rear = (rear + 1) % this->maxSize;
		return true;
	}

	bool DeQueue(int & item) {

		if (rear == front) {
			cout << "EMPTY Queue!" << endl;
			return false;
		}

		item = q[front];
		front = (front + 1) % this->maxSize;
		return true;

	}

	bool GetFront(int & item) {
		
		if (rear == front) {
			cout << "EMPTY Queue!" << endl;
			return false;
		}

		item = q[front];
		return true;
	}
};


string transform(int origin, int hex) {

	ArrStack *as = new ArrStack(36);

	int res = origin;
	while (res >= hex) {
		as->push(res % hex);
		res = res / hex;
	}
	as->push(res);

	string t;
	int tmp;
	while (as->isEmpty()) {
		as->pop(tmp);
		t = t + std::to_string(tmp);
	}
	return t;
	
}

int strcmp(char *s1, char *s2) {

	int count = 0;

	while (s1[count] != '\0' && s2[count] != '\0') {
		if (s1[count] > s2[count])
			return 1;
		else if (s1[count] < s2[count])
			return -1;

		count++;
	}

	if (s1[count] == '\0' && s2[count] != '\0')
		return -1;
	else if (s1[count] != '\0' && s2[count] == '\0')
		return 1;
	return 0;
}


int * NEXT(string p) {

	int m = p.length();
	if (m <= 0)
		return NULL;

	int * N = new int[m];

	N[0] = 0;

	for (int i = 1; i < m; i++) {

		int k = N[i - 1];

		while (k > 0 && p[i] != p[k])
			k = N[k - 1];

		if (p[i] == p[k])
			N[i] = k + 1;

		else
			N[i] = 0;
	}
	
	return N;
}


int KMPStringMatching(string T, string P, int * N, int startIndex) {

	int lastIndex = T.length() - P.length();

	if (lastIndex < startIndex)
		return -1;

	int i; // for T
	int j = 0; // for P

	for (i = startIndex; i < T.length(); i++) {

		while (P[j] != T[i] && j > 0)
			j = N[j - 1];

		if (P[j] == T[i])
			j++;

		if (j == P.length())
			return i - j + 1;

	}

	return -1;

}

int FindLastSub(char * t, char * p) {


	int plen = 0, tlen = 0;
	string T, P;


	while (t[tlen] != '\0')
		tlen++;
	for (int i = tlen - 1; i >= 0; i--)
		T = T + t[i];

	while (p[plen] != '\0')
		plen++;
	for (int i = plen - 1; i >= 0; i--)
		P = P + p[i];

	if (tlen < plen)
		return -1;

	int res = KMPStringMatching(T, P, NEXT(P), 0);
	if (res == -1)
		return -1;

	res = tlen - res - plen;

	return res;

}


void main() {

	//cout << transform(8,2) << endl;

	//string T = "amcdfgmcdfgmcde";
	//string P = "cdfgmcde";

	//int * N = NEXT(P);

	//cout << KMPStringMatching(T, P, N, 0) << endl;

	char * t = "gmsgms";
	char * p = "gms";

	cout << FindLastSub(t, p) << endl;


	cin.clear();
	cin.sync();
	cin.get();

}