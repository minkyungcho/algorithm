// DP
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int count_0, count_1;
vector<int> count_0_vec, count_1_vec;

int fibo(int n){
    if(n == 0){
        count_0++;
        return 0;
    }else if(n == 1){
        count_1++;
        return 1;
    }else {
        return fibo(n-1)+ fibo(n-2);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int N;
        scanf("%d", &N);
        count_0, count_1 = 0;
        fibo(N);
        count_0_vec.push_back(count_0);
        count_1_vec.push_back(count_1);
    }
    for(int i=0; i<count_0_vec.size(); i++){
        printf("%d %d\n", count_0_vec[i], count_1_vec[i]);
    }

}
