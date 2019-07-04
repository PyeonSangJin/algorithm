#include<iostream>
using namespace std;
#pragma warning(disable:4996)

#include<algorithm>

struct gansun {
	int to;
	int go;

	gansun(int to, int go) :to(to), go(go) {};
	gansun() {};
};

gansun arr[500000];

int main(int argc, char* argv[]) {
	int N, M;

	int ans[1005];
	int rs[1005] = { 0, };

	freopen("test.txt", "r", stdin);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		if (a < b) {
			arr[i].to = a;
			arr[i].go = b;
		}
		else {
			arr[i].to = b;
			arr[i].go = a;
		}
	}

	for (int i = 0; i <= N; i++) 
		ans[i] = i;

	sort(arr, arr + M, [](gansun& a, gansun& b)->bool{
		return a.to < b.to;
	});

	for (int i = 0; i < M; i++) {
		if (ans[arr[i].go] < arr[i].to) {
			ans[arr[i].to] = ans[arr[i].go];
		}else
			ans[arr[i].go] = arr[i].to;
	}

	for (int i = 1;i <= N;i++) {
		

		ans[i] = ans[ans[i]];
		rs[ans[i]] = true;
	}
	int cnt = 0;

	for (int i = 1;i <= N;i++) 
		if (rs[i]) cnt++;

	cout << cnt;

	return 0;

}