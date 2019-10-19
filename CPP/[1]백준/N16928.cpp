#include<iostream>
#include<queue>
using namespace std;

typedef struct obj {
	int pos, cnt;
}Obj;

int N, M;
int ladders[101], snakes[101];
int visited[101];

queue<Obj> Q;

void init() {
	int a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ladders[a] = b;
	}
	for (int j = 0; j < M; j++) {
		scanf("%d %d", &a, &b);
		snakes[a] = b;
	}
	for (int i = 1; i <= 100; i++) {
		visited[i] = 987654321;
	}
}

int bfs() {
	Q.push({ 1,0 });
	visited[1] = 0;

	while (!Q.empty()) {
		int nowPos, nowCnt, nextPos, nextCnt;
		nowPos = Q.front().pos;
		nowCnt = Q.front().cnt;
		Q.pop();

		if (ladders[nowPos] != 0) {
			nextPos = ladders[nowPos];
			Q.push({ nextPos, nowCnt });
			continue;
		}
		else if (snakes[nowPos] != 0) {
			nextPos = snakes[nowPos];
			Q.push({ nextPos, nowCnt });
			continue;
		}

		for (int i = 1; i <= 6; i++) {
			nextPos = nowPos + i;
			nextCnt = nowCnt + 1;
			
			if (nextPos > 100) 
				continue;

			if (nextCnt < visited[nextPos]) {
				visited[nextPos] = nextCnt;
				Q.push({ nextPos, nextCnt });
			}
		}
	}
	return visited[100];
}

int main() {
	int answer;
	init();

	answer = bfs();

	printf("%d\n", answer);
	return 0;
}