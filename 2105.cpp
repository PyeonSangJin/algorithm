#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

int ans;
int N;
int map[30][30];
bool visited[110];
int ox, oy;

void dfs(int x, int y, int cnt, int way) {
	if (x >= N || y >= N || x < 0 || y < 0) return;
	if (ox == x && oy == y && way == 3) {
		if (ans < cnt) ans = cnt;
		return;
	}
	if (visited[map[x][y]]) return;

	visited[map[x][y]] = true;

	if (way == 0) {
		dfs( x + 1, y + 1, cnt + 1, way);
		dfs( x + 1, y - 1, cnt + 1, way + 1);
	}

	else if (way == 1) {
		dfs( x + 1, y - 1, cnt + 1, way);
		dfs( x - 1, y - 1, cnt + 1, way + 1);
	}

	else if (way == 2) {
		dfs( x - 1, y - 1, cnt + 1, way);
		dfs( x - 1, y + 1, cnt + 1, way + 1);
	}
	else if (way == 3) 
		dfs( x - 1, y + 1, cnt + 1, way);

	visited[map[x][y]] = false;
}


int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = -1;

		cin >> N;

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N - 2; i++)
			for (int j = 1; j < N - 1; j++) {
				ox = i;
				oy = j;
				dfs(i, j, 0, 0);
			}

		cout << "#" << t + 1 << " " << ans << endl;
	}
	return 0;
}