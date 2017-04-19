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

int n, m;
typedef struct node{
	char c;
	int add;
	int sub;
}node;

const int len = 2015;
char s[len];
//char s2[len];
node all[30];

int cost[len][len];

//map<string, int> dp;
//
//int mydp(string &str){
//	if (dp.count(str))
//		return dp[str];
//	int out = INF;
//	for (int i = 0; i < str.size(); ++i){
//		string a = str.substr(0, i);
//		string b=
//	}
//	return 1;
//}

//inline int id(int i){
//	return i - 1;
//}

//void solve(){
//	memset(cost, 0, sizeof(cost));
//	for (int i = 0; i < m; ++i){
//		for (int j = m-1; j >= 0; --j){
//			if (s1[i] == s1[j]){
//				cost[id(i)][id(j)] = cost[id(i - 1)][id(j + 1)];
//			}
//			else{
//				cost[id(i)][id(j)] = min(cost[id(i - 1)][id(j)] + min(all[s1[i] - 'a'].add, all[s1[i] - 'a'].sub), cost[id(i)][id(j + 1)] + min(all[s1[j] - 'a'].add, all[s1[j] - 'a'].sub));
//			}
//		}
//	}
//	printf("%d\n", cost[id(m - 1)][id(0)]);
//}

//void show(){
//	for (int i = 0; i <= (m + 1); ++i){
//		for (int j = 0; j <= (m + 1); ++j){
//			cout << cost[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//void solve(){
//	memset(cost, 0, sizeof(cost));
//	for (int j = m + 1; j > 0; --j){
//		if (j != (m + 1)){
//			cost[0][j] = cost[0][j + 1] + min(all[s1[id(j)]].add, all[s1[id(j)]].sub);
//		}
//	}
//	for (int i = 1; i <= m; ++i){
//		for (int j = m + 1; j > 0; --j){
//			if (j == (m + 1)){
//				cost[i][j] = cost[i - 1][j] + min(all[s1[id(i)]].add, all[s1[id(i)]].sub);
//			}
//			else if (s1[id(i)] == s1[id(j)]){
//				cost[i][j] = cost[i-1][j+1];
//			}
//			else{
//				cost[i][j] = min(cost[i - 1][j] + min(all[s1[id(i)] - 'a'].add, all[s1[id(i)] - 'a'].sub), cost[i][j + 1] + min(all[s1[id(j)] - 'a'].add, all[s1[id(j)] - 'a'].sub));
//			}
//		}
//	}
//	//show();
//	printf("%d\n", cost[m][1]);
//}

void show(){
	for (int i = 0; i <= m; ++i){
		for (int j = 0; j <= m; ++j){
			cout << cost[i][j] << ' ';
		}
		cout << endl;
	}
}

inline int f_id(int i){
	return i - 1;
}
inline int b_id(int i){
	return m - i;
}
void solve(){
	memset(cost, 0, sizeof(cost));
	for (int i = 0; i <= m; ++i){
		for (int j = 0; j <= m; ++j){
			if (i == 0 && j == 0)
				continue;
			else if (i == 0){
				cost[i][j] = cost[i][j - 1] + min(all[s[b_id(j)] - 'a'].add, all[s[b_id(j)] - 'a'].sub);
			}
			else if (j == 0){
				cost[i][j] = cost[i - 1][j] + min(all[s[f_id(i)] - 'a'].sub, all[s[f_id(i)] - 'a'].add);
			}
			else if (s[f_id(i)] == s[b_id(j)]){
				cost[i][j] = cost[i - 1][j - 1];
			}
			else{
				cost[i][j] = min(cost[i - 1][j] + min(all[s[f_id(i)] - 'a'].sub, all[s[f_id(i)] - 'a'].add),
					cost[i][j - 1] + min(all[s[b_id(j)] - 'a'].add, all[s[b_id(j)] - 'a'].sub));
			}
		}
	}
	//show();
	printf("%d\n", cost[m][m]/2);
}

int main(){
	freopen("a.in", "r", stdin);
	while (scanf("%d %d",&n,&m ) != EOF){
		//s = new char[m+1];
	//while (true){
		scanf("%s", &s);
		char c;
		for (int i = 0; i < n; ++i){
			scanf("%c", &c);
			scanf("%c", &c);
			scanf("%d %d", &all[c - 'a'].add, &all[c - 'a'].sub);
		}
		solve();
		//delete[]s;
	}
	
	return 0;
}