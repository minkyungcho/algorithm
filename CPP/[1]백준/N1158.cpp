#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	cout << "<";
	for(int i=1; i<=n-1; i++){
		for(int j=1; j<=k-1; j++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", "; 
		q.pop();
	}
	cout << q.front() << ">\n";
	return 0;
}
