#include"pch.h"
#include<iostream>
#include<vector>
using namespace std;

vector<int> arr[1000010];

int main(int argc, char* argv[]) {
	int N, M, num;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[abs(num) % 100000].push_back(num);
	}

	bool isin = false;

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		isin = false;
		for (int j = 0;  j < arr[abs(num) % 100000].size();j++)
			if (num == arr[abs(num) % 100000].at(j)) {
				cout << "1\n";
				isin = true;
				break;
			}
		if(!isin)
			cout << "0\n";
	}

	return 0;
}