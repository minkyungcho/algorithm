#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];
int main(){
    // 소수 저장하는 곳
    vector<int> primes;
    for(int i=2; i<=1000000; i++){
        if(check[i] == false){
            primes.push_back(i);
            for(int j=i+i; j<=1000000; j+=1){
                check[j] = true;
            }
        }
    }


    // 입력 받는곳
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        int ans = 0;
        for(int i=0; i<primes.size(); i++){
            if(2<=N-primes[i] && primes[i]<=N-primes[i]){
                if(check[N-primes[i]] == false){
                    ans += 1;
                }
            }else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}