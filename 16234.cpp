#include"pch.h"
#include <iostream>
#include<string.h>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[51][51];
bool visitedDFS[51][51];

int cnt;
int sum;
bool ismov = true;
vector<pair<int, int>> point;

int N, L, R;

void dfs(int x, int y);
void mov();

int main() {
	freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int ans = 0;

	while (ismov) {
		ismov = false;
		memset(visitedDFS, 0, sizeof(visitedDFS));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!visitedDFS[i][j]) {
					point.push_back(make_pair(i, j));
					visitedDFS[i][j] = true;
					cnt = 1;
					sum = map[i][j];
					dfs(i, j);
					mov();
				}

		if (ismov)
			ans++;
	}

	cout << ans;
	return 0;
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (L <= abs(map[x][y] - map[nx][ny]) && abs(map[x][y] - map[nx][ny]) <= R && !visitedDFS[nx][ny]) {
			point.push_back(make_pair(nx, ny));
			visitedDFS[nx][ny] = true;
			cnt++;
			sum += map[nx][ny];
			dfs(nx, ny);
		}
	}
}

void mov() {
	if (point.size() > 1) {
		ismov = true;
		while (!point.empty()) {
			map[point.front().first][point.front().second] = sum / cnt;
			point.erase(point.begin());
		}
	}
	point.clear();
}