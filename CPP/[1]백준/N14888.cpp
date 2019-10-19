#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int N, plusNum, minusNum, multiNum, divNum, operands[11];
int operatorsNum, AnswerMax, AnswerMin;
char operators[10];

void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &operands[i]);
	scanf("%d %d %d %d", &plusNum, &minusNum, &multiNum, &divNum);
	for (int i = 0; i < plusNum; i++) 
		operators[operatorsNum++] = '+';
	for (int i = 0; i < minusNum; i++) 
		operators[operatorsNum++] = '-';
	for (int i = 0; i < multiNum; i++) 
		operators[operatorsNum++] = '*';
	for (int i = 0; i < divNum; i++) 
		operators[operatorsNum++] = '/';
	AnswerMax = INT_MIN;
	AnswerMin = INT_MAX;
}

int calc(int a, int b, char op) {
	int ret = 0;
	switch (op) {
	case '+':
		ret = a + b;
		break;
	case '-':
		ret = a - b;
		break;
	case '*':
		ret = a * b;
		break;
	case '/':
		ret = a / b;
		break;
	}
	return ret;
}

void dfs(int result, int operandIdx) {
	int nextResult = 0;
	if (operandIdx == operatorsNum) {
		if (AnswerMax < result)
			AnswerMax = result;
		if (AnswerMin > result)
			AnswerMin = result;
		return;
	}
	nextResult = calc(result, operands[operandIdx+1], operators[operandIdx]);
	dfs(nextResult, operandIdx + 1);
}

void perm(int n, int k) {
	if (k == n) {
		dfs(operands[0], 0);
		return;
	}

	for (int i = k; i < n; i++) {
		swap(operators[i], operators[k]);
		perm(operatorsNum, k + 1);
		swap(operators[i], operators[k]);
	}
}

int main() {
	init();
	perm(operatorsNum,0);
	printf("%d\n%d\n", AnswerMax, AnswerMin);
	return 0;
}