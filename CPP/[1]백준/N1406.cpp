#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
char s[600000];

int main(){
	// string s;
	cin >> s;
	
	int num;
	cin >> num;
	stack<char> left;
	stack<char> right;
	int l = strlen(s);
	for(int i=0; i<l; i++){
		left.push(s[i]);	
	}
	
	// for(int i=0; i<l; i++){
	// 	cout << left.top();
	// 	left.pop();
	// }
	
	while(num--){
		char cmd;
		cin >> cmd;
		if(cmd == 'L'){
			if(!left.empty()){
				char c = left.top();
				right.push(c);
				left.pop();
			}
		}else if(cmd == 'D'){
			if(!right.empty()){
				char c = right.top();
				left.push(c);
				right.pop();
			}
		}else if(cmd == 'B'){
			if(!left.empty()){
				left.pop();
			}
		}else if(cmd == 'P'){
			char c;
			cin >> c;
			left.push(c);
		}
	}
	while(!left.empty()){
		char c = left.top();
		left.pop();
		right.push(c);
	}
	
	while(!right.empty()){
		cout << right.top();
		right.pop();
	}
	
	return 0;
}