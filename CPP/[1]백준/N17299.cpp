#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N; // 수열 크기 입력
	
	vector<int> A(N);
	vector<int> NGF(N);
	// int freq[1000001];
	vector<int> freq(1000001,0);
	stack<int> s;
	
	for(int i=0; i<N; i++){
		cin >> A[i];
		freq[A[i]] += 1;
	}
	s.push(0);
	for(int i=1; i<N; i++){
		if(s.empty()){
			s.push(i);
		}
		while(!s.empty() && freq[A[s.top()]]<freq[A[i]]){
			NGF[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty()){
		NGF[s.top()] = -1;
		s.pop();
	}
	
	for(int i=0; i<N; i++){
		cout << NGF[i] << " ";
	}
	cout << endl;
	
	return 0;
	
}