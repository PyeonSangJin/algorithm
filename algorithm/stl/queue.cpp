#define NULL 0

template<typename T>
class my_queue {

private:

	struct Node {
		T data;
		Node* node;

		Node() {};
		Node(T data) :data(data), node(NULL) {};
	};

	int size;
	Node *head, *tail;

public:

	my_queue() {
		head = tail = NULL;
		size = 0;
	}

	bool empty() {
		return size == 0 ? true : false;
	}

	void push(T d) {
		Node *n = new Node(d);

		if (empty()) {
			head = tail = n;
		}
		else {
			tail->node = n;
			tail = n;
		}
		size++;
	}

	void pop() {
		Node *n = head;
		head = head->node;

		delete n;
		size--;
	}

	T front() {
		return head->data;
	}
};