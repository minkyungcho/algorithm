// DP
#include <iostream>
#include<vector>
#define MAX 15+1
#define INF 987654321
using namespace std;

pair<int, int> work[MAX];
int chk[MAX];
// vector<pair<int,int>> check;
int N;

int go(int pos){
    if(pos == N+1){
        return 0;
    }
    if(pos > N+1){
        return -INF;
    }
    int &ret = chk[pos];
    if(ret != -1){
        return ret;
    }
    return ret = max(go(pos+1), go(pos+work[pos].first)+work[pos].second);
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &work[i].first, &work[i].second);
    }
    memset(chk, -1, sizeof(chk));
    int result = go(1);
    printf("%d\n", result);
}