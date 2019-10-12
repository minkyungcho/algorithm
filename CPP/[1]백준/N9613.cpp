#include <iostream>

using namespace std;

int GCD(int x, int y){
	if(y == 0){
		return x;
	}else {
		return GCD(y, x%y);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int a[111];
		int N;
		cin >> N;
		
		for(int i=0; i<N; i++){
			cin >> a[i];
		}
		
		long long sum=0;
		
		for(int i=0; i<N-1; i++){
			for(int j=i+1; j<N; j++){
				sum += GCD(a[i], a[j]);
			}
		}
		cout << sum << "\n";
	}
	return 0;
}