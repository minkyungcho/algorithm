#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int nums[10];
char ops[10];
int N, numcnt, opcnt;
long long ans;

void init(){
	numcnt = opcnt = 0;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		if(i%2 == 0){
			scanf("%1d", &nums[numcnt++]);
		}else {
			scanf("%c", &ops[opcnt++]);
		}
	}
}

long long calc(long long a, long long b, char op){
	long long ret = 0;
	switch(op){
		case '+':
			ret = a+b;
			break;
		case '-':
			ret = a-b;
			break;
		case '*':
			ret = a*b;
			break;
	}
	return ret;
}


void dfs(long long result, int opidx){
	int nextresult = 0, nowresult = 0;
	
	// dfs 끝날때 최대값 비교
	if(opidx >= opcnt){
		if(ans < result){
			ans = result;
		}
		return;
	}
	
	nowresult = calc(result, nums[opidx+1], ops[opidx]);
	
	dfs(nowresult, opidx+1); // 왼쪽부터 쭉 계산하는 경우
	
	if(opidx+2 < numcnt){
		nextresult = calc(nums[opidx+1], nums[opidx+2], ops[opidx+1]);
		nowresult = calc(result, nextresult, ops[opidx]);
		dfs(nowresult, opidx+2);
	}
}

void solve(){
	// ans = -987654321;
	ans = -LLONG_MAX; 
	dfs(nums[0], 0);
}

int main(){
	init();
	solve();
	
	cout << ans << "\n";
	
	return 0;
}