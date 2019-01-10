#include "pch.h"
#include <iostream>
#include <string.h>
#include<queue>
#include<tuple>
using namespace std;
#pragma warning(disable:4996)

int ans;
int N, M, R, C, L;
int map[55][55];
int visited[55][55];

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = 0;
		queue<tuple<int, int, int>> qu;

		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];

		memset(visited, 0, sizeof(visited));

		visited[R][C] = true;
		qu.push(make_tuple(R, C, 1));

		while (!qu.empty()) {
			int x, y, time;
			tie(x, y, time) = qu.front(); qu.pop();

			if (x < 0 || x >= N || y < 0 || y >= M) continue;
			if (time >= L) break;

			if (map[x][y] == 1) {
				if (!visited[x - 1][y] && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) { visited[x - 1][y] = true; qu.push(make_tuple(x - 1, y, time + 1)); }
				if (!visited[x + 1][y] && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) { visited[x + 1][y] = true; qu.push(make_tuple(x + 1, y, time + 1)); }
				if (!visited[x][y - 1] && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) { visited[x][y - 1] = true; qu.push(make_tuple(x, y - 1, time + 1)); }
				if (!visited[x][y + 1] && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) { visited[x][y + 1] = true; qu.push(make_tuple(x, y + 1, time + 1)); }
			}
			else if (map[x][y] == 2) {
				if (!visited[x - 1][y] && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) { visited[x - 1][y] = true; qu.push(make_tuple(x - 1, y, time + 1)); }
				if (!visited[x + 1][y] && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) { visited[x + 1][y] = true; qu.push(make_tuple(x + 1, y, time + 1)); }
			}
			else if (map[x][y] == 3) {
				if (!visited[x][y - 1] && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) { visited[x][y - 1] = true; qu.push(make_tuple(x, y - 1, time + 1)); }
				if (!visited[x][y + 1] && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) { visited[x][y + 1] = true; qu.push(make_tuple(x, y + 1, time + 1)); }
			}
			else if (map[x][y] == 4) {
				if (!visited[x - 1][y] && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) { visited[x - 1][y] = true; qu.push(make_tuple(x - 1, y, time + 1)); }
				if (!visited[x][y + 1] && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) { visited[x][y + 1] = true; qu.push(make_tuple(x, y + 1, time + 1)); }
			}
			else if (map[x][y] == 5) {
				if (!visited[x + 1][y] && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) { visited[x + 1][y] = true; qu.push(make_tuple(x + 1, y, time + 1)); }
				if (!visited[x][y + 1] && (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7)) { visited[x][y + 1] = true; qu.push(make_tuple(x, y + 1, time + 1)); }
			}
			else if (map[x][y] == 6) {
				if (!visited[x + 1][y] && (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7)) { visited[x + 1][y] = true; qu.push(make_tuple(x + 1, y, time + 1)); }
				if (!visited[x][y - 1] && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) { visited[x][y - 1] = true; qu.push(make_tuple(x, y - 1, time + 1)); }
			}
			else if (map[x][y] == 7) {
				if (!visited[x - 1][y] && (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6)) { visited[x - 1][y] = true; qu.push(make_tuple(x - 1, y, time + 1)); }
				if (!visited[x][y - 1] && (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5)) { visited[x][y - 1] = true; qu.push(make_tuple(x, y - 1, time + 1)); }
			}

		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (visited[i][j] == true)
					ans++;


		cout << "#" << t + 1 << " " << ans << endl;
	}
	return 0;
}