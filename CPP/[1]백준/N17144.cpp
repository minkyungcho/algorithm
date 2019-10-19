#include <iostream>
#include <vector>

using namespace std;

typedef struct dust{
	int x, y, a;
}Dust;

int N, M, T;
int map[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int machine[2][2];

void init(){
	scanf("%d %d %d", &N,&M,&T);
	int idx = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d",  &map[i][j]);
			if(map[i][j] == -1){
				machine[idx][0] = i;
				machine[idx++][1] = j;
			}
		}
	}
}

void birth(){
	vector<Dust> dusts;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] != -1 && map[i][j] != 0){
				dusts.push_back({i,j,map[i][j]});
			}
		}
	}
	
	for(int i=0; i<dusts.size(); i++){
		int nowX = dusts[i].x;
		int nowY = dusts[i].y;
		int nowA = dusts[i].a;
		int birthCnt = 0;
		
		for(int dir=0; dir<4; dir++){
			int nextX = nowX + dx[dir];
			int nextY = nowY + dy[dir];
			
			if(1<=nextX && nextX<=N && 1<=nextY && nextY<=M && map[nextX][nextY]!=-1){
				map[nextX][nextY] += nowA/5;
				birthCnt++;
			}
		}
		map[nowX][nowY] = map[nowX][nowY] - ((nowA/5)*birthCnt);
	}
}

void clean(){
	int X1,  X2, Y1, Y2;
	int dir1, dir2;
	
	X1 = machine[0][0];
	Y1 = machine[0][1];
	
	X1 = machine[1][0];
	Y1 = machine[1][1];
	
	dir1 = 0;
	dir2 = 2;

	while(true){
		int nextX1 = X1 + dx[dir1];
		int nextY1 = Y1 + dy[dir1];
		
		if(!(1<=nextX1 && nextX1<=machine[0][0] && 1<=nextY1 && nextY1<=M)){
			dir1 = (dir1+1)%4;
			nextX1 = X1 + dx[dir1];
			nextY1 = Y1 + dy[dir1];
		}
		
		if(map[nextX1][nextY1]==-1){
			map[X1][Y1] = 0;
			break;
		}
		
		if(map[X1][Y1] != -1){
			map[X1][Y1] = map[nextX1][nextY1];
		}
		
		X1 = nextX1;
		Y1 = nextY1;
	}
	
	while(true){
		int nextX2 = X2 + dx[dir2];
		int nextY2 = Y2 + dy[dir2];
		
		if(!(machine[1][0]<=nextX2 && nextX2<=N && 1<=nextY2 && nextY2<=M)){
			dir2 = (dir2+3)%4;
			nextX2 = X2 + dx[dir2];
			nextY2 = Y2 + dy[dir2];
		}
		
		if(map[nextX2][nextY2]==-1){
			map[X2][Y2] = 0;
			break;
		}
		
		if(map[nextX2][nextY2] != -1){
			map[X2][Y2] = map[nextX2][nextY2];
		}
		
		X2 = nextX2;
		Y2 = nextY2;
	}
	
}

int getAns(){
	int ret = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] != -1){
				ret += map[i][j];
			}
		}
	}
	return ret;
}

int solve(){
	int ret = 0;
	for(int i=0; i<T; i++){
		birth();
		clean();
	}
	ret = getAns();
	return ret;
}

int main(){
	int ans = 0;
	init();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}