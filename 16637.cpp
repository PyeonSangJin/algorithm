#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

long long ans = -1999999999;
int N;
string input;
vector<char> mark;

void cal(vector<pair<long long, bool>> num, vector<char> mark) {
	for (int i = 0; i < N / 2; i++) {
		if (num.size() > i + 1)
			if (num.at(i).second) {
				int a, b;
				a = num.at(i).first;
				b = num.at(i + 1).first;
				num.erase(num.begin() + i + 1);

				if (mark.at(i) == '+') num.at(i).first = a + b;
				else if (mark.at(i) == '-') num.at(i).first = a - b;
				else if (mark.at(i) == '*') num.at(i).first = a * b;

				num.at(i).second = false;
				mark.erase(mark.begin() + i);
			}
	}
	for (; 1 < num.size();) {
		int a, b;
		a = num.at(0).first;
		b = num.at(1).first;
		num.erase(num.begin() + 1);

		if (mark.at(0) == '+') num.at(0).first = a + b;
		else if (mark.at(0) == '-') num.at(0).first = a - b;
		else if (mark.at(0) == '*') num.at(0).first = a * b;

		mark.erase(mark.begin());
	}

	ans = max(ans, num.at(num.size() - 1).first);
}

void dfs(int index, vector<pair<long long, bool>> num) {
	if (index > N / 2) {
		cal(num, mark);
		return;
	}
	dfs(index + 1, num);
	num.at(index).second = true;
	dfs(index + 2, num);
}

int main(int argc, char *argv[]) {
	freopen("test.txt", "r", stdin);

	cin >> N >> input;
	vector<pair<long long, bool>> num;

	for (int i = 0; i < N; i += 2) {
		num.push_back((make_pair(long long(input.at(i) - '0'), false)));
		if (i + 1 < N)
			mark.push_back(input.at(i + 1));
	}

	dfs(0, num);

	cout << ans;
	return 0;
}