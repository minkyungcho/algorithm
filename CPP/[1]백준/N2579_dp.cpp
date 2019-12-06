#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int N, score[300]{0}, dp[300]{ 0 };
    
    // 데이터 입력
    scanf("%d", &N);
    for (int idx = 0; idx < N; idx++) {
        scanf("%d", &score[idx]);
    }
    
    // 문제 해결
    for (int idx = 0; idx < N; idx++) {
        int case1 = score[idx], case2 = score[idx];
        if (idx - 1 >= 0) {
            case1 += dp[idx - 2];
            case2 += score[idx - 1];
            if (idx - 3 >= 0)
                case2 += dp[idx - 3];
        }
        dp[idx] = max(case1, case2);
    }
 
    // 결과 출력
    printf("%d\n", dp[N-1]);
    return 0;
}
