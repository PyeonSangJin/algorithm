#include "pch.h"
#include <iostream>
#include <queue>
#include<tuple>
using namespace std;
#pragma warning(disable:4996)

char map[15][15];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int N, M;
queue<tuple<int, int, int, int, int>> qu;
bool visited[11][11][11][11];
int rx, ry, bx, by;

tuple<int, int> mov(int x, int y, int dirx, int diry);

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') rx = i, ry = j, map[i][j] = '.';
			if (map[i][j] == 'B') bx = i, by = j, map[i][j] = '.';
		}

	visited[rx][ry][bx][by] = true;
	qu.push(make_tuple(rx, ry, bx, by, 1));

	while (!qu.empty()) {
		int cnt;
		tie(rx, ry, bx, by, cnt) = qu.front(); qu.pop();
		for (int i = 0; i < 4; i++) {
			int nrx, nry, nbx, nby;
			tie(nrx, nry) = mov(rx, ry, dx[i], dy[i]);
			tie(nbx, nby) = mov(bx, by, dx[i], dy[i]);

			if (nbx == -1 && nby == -1) continue;//µÎ°³, ÆÄ¶û È¦ ºüÁü
				
			if (nrx == -1 && nry == -1) {// »¡°£¸¸ È¦ ºüÁü
				cout << cnt;
				return 0;
			}

			if (nrx == nbx && nry == nby) { //°ãÄ¡¸é
				if (i == 0) { if (rx < bx)nbx++; else nrx++; }
				else if (i == 1) { if (rx < bx)nrx--; else nbx--; }
				else if (i == 2) { if (ry < by)nby++; else nry++; }
				else if (i == 3) { if (ry < by)nry--; else nby--; }
			}

			if (!visited[nrx][nry][nbx][nby]) {
				visited[nrx][nry][nbx][nby] = true;
				qu.push(make_tuple(nrx, nry, nbx, nby, cnt + 1));
			}
		}

		if (cnt > 10) {
			cout << "-1";
			return 0;
		}
	}
	cout << "-1";
	return 0;
}

tuple<int, int> mov(int x, int y, int dirx, int diry) {
	if (map[x][y] == '#') return make_tuple(x - dirx, y - diry);
	if (map[x][y] == 'O') return make_tuple(-1, -1); //hole in
	return mov(x + dirx, y + diry, dirx, diry);
}