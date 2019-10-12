#include <iostream>
#include <vector>

using namespace std;

int GCD(int x, int y){
	if(y == 0){
		return x;
	}else {
		return GCD(y, x%y);
	}
}

int main(){
	int N,  S;
	cin >> N >> S;
	vector<int> Nloc(N);
	vector<int> Ndiff(N);
	
	for(int i=0; i<N; i++){
		cin >> Nloc[i]; // 동생들 위치 받기
		int diff = S - Nloc[i]; // 동생들과 수빈이의 거리 차이 계산하기
		if(diff < 0){
			diff = -diff;
		}
		Ndiff[i] = diff;
	}
	
	// for(int i=0; i<N; i++){
	// 	cout << Nloc[i] << " ";
	// }
	// cout << "\n";
	int ans = Ndiff[0];
	for(int i=1; i<N; i++){
		ans = GCD(ans, Ndiff[i]);
	}
	
	cout << ans << "\n";
	
	return 0;
	
}