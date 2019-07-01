#include<iostream>
using namespace std;
#pragma warning (disable:4996)
#include<queue>
#include<string.h>

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N;
char arr[105][105];
bool visited[105][105];

int bfs(char c) {
	int cnt = 0;
	queue<pair<int, int>> qu;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (arr[i][j] == c && visited[i][j] == 0) {
				qu.push(make_pair(i, j));
				visited[i][j] = true;

				while (!qu.empty()) {
					pair<int, int> val = qu.front();
					qu.pop();
					int x, y;

					x = val.first;
					y = val.second;

					for (int l = 0; l < 4; l++) {
						int nx = dx[l] + x;
						int ny = dy[l] + y;

						if (!visited[nx][ny] && arr[nx][ny] == c) {
							qu.push(make_pair(nx, ny));
							visited[nx][ny] = true;
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}


int main(int argc, char* argv[]) {
	freopen("test.txt", "r", stdin);


	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << bfs('R') + bfs('G') + bfs('B');

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			if (arr[i][j] == 'R') arr[i][j] = 'G';
	
	cout << " "  << bfs('G') + bfs('B');
}