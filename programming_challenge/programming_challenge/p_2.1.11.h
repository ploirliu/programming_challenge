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
using namespace std;
const int INF = 1147483647;

bitset<10005> all[15];
int r, c;

//int count(){
//	int out = 0;
//	for (int i = 0; i < all.size(); ++i){
//		for (int j = 0; j < r; ++j){
//			if (((1 << j)&all[i]) == 0){
//				++out;
//			}
//		}
//	}
//	return out;
//}
//
//void show(){
//	for (int i = 0; i < r; ++i){
//		for (int j = 0; j < c; ++j){
//			if (all[j] & (1 << i)){
//				cout << 1 << ' ';
//			}
//			else{
//				cout << 0 << ' ';
//			}
//		}
//		cout << endl;
//	}
//	cout << count() << endl;
//}
//
//
//void dfs(map<vector<int>,int> &stu){
//	show();
//	for (int i = 0; i < r; ++i){
//		for (int j = 0; j < all.size(); ++j){
//			if (all[j] & (1 << i)){
//				all[j] = all[j] & (~(1 << i));
//			//	cout << ((1 << i)) << endl;
//			//	cout << (~(1 << i)) << endl;
//			}
//			else{
//				all[j] = all[j] | (1 << i);
//			}
//		}
//
//		if (stu.count(all) == 0){
//			int t = count();
//			stu[all] = t;
//			out = max(t, out);
//			dfs(stu);
//		}
//
//		for (int j = 0; j < all.size(); ++j){
//			int cache = all[j];
//			if (all[j] & (1 << i)){
//				all[j] = all[j] & (~(1 << i));
//			}
//			else{
//				all[j] = all[j] | (1 << i);
//			}
//		}
//	}
//	for (int i = 0; i < all.size(); ++i){
//		int tmp = 0;
//		for (int j = 0; j < r; ++j){
//			tmp = tmp | (1 << j);
//		}
//		int cache = all[i];
//		all[i] = ~all[i] & tmp;
//		if (stu.count(all) == 0){
//			int t = count();
//			stu[all] = t;
//			out = max(t, out);
//			dfs(stu);
//		}
//		all[i] = cache;
//	}
//}
//
//void solve(){
//	out = -1;
//	map<vector<int>, int> stu;
//	dfs(stu);
//	cout << out << endl;
//}
//

int count(){
	int out = 0;
	for (int j = 0; j < c; ++j){
		int tmp = 0;
		for (int i = 0; i < r; ++i){
			if (all[i][j] == 0)
				++tmp;
		}
		out += max(tmp, r - tmp);
	}
	return out;
}
void show(){
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			cout << all[i][j] << ' ';
		}
		cout << endl;
	}
	cout << count() << endl;
}
void solve(){
	int out = -1;
	for (int i = 0; i < (1 << r); ++i){
		for (int j = 0; j < r; ++j){
			if (i&(1 << j)){
				all[j].flip();
			}
		}
		//show();
		out = max(out, count());

		for (int j = 0; j < r; ++j){
			if (i&(1 << j)){
				all[j].flip();
			}
		}
	}
	cout << out << endl;
}
int main(){
//	freopen("p_2.1.11.txt", "r", stdin);
//	freopen("a.out", "w",stdout);
	while (true){
		scanf("%d %d", &r, &c); 
		if (r == 0 && c == 0)
			break;

		int tmp;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				scanf("%d", &tmp);
				all[i][j] = tmp;
			}
		}

		solve();
	}
	return 0;
}