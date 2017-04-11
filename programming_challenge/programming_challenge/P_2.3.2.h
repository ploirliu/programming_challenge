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
using namespace std;
const int INF = 1147483647;
typedef long long ll;

const int len = 1000005;
ll all[len];
int n;
void solve(){
	memset(all, 0, sizeof(all));
	all[1] = 1;
	all[2] = 2;
	for (int i = 3; i <= n; ++i){
		all[i] = all[i - 1] + all[i - 2];
		cout << i<<' '<<all[i] << endl;
	}
	printf("%lld", all[n]);
}

int main(){
	while (scanf("%d",&n ) != EOF){
		solve();
	}
	return 0;
}