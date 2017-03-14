#include <iostream>
#include <queue>
using namespace std;

const int MAX_H = 25;
const int MAX_W = 25;

int all[MAX_H][MAX_W];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int h, w;
int ans;
typedef pair<int, int> P;

//void solve(){
//	int ans = -1;
//	int x = -1, y = -1;
//	for (int i = 0; i < h; ++i){
//		for (int j = 0; j < w; ++j){
//			if (all[i][j] == 2){
//				y = i, x = j;
//				break;
//			}
//		}
//		if (y != -1) break;
//	}
//	if (y == -1){
//		cout << -1 << endl;
//		return;
//	}
//	all[y][x] = 0;
//	queue<P> q;
//	queue<int> q2;
//	q.push(P(y, x)); q2.push(0);
//	while (!q.empty()){
//		P p = q.front(); q.pop();
//		int t = q2.front(); q2.pop();
//		if (t >= 10){
//			continue;
//		}
//		y = p.first, x = p.second;
//		//cout << y << " " <<x<< endl;
//		for (int i = 0; i < 4; ++i){
//			int tmpy = y + dy[i], tmpx = x + dx[i];
//			if (0 <= tmpy && tmpy < h && 0 <= tmpx&& tmpx < w && (all[tmpy][tmpx] == 0 || all[tmpy][tmpx] == 3)){
//				while (0 <= tmpy && tmpy < h && 0 <= tmpx&& tmpx < w && all[tmpy][tmpx] == 0){
//					tmpy += dy[i], tmpx += dx[i];
//				}
//				if (0 <= tmpy && tmpy < h && 0 <= tmpx && tmpx < w){
//					if (all[tmpy][tmpx] == 3){
//						cout << t + 1 << endl;
//						return;
//					}
//					else{
//						all[tmpy][tmpx] = 0;
//						q.push(P(tmpy - dy[i], tmpx - dx[i]));
//						q2.push(t + 1);
//					}
//				}
//
//			}
//		}
//	}
//	cout << -1 << endl;
//}

void dfs(int depth, int x, int y){
	if (all[y][x] == 3){
		if (ans == -1)
			ans = depth;
		else
			ans = min(ans, depth);
		return;
	}
	if (depth >= 10)
		return;
	for (int i = 0; i < 4; ++i){
		int tmpy = y + dy[i], tmpx = x + dx[i];
		if (tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h && all[tmpy][tmpx] != 1){
			while (tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h && all[tmpy][tmpx] == 0){
				tmpx += dx[i], tmpy += dy[i];
			}
			if (tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h){
				if (all[tmpy][tmpx] == 3){
					dfs(depth + 1, tmpx, tmpy);
				}
				else if (all[tmpy][tmpx] == 1){
					all[tmpy][tmpx] = 0;
					dfs(depth + 1, tmpx-dx[i], tmpy-dy[i]);
					all[tmpy][tmpx] = 1;
				}
			}
		}
	}
}

void solve(){
	int x = -1, y = -1;
	ans = -1;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			if (all[i][j] == 2){
				all[i][j] = 0;
				y = i, x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1){
		cout << -1 << endl;
		return;
	}
	dfs(0, x, y);
	cout << ans << endl;
}

int main(){
	//freopen("a.out", "w", stdout);
	while(cin >> w >> h){
		if (h == 0 && w == 0)
			break;
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> all[i][j];
			}
		}
		solve();
	}
	return 0;
}