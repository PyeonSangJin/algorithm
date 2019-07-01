#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<string.h>
#include<queue>

int dx[] = { 0,0,-1,1, -1, 1, -1, 1 };
int dy[] = { -1,1,0,0, 1, 1, -1, -1 };

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);

	int w, h;


	while (1) {
		int map[100][100] = { 0, };
		int visited[100][100] = { 0, };
		int cnt = 0;

		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;
		if (w == 0 && h == 0) return 0;

		int val;

		for (int j = 0; j < h; j++)
			for (int i = 0; i < w; i++)
			{
				cin >> val;
				map[j][i] = val;
			}

		queue<pair<int, int>> qu;

		for (int j = 0; j < w; j++) {
			for (int i = 0; i < h; i++) {
				if (map[i][j] != 0 && visited[i][j] == 0) {

					qu.push(make_pair(i, j));
					visited[i][j] = true;

					while (!qu.empty()) {
						pair<int, int> val = qu.front();
						qu.pop();
						int x, y;

						x = val.first;
						y = val.second;

						for (int l = 0; l < 8; l++) {
							int nx = dx[l] + x;
							int ny = dy[l] + y;

							if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

							if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
								qu.push(make_pair(nx, ny));
								visited[nx][ny] = true;
							}
						}
					}
					cnt++;
				}


			}
		}
		cout << cnt << endl;
	}
}