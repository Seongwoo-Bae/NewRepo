#include <stdio.h>
#include <string.h>
#define WRONG 1000000*16;

int past[18][1 << 18] = { 0, };
int W[18][18];
int N;
int salesman(int now, int visited) {
	if (past[now][visited] != 0) return past[now][visited];

	if (visited == (1<<(N+1))-1) {
		if (W[now][N+1] == 0) return WRONG
		else
			return W[now][N+1];
	}
	int min = WRONG;
	for (int next = 1; next < N+1; next++) {
		if (visited & 1 << next) 
			continue;
		if (W[now][next] == 0)
			continue;
		int value = W[now][next] + salesman(next, visited | (1 << next));
		if (min > value)
			min = value;
	}

	return past[now][visited] = min;
}
int main() {

	scanf_s("%d", &N);
	for (int i = 0; i < N+2; i++)
		for (int j = 0; j < N+2; j++)
			scanf_s("%d", &W[i][j]);

	printf("%d\n", salesman(0, 1 << 0));
}
	