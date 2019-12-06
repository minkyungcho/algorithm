#include <iostream>

using namespace std;

int d[1000001];

int go(int N){
    if(N == 1){
        return 0;
    }
    if(d[N] > 0){
        return d[N];
    }
    d[N] = go(N-1) + 1;
    if(N%2 == 0){
        int tmp = go(N/2)+1;
        if(d[N]>tmp){
            d[N] = tmp;
        }
    }
    if(N%3 == 0){
        int tmp = go(N/3)+1;
        if(d[N]>tmp){
            d[N] = tmp;
        }
    }
    return d[N];
}

int main(){
    int N;
    scanf("%d", &N);
    int result = 0;
    result = go(N);
    printf("%d", result);
}