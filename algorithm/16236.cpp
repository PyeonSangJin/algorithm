#include<bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)

#define NULL 0

template<typename T>
class my_queue {

private:
	struct Node {
		T data;
		Node *node;

		Node() {};
		Node(T data) :data(data), node(NULL) {};
	};

	int size;
	Node *head, *rear;

public:
	my_queue() {
		size = 0;
		head = rear = NULL;
	}

	bool empty() {
		return size == 0;
	}

	void push(T data) {
		Node *n = new Node(data);

		if (empty()) {
			head = rear = n;
		}
		else {
			rear->node = n;
			rear = n;
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

struct my_tuple {
	int x;
	int y;
	int cnt;
	int size;

	my_tuple() {};
	my_tuple(int x, int y, int cnt, int size) :x(x), y(y), cnt(cnt), size(size) {}
};

struct my_pair {
	int x;
	int y;

	my_pair() {};
	my_pair(int x, int y) :x(x), y(y) {}
};

int N;
int my_map[20][20];
int shark_grow = 0;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

my_tuple shark;

void choose(my_queue<my_pair> &qu) {
	int minX = 987654321, minY = 987654321;
	while (!qu.empty()) {
		int x, y;
		my_pair temp;

		temp = qu.front(); qu.pop();
		x = temp.x; y = temp.y;

		if (minX > x) {
			minX = x;
			minY = y;
		}

		if (minX == x) {
			if (minY > y) {
				minX = x;
				minY = y;
			}
		}
		else continue;
	}

	if (minX != 987654321) {

		shark_grow++;

		if (shark_grow == shark.size) {
			shark_grow = 0;
			shark.size++;
		}

		shark.x = minX;
		shark.y = minY;
		my_map[minX][minY] = 0;
	}
}

bool shark_mov() {
	my_queue<my_tuple> qu;
	my_queue<my_pair> doub;
	bool visited[20][20] = { 0, };

	visited[shark.x][shark.y] = true;
	qu.push(shark);

	int min_pos = 987654321;
	bool isin = false;
	bool firstin = false;

	while (!qu.empty()) {
		int x, y, cnt, size;
		my_tuple temp;

		temp = qu.front(); qu.pop();
		x = temp.x; y = temp.y; cnt = temp.cnt; size = temp.size;

		if (0 < my_map[x][y] && my_map[x][y] < shark.size) {
			if (!firstin) {
				firstin = true;
				isin = true;
				min_pos = cnt;
			}

			if (min_pos == cnt) {
				doub.push(my_pair(x, y));
				shark.cnt = cnt;
			}
		}

		if (isin && cnt != min_pos)	break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (!visited[nx][ny] && my_map[nx][ny] <= size) {
				visited[nx][ny] = true;
				qu.push(my_tuple(nx, ny, cnt + 1, size));
			}
		}
	}

	if (isin) {
		choose(doub);
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	freopen("text.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> my_map[i][j];
			if (my_map[i][j] == 9) {
				my_map[i][j] = 0;
				shark.x = i;
				shark.y = j;
			}
		}

	shark.cnt = 0;
	shark.size = 2;

	while (1) {
		if (!shark_mov()) break;
	}

	cout << shark.cnt;
}