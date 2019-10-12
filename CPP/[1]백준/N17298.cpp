#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int N;
	// 수열 a의 크기 입력받기
	cin >> N;
	
	vector<int> A(N); // 수열 a
	vector<int> NGE(N); // 정답수열 NGE
	stack<int> s; // 인덱스 넣을 스택
	
	
	// 수열 a 입력받기
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	
	s.push(0); // 인덱스 0부터 비교
	
	for(int i=1; i<N; i++){
		// 스택에 수가 없으면 현재 위치를 스택에 넣는다
		if(s.empty()){
			s.push(i);
		}
		
		// 스택이 비어있지 않고, 스택 가장 위에 있는 수 A[s.top()]보다 현재 수 A[i]가 클때 오큰수를 찾음. NGE[s.top()]는 현재 수 A[i]가 된다. 
		while(!s.empty() && A[i]>A[s.top()]){
			NGE[s.top()] = A[i];
			s.pop(); // 오큰수 NGE 찾았으니 스택에서 뺌
		}
		
		s.push(i);		
	}
	while(!s.empty()){
		NGE[s.top()] = -1; // 오큰수를 못찾으면 -1
		s.pop();
	}
	
	// NGE 출력
	for(int i=0; i<N; i++){
		cout << NGE[i] << " ";
	}
	cout << endl;
	
	return 0;

}