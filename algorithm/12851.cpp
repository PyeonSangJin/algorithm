#include "pch.h"
#include<iostream>
#include<queue>
#include <tuple>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

#define MAX_RANGE 100000

queue<tuple <int, int> > q;
int s, e;
int visited[100001];
int layervisited[100001];
int temp[100001];

int pos, depth, routin = 0;
int max_depth = 987654321;

int main(int argv, char* argc[]) {
	freopen("text.txt", "r", stdin);

	cin >> s >> e;

	visited[s] = 1;
	q.push(make_tuple(s, 0));

	int pre = 0;
	bool isFirst = false;

	while (!q.empty()) {
		tie(pos, depth) = q.front(); q.pop();

		if (pos == e) {
			if (!isFirst) {
				isFirst = true;
				max_depth = depth;
			}
			routin++;
		}

		if (pre != depth) {
			memset(layervisited, 0, sizeof(layervisited));
			pre = depth;
		}

		if (max_depth > depth) {
			if (pos < e) {
				if (pos * 2 <= MAX_RANGE) {
					if (!visited[pos * 2]) {
						visited[pos * 2] = 1;
						layervisited[pos * 2] = 1;
						q.push(make_tuple(pos * 2, depth + 1));
					}
					else if (depth == pre && layervisited[pos * 2]) {
						q.push(make_tuple(pos * 2, depth + 1));
					}
				}
				if (pos + 1 <= MAX_RANGE) {
					if (!visited[pos + 1]) {
						visited[pos + 1] = 1;
						layervisited[pos + 1] = 1;
						q.push(make_tuple(pos + 1, depth + 1));
					}
					else if (depth == pre && layervisited[pos + 1]) {
						q.push(make_tuple(pos + 1, depth + 1));
					}
				}
			}
			if (pos - 1 >= 0) {
				if (!visited[pos - 1]) {
					visited[pos - 1] = 1;
					layervisited[pos - 1] = 1;
					q.push(make_tuple(pos - 1, depth + 1));
				}
				else if (depth == pre && layervisited[pos - 1]) {
					q.push(make_tuple(pos - 1, depth + 1));
				}
			}
		}
	}
	std::cout << max_depth << "\n" << routin;
}