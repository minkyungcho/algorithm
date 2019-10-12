#include <iostream>

using namespace std;

int memo[100];
int fibonacci(int n){
	if(n<=1){
		return n;
	}else {
		if(memo[n] > 0){
			return memo[n];
		}
		memo[n] = fibonacci(n-1) + fibonacci(n-2);
		return memo[n];
	}
}
int main(){
	int N;
	cin >> N;
	int ans = fibonacci(N);
	cout << ans << "\n";
	return 0;
}