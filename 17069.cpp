#include "pch.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

long long dp[40][40][3];
int map[40][40];
int N;

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	dp[0][1][0] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i < 0 || j < 0 || i >= N || j >= N)
				continue;

			if (map[i][j] != 0)
				continue;

			dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
			dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];

			if (map[i][j + 1] != 1 && map[i + 1][j] != 1)
				dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
		}

	long long ans = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	cout << ans;
	return 0;
}