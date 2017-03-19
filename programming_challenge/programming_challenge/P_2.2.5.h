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

int all[6];

void solve(){
	ll out = 0;
	out += (ll)all[5];
	
	out += (ll)all[4]; all[0] = max(0, all[0] - 11*all[5]);
	
	out += (ll)all[3];
	int tmp = all[3] * 5;
	int tmp2 = max(0, tmp-all[1])*4;
	all[1] = max(0, all[1] - tmp);
	all[0] = max(0, all[0] - tmp2);

	out += (ll)(all[2] / 4);
	tmp = all[2] % 4;
	++out;
	if (tmp == 3){
		if (all[1]){
			--all[1];
			all[0] = max(0, all[0] - 5);
		}
		else{
			all[0] = max(0, all[0] - 9);
		}
	}
	else if (tmp == 2){
		if (all[1]){
			tmp2 = max(0, 3 - all[1]);
			all[1] = max(0, all[1] - 3);
			all[0] = max(0, all[0] - (18 - 4 * tmp2));
		}
		else{
			all[0] = max(0, all[0] - 18);
		}
	}
	else if (tmp){
		if (all[1]){
			tmp2 = max(0, 5 - all[1]);
			all[1] = max(0, all[1] - 5);
			all[0] = max(0, all[0] - (27 - 4 * tmp2));
		}
		else{
			all[0] = max(0, all[0] - 27);
		}
	}
	else{
		--out;
	}

	out += (ll)(all[1] / 9);
	tmp = all[1] % 9;
	if (tmp){
		++out;
		all[0] = max(0, all[0] - (36 - 4 * tmp));
	}

	out += (ll)(all[0] / 36);
	tmp = all[0] % 36;
	if (tmp){
		++out;
	}
	printf("%lld\n", out);
}

int main(){
	while (scanf("%d %d %d %d %d %d", &all[0], &all[1], &all[2], &all[3], &all[4], &all[5])!=EOF){
		solve();
	}
	return 0;
}