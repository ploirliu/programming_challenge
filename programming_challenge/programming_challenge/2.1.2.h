// this is about stack
#include <iostream>
#include <stack>
using namespace std;

int test(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	printf("%d\n", s.top()); // 3
	s.pop();
	printf("%d\n", s.top()); // 2
	s.pop();
	printf("%d\n", s.top()); // 1
	s.pop();
	return 0;
}