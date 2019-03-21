#include "pch.h"
#include <iostream>
#include<vector>
#include<tuple>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int ans;
int N;
int map[20][20];
vector<tuple<int, int >> core;
int connect;
vector<int> corelen;

//way 0µ¿ 1¼­ 2³² 3ºÏ
bool isdraw(int x, int y, int way) {
	if (way == 0) {
		for (int i = y + 1; i < N; i++)
			if (map[x][i] != 0)
				return false;
	}

	else if (way == 1) {
		for (int i = y - 1; i >= 0; i--)
			if (map[x][i] != 0)
				return false;
	}

	else if (way == 2) {
		for (int i = x + 1; i < N; i++)
			if (map[i][y] != 0)
				return false;
	}

	else if (way == 3) {
		for (int i = x - 1; i >= 0; i--)
			if (map[i][y] != 0)
				return false;
	}
	return true;
}


//way 0µ¿ 1¼­ 2³² 3ºÏ
int draw(int x, int y, int way, int flag) {
	int cnt = 0;

	if (way == 0) {
		for (int i = y + 1; i < N; i++) {
			map[x][i] = flag;
			cnt++;
		}
	}

	else if (way == 1) {
		for (int i = y - 1; i >= 0; i--) {
			map[x][i] = flag;
			cnt++;
		}
	}

	else if (way == 2) {
		for (int i = x + 1; i < N; i++) {
			map[i][y] = flag;
			cnt++;
		}
	}

	else if (way == 3) {
		for (int i = x - 1; i >= 0; i--) {
			map[i][y] = flag;
			cnt++;
		}
	}

	return cnt;
}

void dfs(int index, int link, int vertec) {
	if (index == core.size()) {
		if (connect < vertec) {
			connect = vertec;
			ans = link;
		}
		else if (connect == vertec) {
			ans = min(ans, link);
		}

		return;
	}

	int x, y;
	tie(x, y) = core[index];

	for (int i = 0; i < 4; i++) {
		if (isdraw(x, y, i)) {
			dfs(index + 1, link + draw(x, y, i, 2), vertec + 1);
			draw(x, y, i, 0);
		}
	}
	dfs(index + 1, link, vertec);
}



int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = 99999999;
		core.clear();
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					if (i != 0 && j != 0 && i != N - 1 && j != N - 1)
						core.push_back(make_tuple(i, j));

			}

		connect = 0;

		dfs(0, 0, 0);

		for (int i = 0; i < corelen.size(); i++){
			ans = min(ans, corelen[i]);
		}

		if (ans == 99999999)
			ans = 0;

		cout << "#" << t + 1 << " " << ans << endl;
	}
	return 0;
}