#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// vector<int> height;
// vector<int> weight;
pair<int, int> people[50];
int ranking[50];

void compare_people(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(people[i].first > people[j].first && people[i].second > people[j].second){
                ranking[j]++;
            }
        }
    }
}
void print_rank(int N){
    for(int i=0; i<N; i++){
        printf("%d ", ranking[i]+1);
    }
}
int main(){
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d %d", &people[i].first, &people[i].second);
    }

    compare_people(N);
    print_rank(N);
    // printf("\nOUTPUT\n");
    // for(int i=0; i<N; i++){
    //     printf("%d %d\n", people[i].first, people[i].second);
    // }
}