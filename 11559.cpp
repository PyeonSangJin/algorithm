#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<queue>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char map[13][6];

struct puyo {
	int x;
	int y;
	puyo(int x, int y) :x(x), y(y) {};
};

queue<puyo> qu;

void move() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				int k = i;
				while (map[k + 1][j] == '.') { 
					char temp = map[k][j];
					map[k][j] = map[k + 1][j];
					map[k + 1][j] = temp;
					k++;
				}
			}
		}
	}
}

bool bomb() {
	queue<puyo> temp;
	bool isin = false;
	bool visited[12][6] = { 0, };

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == '.' || visited[i][j]) continue;

			qu.push(puyo(i, j));
			temp.push(puyo(i, j));

			visited[i][j] = true;
			bool isbomb = false;

			int cnt = 1;
			while (!qu.empty()) {
				int x = qu.front().x;
				int y = qu.front().y;

				if (cnt >= 4) {
					isbomb = true;
				}

				qu.pop();

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;

					if (map[x][y] == map[nx][ny] && !visited[nx][ny]) {
						visited[nx][ny] = true;
						cnt++;
						qu.push(puyo(nx, ny));
						temp.push(puyo(nx, ny));

					}
				}
			}

			if (isbomb) {
				isin = true;
				while (!temp.empty()) {
					int x = temp.front().x;
					int y = temp.front().y;
					temp.pop();
					map[x][y] = '.';
				}
			}
			else {
				while (!temp.empty()) 
					temp.pop();
			}
		}
	}

	return isin;
}

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	int ans = 0;

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];

	while (bomb()) {
		move();
		ans++;
	}

	cout << ans;

	return 0;
}