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

const int h = 5;
const int w = 5;
int all[h][w];
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };



void dfs(int i, int j,int t,int num, set<int> &s){
	if (t == 0){
		s.insert(num);
		return;
	}
	for (int k = 0; k < 4; ++k){
		int y = i + dy[k], x = j + dx[k];
		if (y >= 0 && y < h && x >= 0 && x < w){
			dfs(y, x, t - 1, num * 10 + all[y][x], s);
		}
	}
}

void solve(){
	set<int> s;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			dfs(i, j, 6, 0, s);
		}
	}
	cout << s.size() << endl;
}

int main(){
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			cin >> all[i][j];
		}
	}
	solve();
	return 0;
}