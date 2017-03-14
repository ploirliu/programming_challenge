#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> all;
int h, w;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

typedef pair<int, int> P;

void solve(){
	int x=-1, y = -1;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			if(all[i][j] == '@'){
				x = j, y = i;
				break;
			}
		}
		if (x != -1) break;
	}
	queue<P> q;
	q.push(P(x, y));
	int ans = 0;
	while (!q.empty()){
		P tmp = q.front(); q.pop();
		x = tmp.first, y = tmp.second;
		++ans;
		for (int i = 0; i < 4; ++i){
			int tmpx = x + dx[i], tmpy = y + dy[i];
			if (0 <= tmpx && tmpx < w && 0 <= tmpy && tmpy < h && all[tmpy][tmpx]=='.'){
				q.push(P(tmpx, tmpy));
				all[tmpy][tmpx] = '#';
			}
		}
	}
	cout << ans << endl;
}

int main(){
	while (cin >> w >> h){
		if (h == 0 && w == 0)
			break;
		all.clear();
		for (int i = 0; i < h; ++i){
			string tmp;
			cin >> tmp;
			all.push_back(tmp);
		}
		solve();
	}
	return 0;
}