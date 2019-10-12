#include <iostream>
#include <vector>

using namespace std;
const int MAX=1000000;
bool check[MAX+1];

int main(){
	vector<int> prime;
	check[0] = check[1] = true;
	for(int i=2; i<=MAX; i++){
		if(check[i]==false){
			prime.push_back(i);
			for(int j=i+i; j<=MAX; j+=i){
				check[j] = true;
			}
		}
	}
			
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		int ans=0;
		for(int i=0; i<prime.size(); i++){
			
			int b = N - prime[i];	
			if(b>=2 && b>=prime[i]){
				if(check[b] == false){
					ans++;
				}
			}else{
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}