#include "pch.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int ans;
int N, M;
int err[10];
int arr[999999];

void dfs(int index, int num) {
	if (0 < index&&index <= 6) {
		arr[num] = 1;

		if (index == 6)
			return;
	}

	for (int i = 0; i < 10; i++) {
		bool isin = false;
		for (int j = 0; j < M; j++) {
			if (err[j] == i) {
				isin = true;
				break;
			}
		}
		if (!isin)
			dfs(index + 1, num * 10 + i);
	}
}

int divison(int val) {
	int i = 1;
	while (val / 10 != 0) {
		i++;
		val /= 10;
	}
	return i;
}

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);
	ans = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> err[i];

	dfs(0, 0);

	ans = abs(100 - N);

	for (int i = 0; i < 999999; i++) {
		if (arr[i] == 1) {
			if (abs(i - N) + divison(i) < ans)
				ans = abs(i - N) + divison(i);
		}
	}

	cout << ans;

	return 0;
}