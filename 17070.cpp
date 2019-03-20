#include "pch.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int map[100][100];
int ans;
int N;

//status 0 = 세로, 1 = 대각선, 2 = 가로 
void dfs(int x, int y, int status) {
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;

	if (map[x][y] == 1)
		return;

	if (status == 1) {
		if (map[x - 1][y] != 0 || map[x][y - 1] != 0)
			return;
	}

	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}

	if (status == 2) {
		dfs(x, y + 1, 2);
		dfs(x + 1, y + 1, 1);
	}
	if (status == 1) {
		dfs(x + 1, y, 0);
		dfs(x + 1, y + 1, 1);
		dfs(x, y + 1, 2);
	}
	if (status == 0) {
		dfs(x + 1, y + 1, 1);
		dfs(x + 1, y, 0);
	}
}

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	ans = 0;


	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	dfs(0, 1, 2);

	cout << ans;

	return 0;
}