
#include<algorithm> 
#include<iostream> 
#include<queue> 
#include<vector> 
using namespace std; 
typedef struct Virus { int r, c; }Virus; 
int N, M, map[8][8], answer, OneNum; 
bool visited[8][8], visited_bac[8][8]; 
int dr[4] = {-1,0,1,0}; 
int dc[4] = {0,1,0,-1}; 
queue<Virus> Q; 
vector<Virus> tmp; 
void init() { 
	scanf("%d %d", &N, &M); 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) { 
			scanf("%d", &map[i][j]); 
			if (map[i][j] == 2) { 
				visited[i][j] = true;
				visited_bac[i][j] = true; 
				Q.push({ i,j }); 
			} 
			else if (map[i][j] == 1) { 
				OneNum++; 
			}
		}
	} 
	while (!Q.empty()) { 
		tmp.push_back(Q.front());
		Q.pop(); 
	} 
} 
int bfs() { 
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { 
			visited[i][j] = visited_bac[i][j]; 
		} 
	} 
	for (int i = 0; i < tmp.size(); i++) {
		// visited[tmp[i].r][tmp[i].c] = true; 
		Q.push(tmp[i]); 
	} 
	while (!Q.empty()) { 
		int r = Q.front().r; 
		int c = Q.front().c; 
		Q.pop(); 
		cnt++; 
		int nextR, nextC; 
		for (int i = 0; i < 4; i++) { 
			nextR = r + dr[i];
			nextC = c + dc[i]; 
			if (0 <= nextR && nextR < N && 0 <= nextC && nextC < M && visited[nextR][nextC] == false && map[nextR][nextC] == 0) { 
				visited[nextR][nextC] = true; 
				Q.push({nextR, nextC}); 
			}
		}
	}
	return cnt; 
} 
int solve() { 
	int ret, TwoNum; 
	TwoNum = bfs(); 
	ret = N * M - TwoNum - (OneNum + 3); 
	return ret; 
} 
void dfs(int cnt) { 
	if (cnt == 3) { 
		answer = max(answer, solve()); 
		return; 
	} 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) { 
			if (map[i][j] == 0) { 
				map[i][j] = 1; 
				dfs(cnt + 1); 
				map[i][j] = 0; 
			}
		}
	}
}
int main() { 
	init(); 
	dfs(0); 
	printf("%d\n", answer); 
	return 0; 
}