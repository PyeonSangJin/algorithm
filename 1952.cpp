#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int d, m, tm, y;
int ans;
int val[14];

void dfs(int index, int sum) {
	if (index > 11) {
		if (ans > sum) ans = sum;
		return;
	}

	dfs(index + 1, sum + val[index]);
	dfs(index + 3, sum + tm);
}

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int input;
		val[14] = { 0, };

		cin >> d >> m >> tm >> y;
		for (int i = 0; i < 12; i++) {
			cin >> input;
			val[i] = min(input * d, m);
		}

		ans = y;
		dfs(0, 0);

		cout << "#" << t + 1 << " " << ans << endl;
	}
	return 0;
}

