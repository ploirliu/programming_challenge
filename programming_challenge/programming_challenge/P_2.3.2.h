#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string.h>
using namespace std;
const int INF = 1147483647;
typedef unsigned long long ll;

const int len = 1000005;
//const int len2 = 20;

//int all[len][len2];
int n;


const int mod = 1000000000;
//const int mod = 10000;
//void solve(){
//	memset(all, 0, sizeof(all));
//	for (int i = 1; i <= n; ++i){
//		for (int j = len2-1; j >=0; --j){
//			//cout << (1 << j) << endl;
//			int tmp = i - (1 << j);
//			if (tmp > 0){
//				all[i][j] = (all[tmp][j]+all[i][j+1])%mod;
//			}
//			else if (tmp == 0){
//				all[i][j] = (all[tmp][j] + 1 + all[i][j + 1]) % mod;
//			}
//			
//		}
//		//for (int j = len2 - 1; j >= 0; --j){
//		//	all[i][j] += all[i][j + 1];
//		//	all[i][j] = all[i][j]%mod;
//		//}
//		//cout << i << endl;
//		//for (int j = 0; j < len2; ++j){
//		//	cout <<' ' << all[i][j] ;
//		//}
//		//cout << endl;
//	}
//	printf("%d\n", all[n][0]);
//}
//int out=0;
//int myadd[len2];
//
//void init(){
//	for (int i = 0; i < len2; ++i)
//		myadd[i] = (1 << i);
//}
//void dfs(int now, int id){
//	if (now == 0){
//		++out;
//		out = out%mod;
//		return;
//	}
//	for (int i = id; i < len2; ++i){
//		if (now - myadd[i] >= 0){
//			dfs(now-myadd[i], i);
//		}
//		else
//			return;
//	}
//}
//void solve_force(){
//	out = 0;
//	init();
//	if (n>0)
//		dfs(n, 0);
//	cout << "force " <<out << endl;
//}
//
//

int all[len];
void solve(){
	memset(all, 0, sizeof(all));
	all[1] = 1; all[2] = 2;
	for (int i = 3; i <= n; ++i){
		all[i] = all[i - 1];
		if (i % 2==0)
			all[i] = (all[i] + all[i >> 1]) % mod;
	}
	printf("%d\n", all[n]);
}
int main(){
	//freopen("a.out", "w", stdout);
	//while (scanf("%d",&n ) != EOF){
	//	solve();
	//	//solve()
	//}
	scanf("%d", &n);
	//for (n = 0; n < 100;++n)
	solve();
	//for (int i = 0; i <500; ++i){
	//	n = i;
	//	cout << n << endl;
	//	solve();
	//	solve_force();
	//}
	return 0;
}