#include <iostream>

using namespace std;

void go(int n){
	if(n==0){
		return;
	}
	if(n%2 == 0){
		go(-(n/2));
		cout << "0";
	}else {
		if(n>0){
			go(-(n/2));
		}else {
			go((-n+1)/2);
		}
		cout << "1";
	}
}

int main(){
	int n;
	cin >> n;
	// cout << n-1;
	if(n==0){
		cout << "0\n";
	}else {
		go(n);
	}
	return 0;
}