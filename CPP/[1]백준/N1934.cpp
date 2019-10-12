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
	int N;
	cin >> N;
	for(int i=1; i<=N; i++){
		int a,b;
		cin >> a >> b;
		int g = GCD(a,b);
		cout << (a*b)/g << "\n";
	}
	
	return 0;
}