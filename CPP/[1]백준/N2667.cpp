#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map(26, vector<int>(26,0));
vector<vector<int>> finalmap(26, vector<int>(26,0));

vector<vector<int>> visit(26, vector<int>(26,0)); // 방문표시

int dx[4] = {1,-1,0,0}; // 남 북 동 서
int dy[4] = {0,0,1,-1};
int num;
int cnt; // 연결 요소의 수

void DFS(int x, int y){
	for(int i=0; i<4; i++){
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		
		// 좌표 내에 있는지 확인
		if( (0<=nextX) && (nextX<num) && (0<=nextY) && (nextY<num) ){
			
			// 밟을 수 있는 땅이고 아직 방문 안했을때
			if(map[nextX][nextY]==1 && visit[nextX][nextY]==0){
				// 방문 표시
				visit[nextX][nextY] = 1;
				cnt++;
				DFS(nextX, nextY);	
			}
		}
	}
}

int main(){
	vector<int> homenum;
	num;
	cin >> num;
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			// cin >> map[i][j]; 
			scanf("%1d", &map[i][j]);
		}
	}
	cnt = 0;
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			// 밟을 수 있는 땅이고 아직 방문 안했을때
			if(map[i][j]==1 && visit[i][j]==0){
				// 방문 표시
				visit[i][j] = 1;
				cnt++;
				DFS(i, j);	
				homenum.push_back(cnt);
				cnt = 0; // cnt 초기화
			}
		}
	}
	
	int l = homenum.size();
	
	sort(homenum.begin(), homenum.end());
	
	//cout << endl;
	cout << homenum.size() << "\n";
	
	for(int i=0; i<homenum.size(); i++){
		cout << homenum[i] << " ";
	}
	cout << endl;
	
	// finalmap 출력
	// cout << endl;
	// for(int i=1; i<=num; i++){
	// 	for(int j=1; j<=num; j++){
	// 		cout << finalmap[i][j] << " "; 
	// 	}
	// 	cout << endl;
	// }
}