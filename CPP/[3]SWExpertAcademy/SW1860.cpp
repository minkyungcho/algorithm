#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int T;
int cnt;
int N, M, K;
int people[101]; // n초에 도착하는 사람을 people[n]에 저장
int fish[101]; // n초마다 만든 붕어빵을 fish[n]에 저장

void init();
bool solve();
void print();

void init(){
	scanf("%d", &T);
    while(T--){
        cnt++;
    	//string ans = "";
        scanf("%d %d %d", &N, &M, &K);
        
        memset(people,0,101);
        for(int i=1; i<=N; i++){
            
        	scanf("%d", &people[i]);
            fish[i*M] = K;
        }
        sort(people+1, people+N);
        //sort(people.begin(), people.end());
        //print();
        
        
        if(solve()){
			printf("#%d Possible\n", cnt);        
        }else {
        	printf("#%d Impossible\n", cnt);      
        }
    }
}

bool solve(){
     int fishnum = 0;
    for(int i=1; i<=N; i++){
    	//if(people[i] != 0){
       // }
        int t = people[i]; // 사람이 도착하는 시간(초)
       
        for(int j=1; j<=t; j++){
        	fishnum += fish[j];
        }
        fishnum--;
        if(fishnum<0){
        	return false;
        }
    }
	
    return true;
}
void print(){
	printf("%d\n", T);
    printf("%d %d %d\n", N,M,K);
    for(int i=1; i<=N; i++){
        printf("%d ", people[i]);
    }
    printf("\n");
}

int main() {
    init();
  //  print();
    
    
    return 0;
}
