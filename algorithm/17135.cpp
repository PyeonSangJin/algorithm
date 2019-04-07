#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)

int W, H, D;
int map[20][20];

typedef struct {
	int a;
	int b;
}tuple1;

tuple1 whois(int manX, int y) {
	int minval = 199999999;
	tuple1 temp;
	temp.a = -1;
	temp.b = -1;

	for (int j = W - 1; j >= 0; j--)
		for (int i = H - 1; i > y - 1; i--)
		{
			if (map[i][j] == 1) {
				if (D >= (abs(manX - j) + abs(y - 1 - i))) {
					if (minval >= (abs(manX - j) + abs(y - 1 - i))) {
						minval = (abs(manX - j) + abs(y - 1 - i));
						temp.a = i;
						temp.b = j;
					}
				}
			}
		}

	return temp;

}

int main()
{
	freopen("text.txt", "r", stdin);

	int ans = 0;
	cin >> H >> W >> D;

	for (int i = H - 1; 0 <= i; i--)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	for (int i = 0; i < W; i++)
		for (int j = i + 1; j < W; j++)
			for (int k = j + 1; k < W; k++) {
				int cnt = 0;
				for (int l = 0; l < H; l++) {
					tuple1 temp;
					int x1, y1, x2, y2, x3, y3;
					temp = whois(i, l);
					x1 = temp.a;
					y1 = temp.b;
					temp = whois(j, l);
					x2 = temp.a;
					y2 = temp.b;
					temp = whois(k, l);
					x3 = temp.a;
					y3 = temp.b;

					if (x1 != -1 && y1 != -1)
						map[x1][y1] = 2;
					if (x2 != -1 && y2 != -1)
						map[x2][y2] = 2;
					if (x3 != -1 && y3 != -1)
						map[x3][y3] = 2;
				}

				for (int n = 0; n < H; n++)
					for (int m = 0; m < W; m++) {
						if (map[n][m] == 2) {
							cnt++;
							map[n][m] = 1;
						}
					}
				ans = max(ans, cnt);
			}

	cout << ans;
}
