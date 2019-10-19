#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Virus{
	int x, y;
}Virus;

int N, M, ans, OneNum;
int map[8][8];
bool visited[8][8], visited_bac[8][8];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<Virus> Q;
vector<Virus> tmp;

void init(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2){
				visited[i][j] = true;
				visited_bac [i][j] = true;
				Q.push({i,j});
			}else if(map[i][j] == 1){
				OneNum++;
			}
		}
	}
	while(!Q.empty()){
		tmp.push_back(Q.front());
		Q.pop();
	}
}

int bfs(){
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			visited[i][j] = visited_bac[i][j];
		}
	}
	for(int i=0; i<tmp.size(); i++){
		visited[tmp[i].x][tmp[i].y] = true;
		Q.push(tmp[i]);
	}
	while(!Q.empty()){
		int x = Q.front().x;
		int y = Q.front().y;
		Q.pop();
		cnt++;
		
		int nextX, nextY;
		for(int i=0; i<4; i++){
			nextX = x + dx[i];
			nextY = y + dy[i];
			
			if(0<=nextX && nextX<N && 0<=nextY && nextY<M && visited[nextX][nextY]==false && map[nextX][nextY]==0){
				visited[nextX][nextY] = true;
				Q.push({nextX, nextY});
			}
		}
	}
	return cnt;
}
		  
int solve(){
	int ret, TwoNum;
	TwoNum = bfs();
	ret = N*M - TwoNum - (OneNum+3);
	return ret;
}
		  
void dfs(int cnt){
	if(cnt == 3){
		ans = max(ans, solve());
		return;
	}
	for(int i=0; i<N; i++){
		
		
		
		for(int j=0; j<M; j++){
			if(map[i][j] == 0){
				map[i][j] = 1;
				dfs(cnt+1);
				map[i][j] = 0;
			}
		}
	}
}		  
		  
int main(){
	init();
	dfs(0);
	printf("%d\n",  ans);
	return 0;
}