#include <iostream>

using namespace std;

int Fact(int n){
	if(n==0 || n==1){
		return 1;
	}else {
		return n*Fact(n-1);
	}
}

int main(){
	int N;
	cin >> N;
	int ans = Fact(N);
	cout << ans << "\n";
	return 0;
}