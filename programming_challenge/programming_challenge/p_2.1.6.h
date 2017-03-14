#include <cstdio>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;


//const  int dx[5] = { 1, 0, -1, 0,0 };
//const int dy[5] = { 0, 1, 0, -1,0 };
//const int h = 401;
//const int w = 401;
//int n;
//int last_t;
//typedef pair<int, int> P;
//
//
//map<int, vector<P>> a;
//
//void solve(){
//	int ans = -1;
//	map<P, int> g;
//	set<P> s1;
//	g[P(0, 0)] = 0;
//	s1.insert(P(0, 0));
//	set<P> s2;
//	vector<P> last;
//	last.push_back(P(0, 0));
//	for (int i = 0; i <= last_t; ++i){
//		if (g.empty()){
//			printf("%d\n", -1);
//			return;
//		}
//		if (a.count(i)){
//			for (int j = 0; j < a[i].size(); ++j){
//				for (int k = 0; k < 5; ++k){
//					int x = a[i][j].first + dx[k], y = a[i][j].second + dy[k];
//					if (x >= 0 && x < w && y >= 0 && y < h){
//						s2.insert(P(x, y));
//						if (g.count(P(x, y))){
//							g.erase(P(x, y));
//						}
//					}
//				}
//			}
//		}
//
//		vector<P> tmp;
//		for (int j = 0; j < last.size(); ++j){
//			if (s2.count(last[j]))
//				continue;
//			for (int k = 0; k < 4; ++k){
//				int x = last[j].first + dx[k], y = last[j].second + dy[k];
//				if (x >= 0 && x < w && y >= 0 && y < h && s1.count(P(x,y))==0 && s2.count(P(x,y))==0){
//					s1.insert(P(x, y));
//					g[P(x, y)] = i + 1;
//					tmp.push_back(P(x, y));
//				}
//			}
//		}
//		last = tmp;
//	}
//	if (g.empty())
//		printf("%d\n", -1);
//	else{
//		int ans = last_t+1;
//		for (map<P, int>::iterator it = g.begin(); it != g.end(); ++it){
//			ans = min(ans, it->second);
//		}
//		printf("%d\n", ans);
//	}
//}
//
//int main(){
//	scanf("%d", &n);
//	a.clear();
//	last_t = -1;
//	for (int i = 0; i < n; ++i){
//		int x, y, t;
//		scanf("%d %d %d", &x, &y, &t);
//		a[t].push_back(P(x, y));
//		last_t = max(last_t, t);
//	}
//	solve();
//	return 0;
//}


const int h = 305;
const int w = 305;
const int MAX_T = 1005;
int n,last_t;

int all[h][w];

typedef pair<int, int> P;
vector<vector<P>> a;


const  int dx[5] = { 1, 0, -1, 0,0 };
const int dy[5] = { 0, 1, 0, -1,0 };

void show(int sh, int sw){
	for (int i = 0; i < sh; ++i){
		for (int j = 0; j < sw; ++j){
			cout << all[i][j] << " ";
		}
		cout << endl;
	}
}


void solve(){
	memset(all, 0, sizeof(all));
	//printf("%d\n", -1);
	vector<P> last;
	last.push_back(P(0,0));
	all[0][0] = 1;
	for (int i = 0; i <= last_t; ++i){
		if (a[i].size()){
			for (int j = 0; j < a[i].size(); ++j){
				for (int k = 0; k < 5; ++k){
					int x = a[i][j].first + dx[k], y = a[i][j].second + dy[k];
					if (x >= 0 && x < w && y >= 0 && y < h){
						all[y][x] = -1;
					}
				}
			}
		}
		vector<P> tmp;
		for (int j = 0; j < last.size(); ++j){
			if (all[last[j].second][last[j].first] < 0)
				continue;
			for (int k = 0; k < 4; ++k){
				int x = last[j].first + dx[k], y = last[j].second + dy[k];
				if (x>=0 && x<w && y>=0 && y<h && all[y][x] == 0){
					all[y][x] = i + 2;
					tmp.push_back(P(x,y));
				}
			}
		}
		last = tmp;
		///cout << i << endl;
		//show(7, 7);
		//cout << endl;
	}
	int ans = -1;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			if (all[i][j]>0){
				if (ans == -1)
					ans = all[i][j]-1;
				else
					ans = min(ans, all[i][j]-1);
			}
		}
	}
	printf("%d\n", ans);
}

int main(){
	scanf("%d", &n);
	a.clear();
	a.resize(MAX_T);
	last_t = -1;
	for (int i = 0; i < n; ++i){
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		a[t].push_back(P(x, y));
		last_t = max(last_t, t);
	}
	solve();
	return 0;
}
