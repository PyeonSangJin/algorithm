#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>
#include<algorithm>

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, -2, 2, 2, -2, 1, -1 };

int N;


struct chess {
	int x;
	int y;
	int cnt;

	chess(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {};
};



int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 0; t < T;t++) {

		cin >> N;

		int map[305][305] = { 0, };
		bool visited[305][305] = { 0, };
		int tx, ty, gx, gy;
		int ans = 0;
		bool findAns = false;

		cin >> tx >> ty >> gx >> gy;
		map[gx][gy] = 1;

		queue<chess> qu;

		qu.push(chess(tx, ty, 0));
		visited[tx][ty] = true;

		while (!qu.empty()) {
			if (tx == gx && ty == gy) {
				ans = 0;
				break;
			}

			int x = qu.front().x;
			int y = qu.front().y;
			int cnt = qu.front().cnt;
			qu.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (map[nx][ny] == 1) {
					ans = cnt + 1;
					findAns = true;
					break;
				}

				if (!visited[nx][ny] && !findAns) {
					visited[nx][ny] = true;
					qu.push(chess(nx, ny, cnt + 1));
				}
			}
			if (findAns) break;
		}

		cout << ans<<endl;
	}
}