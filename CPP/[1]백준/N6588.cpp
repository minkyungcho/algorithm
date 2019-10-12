#include <iostream>
#include <vector>

using namespace std;

const int MAX=1000000;
bool check[MAX+1];
vector<int> prime;

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	check[0] = check[1] = true;
	
	for(int i=2; i+i<=MAX; i++){
		if(check[i] == false){
			prime.push_back(i);
			for(int j=i+i; j<=MAX; j+=i){
				check[j] = true;
			}
		}
	}
	
	while(true){
		int N;
		// cin >> N;
		scanf("%d", &N);
		if(N == 0){
			
			break;
		}
		for(int i=0; i<prime.size(); i++){
			
			int b = N - prime[i];
			if(check[b] == false){
				
				// cout << N << " = " << prime[i] << " + " << b << "\n";
				printf("%d = %d + %d\n", N, prime[i], b);
				break;
			}
			
		}
	}
	return 0;
	
}