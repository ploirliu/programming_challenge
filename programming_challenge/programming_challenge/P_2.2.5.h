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
	
	out += (ll)all[4]; all[0] = max(0, all[0] - 11*all[4]);
	
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
			all[0] = max(0, all[0] - (6+4 * tmp2));
		}
		else{
			all[0] = max(0, all[0] - 18);
		}
	}
	else if (tmp){
		if (all[1]){
			tmp2 = max(0, 5 - all[1]);
			all[1] = max(0, all[1] - 5);
			all[0] = max(0, all[0] - (7+ 4 * tmp2));
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
	//freopen("a.out", "w", stdout);
	while (scanf("%d %d %d %d %d %d", &all[0], &all[1], &all[2], &all[3], &all[4], &all[5]) != EOF){
		bool stu = true;
		for (int i = 0; i < 6; ++i){
			if (all[i] != 0){
				stu = false;
				break;
			}
		}
		if (stu)
			break;
		solve();
	}
	return 0;
}




/*
> 0 0 4 0 0 1                         2
> 7 5 1 0 0 0						  > 1
> 36 9 4 1 1 1						  > 6
> 0 9 4 1 1 0						  > 4
> 0 0 4 0 0 0						  > 1
> 36 0 0 0 0 0						  > 1
> 0 9 0 0 0 0						  > 1
> 79 96 94 30 18 14					  > 86
> 53 17 12 98 76 54					  > 231
> 83 44 47 42 80 3					  > 137
> 15 26 13 29 42 40					  > 115
> 41 61 36 90 54 66					  > 219
> 78 56 445 45 23 65				  > 245
> 13 4 8 29 45 3					  > 79
> 15 75 45 98 34 53					  > 197
> 40 9 0 2 0 0						  > 3
> 41 9 0 2 0 0						  > 4
> 44 0 0 0 4 0						  > 4
> 0 2 3 0 0 0						  > 2
> 37 7 2 0 1 0						  > 3
> 12 2 0 1 0 0						  > 1
> 13 2 0 1 0 0						  > 2
> 0 0 0 0 0 0


2
> 1
> 6
> 4
> 1
> 1
> 1
> 86
> 231
> 137
> 115
> 219
> 245
> 79
> 197
> 3
> 4
> 4
> 2
> 3
> 1
> 2
*/