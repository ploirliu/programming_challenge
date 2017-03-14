#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
const int INF = 1147483647;

int all[10];
int k;
char str[1000];
//vector<int> a1, a2;
//map<vector<int>, set<int>> dp;
//
//void dfs(vector<int> &a, set<int> &b, int num, bool first = false){
//	if (a.size() == 1){
//		b.insert(a[0]);
//		return;
//	}
//	bool stu = true;
//	for (int i = 0; i < a.size(); ++i){
//		if (a[i] >= 0){
//			stu = false;
//			break;
//		}
//	}
//	if (stu){
//		b.insert(num);
//		return;
//	}
//	for (int i = 0; i < a.size(); ++i){
//		if (a[i] >= 0){
//			if (first && a[i] == 0)
//				continue;
//			int tmp = a[i];
//			a[i] = -1;
//			dfs(a, b, num * 10 + tmp);
//			a[i] = tmp;
//		}
//	}
//}
//
//void init(){
//	vector<int> tmp;
//	for (int i = 0; i < 10; ++i){
//		tmp.push_back(i);
//	}
//	for (int i = 0; i < (1 << tmp.size()); ++i){
//		vector<int> a; set < int >b;
//		for (int j = 0; j < tmp.size(); ++j){
//			bool stu = i&(1 << j);
//			if (stu){
//				a.push_back(tmp[j]);
//			}
//		}
//		dfs(a, b, 0, true);
//		dp[a] = b;
//	}
//}
//
//
//
//void solve(){
//	int out = INF;
//	for (int i = 0; i < (1 << all.size()); ++i){
//		a1.clear(), a2.clear();
//		for (int j = 0; j < all.size(); ++j){
//			bool stu = i&(1 << j);
//			if (stu){
//				a1.push_back(all[j]);
//			}
//			else{
//				a2.push_back(all[j]);
//			}
//		}
//		
//		for (set<int>::iterator it1 = dp[a1].begin(); it1 != dp[a1].end(); ++it1){
//			for (set<int>::iterator it2 = dp[a2].begin(); it2 != dp[a2].end(); ++it2){
//				if (*it2>*it1 && abs(*it1 - *it2) > out){
//					break;
//				}
//				out = min(out, abs(*it1 - *it2));
//			}
//		}
//
//	}
//	cout << out << endl;
//}
//

void solve(){
	if (k == 2){
		cout << abs(all[0] - all[1]) << endl;
		return;
	}
	int out = INF;
	do{
		//for (int i = 1; i < k; ++i){
		//	if (all[0] == 0 && i!=1){
		//		break;
		//	}
		//	if (all[i] == 0 && (i + 1)<k){
		//		continue;
		//	}
		//	int a = 0, b = 0;
		//	for (int j = 0; j < i; ++j){
		//		a = a * 10 + all[j];
		//	}
		//	for (int j = i; j < k; ++j){
		//		b = b * 10 + all[j];
		//	}
		//	out = min(out, abs(a - b));
		//}
		int mid = k / 2;
		if (all[0] && all[mid]){
			int a = 0, b = 0;
			for (int j = 0; j < mid; ++j){
				a = a * 10 + all[j];
			}
			for (int j = mid; j < k; ++j){
				b = b * 10 + all[j];
			}
			out = min(out, abs(a - b));
			
		}
	} while (next_permutation(all, all + k));
	cout << out << endl;
}

int main(){
	int n;
	cin >> n;
	getchar();
	//init();
	for (int i = 0; i < n; ++i){
		gets(str);
		k = 0;
		for (int j = 0; j < strlen(str); ++j){
			if (str[j] >= '0' && str[j] <= '9'){
				all[k++] = str[j] - '0';
			}
		}
		solve();
	}
	return 0;
}