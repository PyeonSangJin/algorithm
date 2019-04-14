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
		Node *n = t;
		t = t->node;

		delete n;
		size--;

		return true;
	}

	T top() {
		return t->data;
	}

	int get_size() {
		return size;
	}
};