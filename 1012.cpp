#include<iostream>
using namespace std;
#pragma warning (disable:4996)

#include<queue>


int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);
	int T, a, b;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int arr[100][100] = { 0, };
		bool visited[100][100] = { 0, };

		int M, N, K;
		int cnt = 0;

		cin >> M >> N >> K;

		for (int k = 0; k < K; k++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}
		
		queue<pair<int, int>> qu;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {

				if (arr[i][j] != 0 && visited[i][j] == 0) {
					qu.push(make_pair(i, j));
					visited[i][j] = true;

					while (!qu.empty()) {
						pair<int,int> val = qu.front();
						qu.pop();
						int x, y;

						x = val.first;
						y = val.second;

						for (int l = 0; l < 4; l++) {
							int nx = dx[l] + x;
							int ny = dy[l] + y;

							if (!visited[nx][ny] && arr[nx][ny] == 1) {
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