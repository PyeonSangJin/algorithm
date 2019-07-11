#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int map[305][305];
int N, M, input;

struct ice {
	int x;
	int y;

	ice(int x, int y) :x(x), y(y) {};
};

queue<ice> qu;

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (map[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (map[nx][ny] == 0) {
					map[i][j]--;
					if (map[i][j] <= 0) map[i][j] = -1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == -1) map[i][j] = 0;
}

int bfs() {
	int cnt = 0;
	bool visited[305][305] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			if (visited[i][j]) continue;

			visited[i][j] = true;
			qu.push(ice(i, j));

			while (!qu.empty()) {
				int x = qu.front().x;
				int y = qu.front().y;
				qu.pop();

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (visited[nx][ny]) continue;

					if (map[nx][ny] != 0) {
						visited[nx][ny] = true;
						qu.push(ice(nx, ny));
					}
				}
			}
			cnt++;
		}
	}

	return cnt;
}

int main(int argc, char* argv[]) {

	freopen("test.txt", "r", stdin);

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int ans = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	while (1) {
		int obj = bfs();
		

		if (obj == 0) {
			cout << "0";
			break;
		}
		
		if (obj > 1) {
			cout << ans;
			break;
		}

		melt();
		ans++;
	}

	return 0;

}