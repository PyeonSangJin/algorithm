#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>

char map[55][55];
bool visited[55][55];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct point {
	int x;
	int y;
	int cnt;

	point(int x, int y, int cnt) :x(x), y(y), cnt(cnt) {};
};

queue<point> water;
queue<point> dochi;
int R, C;
char val;
bool findAns = false;
int cnt;

void waterMov() {
	int wx = water.front().x;
	int wy = water.front().y;
	int wcnt = water.front().cnt;

	water.pop();

	for (int i = 0; i < 4; i++) {
		int wnx = wx + dx[i];
		int wny = wy + dy[i];

		if (wnx < 0 || wny < 0 || wnx >= R || wny >= C) continue;


		if (!visited[wnx][wny] && map[wnx][wny] == '.') {
			visited[wnx][wny] = true;
			water.push(point(wnx, wny, wcnt + 1));
		}
	}
}

void dochiMov() {
	int sx = dochi.front().x;
	int sy = dochi.front().y;
	cnt = dochi.front().cnt;
	dochi.pop();

	for (int i = 0; i < 4; i++) {
		int snx = sx + dx[i];
		int sny = sy + dy[i];

		if (snx < 0 || sny < 0 || snx >= R || sny >= C) continue;

		if (map[snx][sny] == 'D') {
			findAns = true;
			break;
		}

		if (!visited[snx][sny] && map[snx][sny] == '.') {
			visited[snx][sny] = true;
			dochi.push(point(snx, sny, cnt + 1));
		}
	}
}

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	cin >> R >> C;

	for (int i = 0; i < R;i++)
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'S') {
				visited[i][j] = true;
				dochi.push(point(i, j, 1));
			}
			if (map[i][j] == '*') {
				visited[i][j] = true;
				water.push(point(i, j, 1));
			}
		}

	while (!dochi.empty()) {
		if (findAns) break;

		while (!water.empty() && water.front().cnt <= dochi.front().cnt) waterMov();

		dochiMov();
	}

	if (findAns) cout << cnt;
	else cout << "KAKTUS";
}