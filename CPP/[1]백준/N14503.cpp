#include<iostream>
using namespace std;
int N, M, r, c, dir;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int map[50][50];
void init() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
}
int solve() {
	int ret = 0, now = 1;
	bool visited[50][50] = { false };
	bool flag_go;
	
	while (true) {
		flag_go = false;
		switch (now) {
		case 1:
			visited[r][c] = true;
			map[r][c] = 2;
			ret++;
			now = 2;
			break;

		case 2:
			int nextDir, nextR, nextC;
			for (int i = 0; i < 4; i++) {
				nextDir = (dir + 3) % 4; // 왼쪽 방향
				nextR = r + dr[nextDir];
				nextC = c + dc[nextDir];

				if (visited[nextR][nextC] == true || map[nextR][nextC] == 1) {
					dir = nextDir;
					continue;
				}
				r = nextR;
				c = nextC;
				dir = nextDir;
				flag_go = true;
				break;
			}

			if (flag_go)
				now = 1;
			else {
				nextR = r + dr[(dir + 2) % 4];
				nextC = c + dc[(dir + 2) % 4];

				if (map[nextR][nextC] == 1)
					return ret;
				else {
					r = nextR;
					c = nextC;
					now = 2;
				}
			}
		}
	}
	return ret;
}
int main() {
	int answer = 0;
	//freopen("sample_input.txt", "r", stdin);
	init();
	answer = solve();
	printf("%d", answer);
	return 0;
}