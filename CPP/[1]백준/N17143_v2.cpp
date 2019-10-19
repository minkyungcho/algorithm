#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Shark{
	int s, d, z;
}map[101][101], tmp[101][101];

int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,1,-1};
int conv[5] = {0,2,1,4,3};
int R, C, M, pos, ans;

int getShark(const int& pos){
	int ret = 0;
	for(int r=1; r<=R; r++){
		int z = map[r][pos].z;
		if(z != 0){
			map[r][pos] = {0,0,0};
			ret = z;
			break;
		}
	}
	return ret;
}

void move(){
	memset(tmp,0,sizeof(tmp));
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			if(map[i][j].z == 0){
				continue;
			}
			
			Shark sk = map[i][j];
			int r = i;
			int c = j;
			
			// 속도 최적화
			if(sk.d == 1 || sk.d == 2){
				sk.s %= (R-1)*2;
			}else {
				sk.s %= (C-1)*2;
			}
			
			int dist = sk.s;
			// 1칸씩 이동할 경우 다 확인
			while(dist--){
				int nextR = r + dr[sk.d];
				int nextC = c + dc[sk.d];
				
				if(1<=nextR && nextR<=R && 1<=nextC && nextC<=C){
					r = nextR;
					c = nextC;
				}else {
					if(R < nextR) nextR -= 2;
					else if(nextR < 1) nextR += 2;
					else if(C < nextC) nextC -= 2;
					else if(nextC < 1) nextC += 2;
					
					sk.d = conv[sk.d];
					r = nextR;
					c = nextC;
				}
			}
			
			if(tmp[r][c].z < sk.z){
				tmp[r][c] = sk;
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int i=1; i<=M; i++){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r,&c,&s,&d,&z);
		tmp[r][c] = {s,d,z};
	}
	pos = 0;
	while(true){
		memset(map,0,sizeof(map));
		memcpy(map,tmp,sizeof(map));
		pos += 1;
		if(pos == C+1){
			break;
		}
		ans += getShark(pos);
		move();
	}
	printf("%d", ans);
	return 0;
}