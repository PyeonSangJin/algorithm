#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char arr[55][55] = { 0, };
int visited[55][55][70] = { 0, };

struct point {
	int x;
	int y;
	int cnt;
	string keys;

	point(int x, int y, int cnt, string keys) :x(x), y(y), cnt(cnt), keys(keys) {};
};

queue<point> qu;

int kindKey(string keys) {
	int sum = 0;
	for (int i = 0; i < keys.length(); i++) {
		if (keys[i] == '1') {
			int cnt = 1;

			for (int j = i; j < keys.length() - 1; j++)
				cnt *= 2;

			sum += cnt;
		}
	}

	return sum;
}

int main(int argv, char* argc[]) {

	freopen("test.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				arr[i][j] = '.';
				visited[i][j][0] = 1;
				qu.push(point(i, j, 0, "000000"));
			}
		}
	}


	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int cnt = qu.front().cnt;
		string keys = qu.front().keys;

		int kindKi = kindKey(keys);

		qu.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny][kindKi]) continue;

			if (arr[nx][ny] == '1') {
				cout << cnt + 1;
				return 0;
			}

			if (arr[nx][ny] == 'a' || arr[nx][ny] == 'b' || arr[nx][ny] == 'c' || arr[nx][ny] == 'd' || arr[nx][ny] == 'e' || arr[nx][ny] == 'f') {
				string temp = keys;
				temp[arr[nx][ny] - 'a'] = '1';
				visited[nx][ny][kindKi] = true;

				qu.push(point(nx, ny, cnt + 1, temp));
			}

			else if (arr[nx][ny] == 'A' || arr[nx][ny] == 'B' || arr[nx][ny] == 'C' || arr[nx][ny] == 'D' || arr[nx][ny] == 'E' || arr[nx][ny] == 'F') {
				if (keys[arr[nx][ny] - 'A'] == '1') {
					visited[nx][ny][kindKi] = true;
					qu.push(point(nx, ny, cnt + 1, keys));
				}
			}

			else if (arr[nx][ny] == '.') {
				visited[nx][ny][kindKi] = true;
				qu.push(point(nx, ny, cnt + 1, keys));
			}

		}
	}
	cout << "-1";

	return 0;
}