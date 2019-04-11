#include "pch.h"
#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

int arr[10][10];
int draw[10][10];
int minVal = 2099999999;

int sizing[6] = { 0, };

void drawing(int x, int y, int boxsize, int flag) {
	for (int i = x; i < x + boxsize; i++)
		for (int j = y; j < y + boxsize; j++)
			draw[i][j] = flag;
}

bool isDrawing(int x, int y, int boxsize) {
	if (x + boxsize > 10 || y + boxsize > 10)
		return false;

	for (int i = x; i < x + boxsize; i++)
		for (int j = y; j < y + boxsize; j++)
			if (draw[i][j] != 0 || arr[i][j] != 1)
				return false;

	return true;
}

bool isSame() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i][j] != draw[i][j])
				return false;
	return true;
}

void dfs(int x, int y) {

	for (int i = 5; i > 0; i--) 
		if (sizing[i] > 5) return;

	if (isSame()) {
		int sum = 0;
		for (int i = 5; i > 0; i--) sum += sizing[i];
		minVal = min(minVal, sum);
		return;
	}

	for (int i = 0; i < 10; i++) {
		bool br = false;
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1 && draw[i][j] == 0) {
				br = true;
				x = i;
				y = j;

				break;
			}
		}
		if (br) break;
	}

	for (int size = 5; size > 0; size--) {
		if (isDrawing(x, y, size)) {
			sizing[size]++;

			drawing(x, y, size, 1);
			dfs(x, y);
			drawing(x, y, size, 0);
			sizing[size]--;
		}
	}
}


int main(int argv, char* argc[]) {
	freopen("text.txt", "r", stdin);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];

	dfs(0, 0);

	if (minVal == 2099999999)
		minVal = -1;

	cout << minVal;
}