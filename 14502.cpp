#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<queue>

int ori_map[10][10];
int map[10][10];
int ori_visited[10][10];
int visited[10][10];


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int N, M;
int maxi = 0;

struct virus {
	int x;
	int y;

	virus(int x, int y) :x(x), y(y) {};
};

void make_map(int x, int y, int x2, int y2, int x3, int y3) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			map[i][j] = ori_map[i][j];
			visited[i][j] = ori_visited[i][j];
		}

	map[x][y] = 1;
	map[x2][y2] = 1;
	map[x3][y3] = 1;
}

void getMax() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (map[i][j] == 0) cnt++;

	if (cnt > maxi) {
		int a = 1;
	}
	maxi = max(maxi, cnt);
}

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	queue<virus> ori_qu;
	queue<virus> qu;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> ori_map[i][j];

			if (ori_map[i][j] == 2) {
				ori_qu.push(virus(i, j));
				ori_visited[i][j] = true;
			}
		}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
				for (int l = 0; l < M; l++)
					for (int m = 0; m < N; m++)
						for (int n = 0; n < M; n++) {
							if ((i == k && j == l) || (i == m && j == n) || (k == m && l == n)) continue;
							if (ori_map[i][j] != 0 || ori_map[k][l] != 0 || ori_map[m][n] != 0) continue;

							make_map(i, j, k, l, m, n);		
							qu = ori_qu;

							while (!qu.empty()) {
								int x = qu.front().x;
								int y = qu.front().y;
								qu.pop();

								for (int q = 0; q < 4; q++) {
									int nx = x + dx[q];
									int ny = y + dy[q];

									if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

									if (!visited[nx][ny] && map[nx][ny] == 0) {
										map[nx][ny] = 2;
										visited[nx][ny] = true;
										qu.push(virus(nx, ny));
									}
								}
							}

							getMax();

						}

	cout << maxi;

}