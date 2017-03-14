// this is about queue
#include <iostream>
#include <queue>
using namespace std;

int test(){
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	printf("%d\n", que.front());// 1
	que.pop();
	printf("%d\n", que.front());// 2
	que.pop();
	printf("%d\n", que.front());// 3
	que.pop();
	return 0;
}