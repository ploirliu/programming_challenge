#include<stdio.h>
#include <algorithm>
using namespace std;
// coin problem
const int V[6] = { 1, 5, 10, 50, 100, 500 };

int C[6];
int A;

void solve_coin(){
	int ans = 0;
	for (int i = 5; i >= 0; --i){
		int t = min(A / V[i], C[i]);
		A -= t*V[i];
		ans += t;
	}
	printf("%d\n", ans);
}