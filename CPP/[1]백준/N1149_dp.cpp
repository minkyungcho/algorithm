#include <iostream>

using namespace std;

int house_cost[1000][3];
int result[1000][3];

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        house_cost[i][0] = r;
        house_cost[i][1] = g;
        house_cost[i][2] = b;
    }
    result[0][0] = house_cost[0][0];
    result[0][1] = house_cost[0][1];
    result[0][2] = house_cost[0][2];

    for(int i=1; i<T; i++){
        for(int col=0; col<3; col++){
            if(col == 0){
                result[i][0] = house_cost[i][0] + min(result[i-1][1], result[i-1][2]);
            }else if(col == 1){
                result[i][1] = house_cost[i][1] + min(result[i-1][0], result[i-1][2]);
            }else if(col == 2){
                result[i][2] = house_cost[i][2] + min(result[i-1][1], result[i-1][0]);
            }
        }
    }

    int answer = result[T - 1][0] < result[T - 1][1] ? min(result[T - 1][0], result[T - 1][2]) : min(result[T - 1][1], result[T - 1][2]);
    printf("%d\n", answer);
 
    return 0;
}