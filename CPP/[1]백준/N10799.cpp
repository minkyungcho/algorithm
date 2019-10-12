#include <iostream>
#include <stack>

using namespace std;

int main(){
	string str;
	cin >> str;
	int l = str.size();
	stack<int> s;
	int ans = 0;
	for(int i=0; i<l; i++){
		// '(' 괄호면 스택에 해당인덱스 넣기
		if(str[i] == '('){
			s.push(i);
		}else {
			// 스택의 top과 인덱스 차이가 1이면 레이저
			if(s.top()+1 == i){
				s.pop(); // 스택 top의 괄호 인덱스 빼주고(레이저이기 때문)
				ans += s.size(); // 스택의 크기는 레이저가 자르는 쇠막대기 개수와 같음 
			}else { 
				// 스택의 top과 인덱스 차이가 1보다 크면 쇠막대기의 끝을 의미.
				s.pop(); // 쇠막대기 끝났으니까 스택에서 빼줌
				ans += 1; // 쇠막대기 1개를 레이저가 3번 자르면 쇠막대기는 4개 조각으로 나누어지듯, 쇠막대기의 끝에서 1을 더해야한다.
			}
		}
	}
	// 출력
	cout << ans << endl;
	return 0;
}