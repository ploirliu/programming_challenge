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
typedef long long ll;

const int MAX_N = 1000005;
const int MAX_M = 1005;
typedef struct node{
	int start, end,eff;
	int ans;
	bool operator<(const node&right)const{
		return end < right.end;
	}
}node;

int out[MAX_N];
node all[MAX_M];
int n, m, r;
void solve(){
	//memset(out, 0, sizeof(out));
	////map<int, int> out;
	////out[0] = 0;
	////sort(all, all + m);
	////int myout = 0;
	////for (int i = 0; i < m; ++i){
	////	int tmpid = (all[i].start - r) < 0 ? 0 : (all[i].start - r);
	////	int tmp=
	////}
	////printf("%d\n", myout);
	//int id = 0;
	//ll myout = 0;
	//sort(all, all + m);
	//for (int i = 1; i <= n; ++i){
	//	if (id < m){
	//		if (i < all[id].end){
	//			out[i] = out[i - 1];
	//		}
	//		else if (i == all[id].end){
	//			while (id < m && all[id].end <= i){
	//				int tmpid = (all[id].start - r) < 1 ? 0 : (all[id].start - r);
	//				//cout << tmpid << ' ' << id << endl;
	//				out[i] = max(out[i - 1], (ll)out[tmpid] + (ll)all[id].eff);
	//				++id;
	//			}
	//			//cout << tmpid << ' ' << id << endl;
	//		}
	//	}
	//	else{
	//		out[i] = out[i - 1];
	//	}
	//	myout = max(myout, out[i]);
	//}
	////for (int i = 0; i <= n; ++i)
	////	cout << i << ' ' << out[i] << endl;
	//printf("%lld\n", myout);

	memset(out, 0, sizeof(out));
	sort(all, all + m);
	int id = 0;
	int myout = 0; 
	for (int i = 0; i <= n; ++i){
		if (id < m){
			if (i < all[id].end){
				if(i>0)
					out[i] = out[i - 1];
			}
			else{
				while (id < m && all[id].end <= i){
					int tmp = 0;
					if (all[id].start - r < 0){
						tmp = all[id].eff;
					}
					else{
						tmp = out[all[id].start - r] + all[id].eff;
					}
					if (i > 0)
						tmp = max(tmp, out[i - 1]);
					out[i] = max(tmp, out[i]);
					++id;
				}
			}
		}
		else{
			if (i > 0)
				out[i] = out[i - 1];
		}
		myout = max(myout, out[i]);
	}
	printf("%d\n", myout);
}

//void solve_tmp(){
//	sort(all, all + m);
//	int myout = 0;
//	for (int i = 0; i < m; ++i){
//		if (i == 0){
//			all[i].ans = all[i].eff;
//		}
//		else{
//			int tmp = 0;
//			for (int j = 0; j < i; ++j){
//				if (all[j].end + r <= all[i].start){
//					tmp = max(tmp, all[j].ans);
//				}
//			}
//			all[i].ans = tmp + all[i].eff;
//		}
//		myout = max(myout, all[i].ans);
//	}
//	printf("%d\n", myout);
//}


int main(){
	//freopen("a.in", "r", stdin);
	while (scanf("%d %d %d",&n,&m,&r) != EOF){
		for (int i = 0; i < m; ++i){
			scanf("%d %d %d", &all[i].start, &all[i].end, &all[i].eff);
		}
		solve();
	}
	return 0;
}