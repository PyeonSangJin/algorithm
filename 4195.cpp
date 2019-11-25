#include<stdio.h>
#define MAX (1<<17)
#pragma warning(disable:4996)

char* strcpy(char* src, char* dest) {
	char* tempDest = dest;
	char* tempSrc = src;
	while (*tempSrc != 0)
		* tempDest++ = *tempSrc++;

	return dest;
}

int strcmp(char* arr1, char* arr2) {
	int i = 0;
	while (arr1[i] != '\0' || arr2[i] != '\0') {
		if (arr1[i] > arr2[i])
			return arr1[i] - arr2[i];       // arr1 > arr2 이면 양수
		else if (arr1[i] < arr2[i])
			return arr1[i] - arr2[i];       // arr1 < arr2 이면 음수
		i++;
	}
	return 0;       // arr1 == arr1 이면 0
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

struct bucket {
	char str[25];
};

int parent[200000];
int level[200000];
bucket hashTable[MAX];
int N;

int hashFunc(char src[]) {
	int a = 0;

	char* tempSrc = src;
	while (*tempSrc != 0) {
		a = ( a+ (a<<4) + *tempSrc) % MAX;
		*tempSrc++;
	}
	return a;
}

void insert(char key[]) {
	int hashIndex = hashFunc(key);

	while (hashTable[hashIndex].str[0] != 0) { //충돌되는 값이 있을 때
		if (!strcmp(key, hashTable[hashIndex].str)) return; //같은게 있으면 리턴
		hashIndex = (hashIndex + 1) % MAX;
	}
	
	strcpy(key, hashTable[hashIndex].str);
	return;
}

int find(char key[]) {
	int hashIndex = hashFunc(key);

	int n = MAX;
	while (n-- > 0 && hashTable[hashIndex].str != 0) {
		if (!strcmp(key, hashTable[hashIndex].str)) return hashIndex;
		hashIndex++;
	}

	return -1;
}

void union_find_init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
		level[i] = 1;
	}
}

int union_find(int n) {
	if (n == parent[n]) return n;

	return parent[n] = union_find(parent[n]);
}

int my_union(int u, int v) {
	u = union_find(u);
	v = union_find(v);

	if (u == v) return level[u];

	int res = level[u] + level[v];

	if (parent[u] > parent[v])
		swap(u, v);

	parent[u] = v;
	level[v] += level[u];

	return res;
}


char input[100005][25];
int main() {
	freopen("test.txt", "r", stdin);
	int T;
	char a[25], b[25];
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		union_find_init();

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%s", &a);
			scanf("%s", &b);
			insert(a);
			insert(b);

			int indexA = find(a);
			int indexB = find(b);

			printf("%d\n",my_union(indexA, indexB));
		}
	}
}