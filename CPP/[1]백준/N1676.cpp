#include <iostream>

using namespace std;

// int Fact(int n){
// 	if(n==0 || n==1){
// 		return 1;
// 	}else {
// 		return n*Fact(n-1);
// 	}
// }

int main(){
	
	int N;
	cin >> N;
	
	// int result = Fact(N);
	
	int ans = 0;
	// 내 풀이
	// if(N<5){
	// 	ans = 0;
	// }else if(N<25){
	// 	ans = N/5;
	// }else if(N<125){
	// 	ans = N/5 + N/25;
	// }else {
	// 	ans = N/5 + N/25 + N/125;
	// }
	
	// 모범답안
	for(int i=5; i<=N; i*=5){
		ans += N/i;
	}
	
	cout << ans << "\n";
	
	return 0;
}