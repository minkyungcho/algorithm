#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
vector<int> moves = {1,5,3,5,1,2,1,4};
int result;
    
vector<int> s;


void printS(){
    for(int i=0; i<s.size(); i++){
        printf("%d", s[i]);
    }
    printf("\n");
}
void checkS(){
    printf("checkS\n");
    int len = s.size();
    if(len>=2){
        printf("len이 2보다 큼 : %d %d\n", s[len-2], s[len-1]);
        if(s[len-1] == s[len-2]){
            s.pop_back();
            s.pop_back();
            printf("터졌어요@@");
            result++;
            printS();
        }
    }
}
void print_board(){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}
void pick(int n){
    //printf("%d 뽑기\n", n);
    for(int i=0; i<board.size(); i++){
        if(board[i][n] !=0 ){
            printf("pick %d\n", board[i][n]);
            s.push_back(board[i][n]);
            board[i][n] = 0;
            printS();
            break;
        }
    }    
}
int main(){
    print_board();
    for(int i=0; i<moves.size(); i++){
        pick(moves[i]-1);
        checkS();
    }
    print_board();
    printf("%d", result);
    return 0;
}