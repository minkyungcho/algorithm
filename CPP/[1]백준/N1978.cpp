#include <iostream>

using namespace std;

bool prime(int n){
	if(n < 2){
		return false;
	}
	for(int i=2; i*i<=n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int N;
	cin >> N;
	int cnt = 0;
	
	while(N--){
		int a;
		cin >> a;
		
		if(prime(a)){
			cnt++;
		}
	}
	cout << cnt << endl;
	
	return 0;
	
}