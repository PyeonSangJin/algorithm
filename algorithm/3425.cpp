#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

#define NULL 0
#define EXCIPTION -1234567890
enum { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD, END };

template <typename T>
class my_stack {

private:

	struct Node {
		T data;
		Node *node;

		Node() {};
		Node(T data) :data(data), node(NULL) {};
	};

	int size;
	Node *t;

public:

	my_stack() {
		size = 0;
		t = NULL;
	}

	bool empty() {
		return size == 0 ? true : false;
	}

	void push(T data) {
		Node *n = new Node(data);

		if (empty())
			t = n;
		else {
			n->node = t;
			t = n;
		}
		size++;
	}

	bool pop() {
		if (size <= 0) {
			return false;
		}

		Node *n = t;
		t = t->node;

		delete n;
		size--;

		return true;
	}

	T top() {
		if (t == NULL) return EXCIPTION;
		return t->data;
	}

	int get_size() {
		return size;
	}
};

int sys[200000];
my_stack<int> s;

string processor(int val) {
	long long t1, t2;

	s.push(val);

	for (int i = 0; i < sizeof(sys); i++) {

		if (sys[i] == END) break;

		switch (sys[i])
		{
		case NUM:
			s.push(sys[i + 1]);
			i++;
			break;

		case POP:
			if (!s.pop()) return "ERROR";
			break;

		case INV:
			t1 = s.top();
			if( t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			s.push(t1 * -1);
			break;

		case DUP:
			t1 = s.top();
			if(t1 == EXCIPTION)return "ERROR";
			s.push(t1);
			break;

		case SWP:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";
			s.push(t1);
			s.push(t2);
			break;

		case ADD:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			if( abs(t1+t2) >1000000000)return "ERROR";
			s.push(t1 + t2);
			break;

		case SUB:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			if (abs(t1 - t2) > 1000000000)return "ERROR";
			s.push(t2 - t1);
			break;

		case MUL:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			if (abs(t1 * t2) > 1000000000)return "ERROR";
			s.push(t1 * t2);
			break;

		case DIV:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			if (t1 == 0)return "ERROR";
			s.push(t2 / t1);
			break;

		case MOD:
			t1 = s.top();
			if (t1 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			t2 = s.top();
			if (t2 == EXCIPTION)return "ERROR";
			if (!s.pop()) return "ERROR";

			if (t1 == 0)return "ERROR";
			s.push(t2 % t1);
			break;
		}
	}

	if (s.get_size() != 1) return "ERROR";
	else return to_string(s.top());

}

int main() {
	freopen("text.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	int N, num;
	bool broken = false;

	while (str != "QUIT") {
		int cnt = 0;
		str = "";
		while (str != "END") {
			cin >> str;

			if (str == "NUM") {
				sys[cnt++] = NUM;
				cin >> sys[cnt++];
			}
			else if (str == "POP") sys[cnt++] = POP;
			else if (str == "INV") sys[cnt++] = INV;
			else if (str == "DUP") sys[cnt++] = DUP;
			else if (str == "SWP") sys[cnt++] = SWP;
			else if (str == "ADD") sys[cnt++] = ADD;
			else if (str == "SUB") sys[cnt++] = SUB;
			else if (str == "MUL") sys[cnt++] = MUL;
			else if (str == "DIV") sys[cnt++] = DIV;
			else if (str == "MOD") sys[cnt++] = MOD;
			else if (str == "END") sys[cnt++] = END;
			else if (str == "QUIT") {
				broken = true;
				break;
			}
		}
		if (broken) break;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> num;
			cout << processor(num) << "\n";
			while (!s.empty())s.pop();
		}

		if (broken) break;
		cout << "\n";
	}
}