#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

#define piii pair<pair<int,int>,int>

using namespace std;

typedef struct shark{
	int r, c, t;
}Shark;

int shark_r, shark_c, shark_size;
int eatCnt;
int map[20][20];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int N;
vector<piii> eatable_fishes;
bool cmp1(const piii& a, const piii& b){
	if(a.second < b.second){
		return true;
	}else if(a.second == b.second){
		if(a.first.first < b.first.first){
			return true;
		}else if(a.first.first == b.first.first){
			return a.first.second < b.first.second;
		}else {
			return false;
		}
	}else {
		return false;
	}
}

void init(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 9){
				shark_r = i;
				shark_c = j;
				shark_size = 2;
				map[i][j] = 0;
			}
		}
	}
}

int bfs(){
	queue<Shark> Q;
	int minT = INT_MAX;
	bool visited[20][20] = {false};
	int ret = 0;
	
	eatable_fishes.clear();
	
	visited[shark_r][shark_c] = true;
	Q.push({shark_r, shark_c, 0});
	
	while(!Q.empty()){
		int nowR = Q.front().r;
		int nowC = Q.front().c;
		int nowT = Q.front().t;
		Q.pop();
		
		// 먹을수 있는 고기
		if(map[nowR][nowC]!=0 && map[nowR][nowC]<shark_size){
			if(minT < nowT){
				continue;
			}else {
				minT = nowT;
				eatable_fishes.push_back({{nowR,nowC},nowT});
			}
		}
		
		for(int i=0; i<4; i++){
			int nextR = nowR + dr[i];
			int nextC = nowC + dc[i];
			int nextT = nowT + 1;
			
			if(0<=nextR && nextR<N && 0<=nextC && nextC<N){
				if(visited[nextR][nextC]==false){
					// 지나갈 수 있는 고기
					if(map[nextR][nextC]<=shark_size){
						visited[nextR][nextC] = true;
						Q.push({nextR,nextC,nextT});
					}
				}
			}
		}
	}
	
	if(minT == INT_MAX){
		ret = -1;
	}else {
		ret = minT;
	}
	return ret;
}

int solve(){
	int ret = 0;
	int eatT = 0;
	while(true){
		eatT = bfs();
		if(eatT == -1){
			break;
		}else {
			sort(eatable_fishes.begin(), eatable_fishes.end(), cmp1);
			
			eatCnt++;
			shark_r = eatable_fishes[0].first.first;
			shark_c = eatable_fishes[0].first.second;
			map[shark_r][shark_c] = 0;
			if(eatCnt == shark_size){
				shark_size++;
				eatCnt = 0;
			}
			ret += eatT;
		}
	}
	return ret;
}

int main(){
	int ans = 0;
	init();
	ans = solve();
	printf("%d", ans);
	return 0;
}