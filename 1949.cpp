#include "pch.h"
#include <iostream>
#include <tuple>
#include<queue>
#include <algorithm>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, K;
int map[9][9];
bool visited[10][10][2];
int ans;

void dfs(int x, int y, int val, bool broken, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (!visited[nx][ny][broken]) { //방문 X

			if (map[nx][ny] < val) { //산이 낮을때
				visited[nx][ny][broken] = true;
				dfs(nx, ny, map[nx][ny], broken, cnt + 1);
				visited[nx][ny][broken] = false;
			}
			else if (!broken)  // 산이 더 높고 안 부쉈을때
				for (int k = 1; k <= K; k++)
					if (map[nx][ny] - k < val) {
						visited[nx][ny][true] = true;
						dfs(nx, ny, map[nx][ny] - k, true, cnt + 1);
						visited[nx][ny][true] = false;
						break;
					}
		}

	}
	ans = max(ans, cnt);
}

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		queue<tuple<int, int>> high;
		int tmphigh = 0;
		ans = 0;
		memset(map, 0, sizeof(map));
		
		cin >> N >> K;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				tmphigh = max(tmphigh, map[i][j]);
			}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j] == tmphigh)
					high.push(make_tuple(i, j));

		while (!high.empty()) {
			int highX, highY;
			tie(highX, highY) = high.front(); high.pop();

			memset(visited, 0, sizeof(visited));
			visited[highX][highY][0] = true;

			dfs(highX, highY, map[highX][highY], false, 1);
		}
		cout << "#" << t + 1 << " ";
		cout << ans << endl;
	}

	return 0;
}

