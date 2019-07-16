#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>
#include<algorithm>

#define MAX 210000000

int N;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int map[105][105];
bool startmap[105][105];

struct island {
	int x;
	int y;
	int obj;

	island(int x, int y, int obj) :x(x), y(y), obj(obj) {};
};

queue<island> start;

void findStart() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (startmap[i][j]) continue;
			if (map[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				if (map[nx][ny] == 0 && !startmap[nx][ny]) {
					startmap[nx][ny] = true;
					start.push(island(nx, ny, map[i][j]));
				}
			}
		}
}


int bfs(int startPin, int x, int y) {
	int len = MAX;
	bool visited[105][105] = { 0, };

	queue<island> qu;
	visited[x][y] = true;
	qu.push(island(x, y, 1));

	while (!qu.empty()) {
		int rx = qu.front().x;
		int ry = qu.front().y;
		int cnt = qu.front().obj;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = rx + dx[i];
			int ny = ry + dy[i];

			if (visited[nx][ny] || map[nx][ny] == startPin) continue;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (map[nx][ny] != 0 && map[nx][ny] != startPin) return cnt;


			

			if (map[nx][ny] == 0) {
				visited[nx][ny] = true;
				qu.push(island(nx, ny, cnt + 1));
			}
		}
	}
	return MAX;
}


int main(int argc, char* argv[]) {
	
	queue<island> qu;
	freopen("test.txt", "r", stdin);


	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	bool visited[105][105] = { 0, };

	int objCnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) continue;
			if (visited[i][j]) continue;

			map[i][j] = objCnt;
			visited[i][j] = true;
			qu.push(island(i, j, 0));

			while (!qu.empty()) {
				int x = qu.front().x;
				int y = qu.front().y;
				qu.pop();

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visited[nx][ny]) continue;

					if (map[nx][ny] == 1) {
						map[nx][ny] = objCnt;
						visited[nx][ny] = true;
						qu.push(island(nx, ny, 0));
					}
				}
			}
			objCnt++;
		}
	}

	findStart();

	int ans = MAX;
	while (!start.empty()) {
		ans = min(ans, bfs(start.front().obj, start.front().x, start.front().y));
		start.pop();
	}

	cout << ans;
	return 0;

}