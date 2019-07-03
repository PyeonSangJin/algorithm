#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<queue>
#include<algorithm>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char map[30][30];
bool visited[30][30];

struct danji {
	int x;
	int y;
	int  cnt;

	danji(int x, int y, int cnt):x(x), y(y), cnt(cnt) {};
};

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int anscnt = 0;
	int ans[1000] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == '1' && !visited[i][j]) {
				queue<danji> qu;

				visited[i][j] = true;
				qu.push(danji(i, j, 1));

				anscnt++;
				ans[anscnt] = 1;

				while (!qu.empty()) {
					int x = qu.front().x;
					int y = qu.front().y;
					int cnt = qu.front().cnt;

					qu.pop();


					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (!visited[nx][ny] && map[x][y] == map[nx][ny]) {
							visited[nx][ny] = true;
							ans[anscnt]++;
							qu.push(danji(nx, ny, cnt + 1));
						}
					}
				}
			}

		}
	}

	cout << anscnt << endl;

	sort(ans + 1, ans + anscnt + 1);

	for (int i = 1; i <= anscnt;i++) {
		cout << ans[i] << endl;
	}

	return 0;
}