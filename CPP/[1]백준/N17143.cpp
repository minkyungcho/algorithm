#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Shark{
	int s, d, z;
}map[101][101], tmp[101][101];

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};
int conv[5] = {0,2,1,4,3};
int X, Y, M, pos, ans;

int getShark(const int& pos){
	int ret = 0;
	for(int x=1; x<=X; x++){
		int z = map[x][pos].z;
		if(z != 0){
			map[x][pos] = {0,0,0};
			ret = z;
			break;
		}
	}
	return ret;
}

void move(){
	memset(tmp, 0, sizeof(tmp));
	for(int i=1; i<=X; i++){
		for(int j=1; j<=Y; j++){
			if( map[i][j].z==0 ){
				continue;
			}
			Shark sk = map[i][j];
			int x=i, y=j;
			
			if(sk.d==1 || sk.d==2){
				sk.s %= ((X-1)*2);
			}else {
				sk.s %= ((Y-1)*2);
			}
			int dist = sk.s;
			
			while(dist--){
				int nextX = x + dx[sk.d];
				int nextY = y + dy[sk.d];
				if(1<=nextX && nextX<=X && 1<=nextY && nextY<=Y){
					x = nextX;
					y = nextY;
				}else {
					if(X<nextX)
						nextX -= 2;
					else if(nextX < 1)
						nextX += 2;
					else if(Y<nextY)
						nextY -= 2;
					else if(nextY < 1)
						nextY += 2;
					
					sk.d = conv[sk.d];
					x = nextX;
					y = nextY;
				}
			}
			if(tmp[x][y].z < sk.z)
				tmp[x][y] = sk;
		}
	}
}

int main(){
	
	scanf("%d %d %d", &X, &Y, &M);
	
	for(int i=1; i<=M; i++){
		int x, y, s, d, z;
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		tmp[x][y] = {s, d, z};
	}
	
	pos = 0;
	
	while(true){
		memset(map, 0, sizeof(map));
		memcpy(map, tmp, sizeof(map));
		pos += 1;
		if( pos==Y+1  ){
			break;
		}
		ans += getShark(pos);
		move();
	}
	
	printf("%d",  ans);
	
	return 0;
}