#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>
#include<algorithm>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N;
int map[105][105];

struct danji {
	int x;
	int y;

	danji(int x, int y) : x(x), y(y) {};
};

int bfs(int val) {
	int cnt = 0;
	queue<danji> qu;
	bool visited[105][105] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] > val && !visited[i][j]) {
				cnt++;

				visited[i][j] = true;
				qu.push(danji(i, j));

				while (!qu.empty()) {
					int x = qu.front().x;
					int y = qu.front().y;
					qu.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (map[nx][ny] > val && !visited[nx][ny]) {
							visited[nx][ny] = true;
							qu.push(danji(nx, ny));
						}
					}
				}
			
			}
		}
	}

	return cnt;
}

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);
	cin >> N;

	int maxi = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= 100; i++) {
		maxi = max(maxi, bfs(i));
	}

	cout << maxi;
}