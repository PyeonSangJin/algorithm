#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<queue>

int dx[] = { 0,0,-1,1};
int dy[] = { -1,1,0,0};

int map[1005][1005];
bool visited[1005][1005];

struct tomato {
	int x;
	int y;
	int cnt;

	tomato(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {};
};


int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);
	int N, M;
	int cnt = 0;
	queue<tomato> qu;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				qu.push(tomato(i, j, 0));
				visited[i][j] = true;
			}
		}

	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		cnt = qu.front().cnt;
		qu.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (map[nx][ny] == 0 && map[x][y] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				map[nx][ny] = 1;
				qu.push(tomato(nx, ny, cnt+1));
			}
		}
	}



	for (int i = 0; i < M; i++)
		for (int j = 0; j < N;j++) {
			if (map[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}

	cout << cnt;
	return 0;
}