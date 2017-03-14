// this is about recursion
#include <iostream>
using namespace std;


// n!
int fact(int n){
	if (n == 0) return 1;
	return n*fact(n - 1);
}

// Fibonacci
int fib(int n){
	if (n <= 1) return n;
	return fib(n - 1) + fib(n - 2);
}

const int MAX_N = 1000000;

int memo[MAX_N + 1];
int fast_fib(int n){
	if (n <= 1) return n;
	if (memo[n] != 0) return memo[n];
	return memo[n] = fast_fib(n - 1) + fast_fib(n - 2);
}
